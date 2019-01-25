#include "PersistenceManager.h"
#include "Config.h"
#include <EEPROM.h>
#include <ESP8266WebServer.h>

PersistendData _data;

PersistenceManager::PersistenceManager() {
  EEPROM.begin(sizeof(PersistendData));

  EEPROM.get(0, _data);
}

void PersistenceManager::reset() {
  PersistendData initData;
  initData.displayRotation = DEFAULT_DISPLAY_ROTATION;
  initData.runMode = RUN_MODE_SETUP;
  memset(initData.wifi.ssid, 0, sizeof(initData.wifi.ssid));
  memset(initData.wifi.username, 0, sizeof(initData.wifi.username));
  memset(initData.wifi.password, 0, sizeof(initData.wifi.password));

  initData.mqtt.port = 1883;
  memset(initData.mqtt.host, 0, sizeof(initData.mqtt.host));
  memset(initData.mqtt.clientId, 0, sizeof(initData.mqtt.clientId));
  memset(initData.mqtt.username, 0, sizeof(initData.mqtt.username));
  memset(initData.mqtt.password, 0, sizeof(initData.mqtt.password));
  memset(initData.mqtt.subcribeTopic, 0, sizeof(initData.mqtt.subcribeTopic));
  memset(initData.mqtt.stateTopic, 0, sizeof(initData.mqtt.stateTopic));
  strcpy(initData.mqtt.stateTopic, MQTT_DEFAULT_STATE_TOPIC);

  this->saveData(initData);
}

void PersistenceManager::saveData(PersistendData data) {
  _data = data;
  EEPROM.put(0, data);
  EEPROM.commit();
}

PersistendData PersistenceManager::getData() {
  return _data;
}
