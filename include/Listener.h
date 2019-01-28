#ifndef _LISTENER_H_
#define _LISTENER_H_

#include "Display.h"
#include "PersistenceManager.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

typedef enum BatteryLevel {
  L0, L1, L2, L3, L4
};

class Listener {
 public:
  Listener(GxEPD_Class *_display,
           PersistenceManager *_persistence,
           PubSubClient *_mqttClient);

  void loop();
  void connectWifi();
  void connectMqtt();
 private:
  void handleMessage(char *topic, uint8_t *payload, unsigned int length);
  void handleText(JsonObject& payload);
  void handleImage(JsonObject& payload);

  void publishDeviceState();

  void drawWifiState(bool connected, bool refresh);
  void drawBatteryState(BatteryLevel level, bool refresh);
  void drawMqttState(bool connected, bool refresh);

  BatteryLevel getBatteryLevel();
  bool allTilesProcessed();
  bool tileAlreadyProcessed(uint16_t tileIndex);

  uint16_t currentTile = 0;
  uint16_t expectedTotal = 0;

  int16_t panelStartX;
  int16_t panelStartY;
  int16_t batteryStartX;
  int16_t wifiStartX;
  int16_t mqttStartX;

  GxEPD_Class *display;
  PersistenceManager *persistence;
  PubSubClient *mqttClient;
};

#endif //_LISTENER_H_