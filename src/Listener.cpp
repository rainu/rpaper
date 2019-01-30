#include "Listener.h"
#include "Logging.h"
#include <ESP8266WiFi.h>
#include "Bitmaps.h"
#include "Fonts.h"

Listener::Listener(GxEPD_Class *_display,
                   PersistenceManager *_persistence,
                   PubSubClient *_mqttClient)
    : display(_display),
      persistence(_persistence),
      mqttClient(_mqttClient) {

  PersistendData data = this->persistence->getData();
  this->mqttClient->setCallback(std::bind(&Listener::handleMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

  IPAddress addr;
  if (addr.fromString(data.mqtt.host)) {
    this->mqttClient->setServer(addr, data.mqtt.port);
  } else {
    this->mqttClient->setServer(data.mqtt.host, data.mqtt.port);
  }

  Log::debug("MQTT-Target: " + String(data.mqtt.host) + ":" + String(data.mqtt.port));

  //initialise display
  this->panelStartX = 0;
  this->panelStartY = this->display->height() - BITMAP_HEIGHT;
  this->batteryStartX = this->panelStartX;
  this->wifiStartX = this->panelStartX + BITMAP_WIDTH;
  this->mqttStartX = this->display->width() - BITMAP_WIDTH;
  this->display->setFont(&FreeSerif9pt7b);
  this->display->setTextColor(GxEPD_BLACK);

  this->drawWifiState(false, false);
  this->drawBatteryState(L4, false);
  this->drawMqttState(false, false);
  this->display->update();
}

/*
 * We have space for icons in the buttom panel.
 * The panel is 32px high and <displayWidth> wide.
 *
 * +-----------------------+
 * | B | W | IP |      | M |
 * +-----------------------+
 * B -> Battery
 * W -> Wifi
 * IP -> Ip address
 * M -> mqtt
 */

void Listener::drawWifiState(bool connected, bool refresh) {
  this->display->fillRect(
      this->wifiStartX, this->panelStartY,
      BITMAP_WIDTH, BITMAP_HEIGHT,
      GxEPD_BLACK);
  this->display->drawBitmap(
      this->wifiStartX, this->panelStartY,
      connected ? BITMAP_WIFI_CONNECTED : BITMAP_WIFI_DISCONNECTED,
      BITMAP_WIDTH, BITMAP_HEIGHT,
      GxEPD_WHITE);

  if(connected) {
    this->display->setCursor(this->wifiStartX + BITMAP_WIDTH, this->panelStartY);
    String ip = WiFi.localIP().toString();

    if(ip.length() <= 13 || this->display->width() > 225) {
      this->display->setCursor(this->wifiStartX + BITMAP_WIDTH, this->display->height() - 12);
      this->display->print(ip);
    } else {
      this->display->setCursor(this->wifiStartX + BITMAP_WIDTH, this->display->height() - 18);
      char dotCount = 0;
      for(unsigned int i=0; i < ip.length(); i++) {
        this->display->print(ip.charAt(i));
        if(ip.charAt(i) == '.') {
          dotCount++;

          if(dotCount == 2) {
            this->display->setCursor(this->wifiStartX + BITMAP_WIDTH, this->display->height() - 2);
          }
        }
      }
    }
  }

  if(refresh) {
    this->display->update();
  }
}

void Listener::drawBatteryState(BatteryLevel level, bool refresh) {
  this->display->fillRect(
      this->batteryStartX, this->panelStartY,
      BITMAP_WIDTH, BITMAP_HEIGHT,
      GxEPD_BLACK);

  switch(level){
    case L4:
      this->display->drawBitmap(
          this->batteryStartX, this->panelStartY,
          BITMAP_BATTERY_FULL,
          BITMAP_WIDTH, BITMAP_HEIGHT,
          GxEPD_WHITE);
      break;
    case L3:
      this->display->drawBitmap(
          this->batteryStartX, this->panelStartY,
          BITMAP_BATTERY_THREE_QUARTER,
          BITMAP_WIDTH, BITMAP_HEIGHT,
          GxEPD_WHITE);
      break;
    case L2:
      this->display->drawBitmap(
          this->batteryStartX, this->panelStartY,
          BITMAP_BATTER_HALF,
          BITMAP_WIDTH, BITMAP_HEIGHT,
          GxEPD_WHITE);
      break;
    case L1:
      this->display->drawBitmap(
          this->batteryStartX, this->panelStartY,
          BITMAP_BATTERY_QUARTER,
          BITMAP_WIDTH, BITMAP_HEIGHT,
          GxEPD_WHITE);
      break;
    case L0:
    default:
      this->display->drawBitmap(
          this->batteryStartX, this->panelStartY,
          BITMAP_BATTERY_EMPTY,
          BITMAP_WIDTH, BITMAP_HEIGHT,
          GxEPD_WHITE);
      break;
  }

  if(refresh) {
    this->display->update();
  }
}

void Listener::drawMqttState(bool connected, bool refresh) {
  this->display->fillRect(
      this->mqttStartX, this->panelStartY,
      BITMAP_WIDTH, BITMAP_HEIGHT,
      GxEPD_BLACK);
  this->display->drawBitmap(
      this->mqttStartX, this->panelStartY,
      connected ? BITMAP_SERVER_CONNECTED : BITMAP_WIFI_DISCONNECTED,
      BITMAP_WIDTH, BITMAP_HEIGHT,
      GxEPD_WHITE);

  if(refresh) {
    this->display->update();
  }
}

void Listener::connectWifi() {
  PersistendData data = this->persistence->getData();
  Log::info("Connect to wifi...\n\tSSID: " + String(data.wifi.ssid));
  WiFi.softAPdisconnect(true);
  WiFi.setAutoConnect(false);
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(data.wifi.ssid, data.wifi.password);
  while (!WiFi.isConnected()) {
    Serial.print(".");
    delay(WIFI_CONNECTION_WAIT_INTERVAL);
  }
  Serial.println();
  Log::info("LocalIP: " + WiFi.localIP().toString());
}

void Listener::connectMqtt() {
  PersistendData data = this->persistence->getData();

  while (!this->mqttClient->connected()) {
    Log::debug(F("Attempting MQTT connection..."));
    Log::debug(data.mqtt.subcribeTopic);

    if (this->mqttClient->connect(data.mqtt.clientId, data.mqtt.username, data.mqtt.password)) {
      Log::debug(F("connected"));
      this->mqttClient->subscribe(data.mqtt.subcribeTopic);
    } else {
      Log::error(F("Could not connect to mqtt!"));
      Log::error("rc=" + String(this->mqttClient->state()));
      delay(MQTT_CONNECTION_RETRY);
    }
  }
}

void Listener::handleMessage(char *topic, uint8_t *payload, unsigned int length) {
  Log::debug(F("Handle incoming message for Topic: "));

  String sTopic = String(topic);
  Log::debug(sTopic);

  DynamicJsonBuffer jsonBuffer;
  JsonObject& element = jsonBuffer.parseObject(payload);
  if(!element.success()) {
    Log::warn(F("Invalid json format!"));
    return;
  }

  bool isText = element["t"]["c"].as<String>() == "0";
  bool isImage = element["t"]["c"].as<String>() == "1";
  if(!isText && !isImage) {
    Log::warn(F("Unknown tile class!"));
    return;
  }

  this->expectedTotal = element["t"]["t"].as<uint16_t>();
  bool firstTile = this->currentTile == 0;
  uint16_t tileId = element["t"]["i"].as<uint16_t>();

  if(this->tileAlreadyProcessed(tileId)){
    Log::error(F("Skip tile because already drawn."));
    return;
  }
  this->currentTile++;

  if(firstTile) {
    bool useBlack = element["t"]["b"].as<String>() == "0";

    //clear the "painting area"
    if(useBlack) {
      this->display->fillRect(
          0, 0,
          this->display->width(), this->display->height() - BITMAP_HEIGHT,
          GxEPD_BLACK);
    }else{
      this->display->fillRect(
          0, 0,
          this->display->width(), this->display->height() - BITMAP_HEIGHT,
          GxEPD_WHITE);
    }
  }

  if (isText) {
    this->handleText(element);
  } else if (isImage) {
    this->handleImage(element);
  }

  if(this->allTilesProcessed()){
    Log::debug(F("All tiles received. Update screen."));

    this->display->update();
    this->currentTile = 0;
    this->expectedTotal = 0;
  }
}

bool Listener::allTilesProcessed() {
  return this->expectedTotal == this->currentTile;
}

bool Listener::tileAlreadyProcessed(uint16_t tileIndex) {
//  for (int i = 0; i < this->drawn->size(); i++) {
//    if(tileIndex == this->drawn->get(i)) {
//      return true;
//    }
//  }

  return false;
}

const uint16_t BATTERY_DELTA = BATTERY_MAX_VOLTAGE - BATTERY_MIN_VOLTAGE;
uint8_t Listener::getBatteryPercent() {
  uint16_t currentDelta = BATTERY_MAX_VOLTAGE - ESP.getVcc();
  uint8_t batteryPercentage = currentDelta * 100 / BATTERY_DELTA;
  return batteryPercentage;
}

BatteryLevel Listener::getBatteryLevel() {
  uint8_t batteryPercentage = this->getBatteryPercent();

  if(batteryPercentage > 90) {
    return L4;
  }

  if(batteryPercentage > 50) {
    return L3;
  }

  if(batteryPercentage > 30) {
    return L2;
  }

  if(batteryPercentage > 10) {
    return L1;
  }

  return L0;
}

void Listener::publishDeviceState() {
  PersistendData data = this->persistence->getData();

  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  JsonObject& state = root.createNestedObject("s");
  JsonObject& stateWifi = state.createNestedObject("w");
  stateWifi["i"] = WiFi.localIP().toString();
  stateWifi["m"] = WiFi.macAddress();
  stateWifi["g"] = WiFi.gatewayIP().toString();
  stateWifi["s"] = WiFi.RSSI();
  stateWifi["b"] = WiFi.BSSIDstr();

  JsonObject& battery = state.createNestedObject("b");
  battery["p"] = this->getBatteryPercent();
  switch(this->getBatteryLevel()){
    case L0:  battery["l"] = "L0"; break;
    case L1:  battery["l"] = "L1"; break;
    case L2:  battery["l"] = "L2"; break;
    case L3:  battery["l"] = "L3"; break;
    case L4:  battery["l"] = "L4"; break;
  }
  battery["v"] = ESP.getVcc();

  JsonObject& config = root.createNestedObject("c");
  JsonObject& configWifi = config.createNestedObject("w");
  configWifi["s"] = data.wifi.ssid;
  configWifi["u"] = data.wifi.username;

  if(PUBLISH_WIFI_PASSWORD){
    configWifi["p"] = data.wifi.password;
  }

  JsonObject& configMqtt = config.createNestedObject("m");
  configMqtt["h"] = data.mqtt.host;
  configMqtt["p"] = data.mqtt.port;
  configMqtt["c"] = data.mqtt.clientId;
  configMqtt["u"] = data.mqtt.username;

  if(PUBLISH_MQTT_PASSWORD){
    configMqtt["s"] = data.mqtt.password;
  }

  JsonObject& configMqttTopic = configMqtt.createNestedObject("t");
  configMqttTopic["s"] = data.mqtt.subcribeTopic;
  configMqttTopic["p"] = data.mqtt.stateTopic;

  String result;
  root.printTo(result);

  this->mqttClient->publish(data.mqtt.stateTopic, result.c_str());
}

void Listener::loop() {
  bool justRefreshed = false;
  if (!WiFi.isConnected()) {
    this->drawWifiState(false, true);
    this->connectWifi();
    this->drawWifiState(true, true);
    justRefreshed = true;
  }
  if (!this->mqttClient->connected()) {
    this->drawMqttState(false, !justRefreshed);
    this->connectMqtt();
    this->drawMqttState(true, true);
  }

  this->mqttClient->loop();
  this->publishDeviceState();
  this->drawBatteryState(this->getBatteryLevel(), true);
}