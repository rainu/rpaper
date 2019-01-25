#ifndef _PERSISTENCEMANAGER_H_
#define _PERSISTENCEMANAGER_H_

#include <stdint.h>
#include "Config.h"

#define RUN_MODE_SETUP        0
#define RUN_MODE_LISTENING    1

struct PersistendData {
  uint8_t displayRotation;
  uint8_t runMode;

  struct Wifi {
    char ssid[WIFI_SSID_MAX_LENGTH];
    char username[WIFI_USERNAME_MAX_LENGTH];
    char password[WIFI_PASSWORD_MAX_LENGTH];
  } wifi;

  struct Mqtt {
    char host[MQTT_HOSTNAME_MAX_LENGTH];
    uint16_t port;
    char clientId[MQTT_CLIENT_MAX_LENGTH];
    char username[MQTT_USERNAME_MAX_LENGTH];
    char password[MQTT_PASSWORD_MAX_LENGTH];
    char subcribeTopic[MQTT_TOPIC_MAX_LENGTH];
    char stateTopic[MQTT_TOPIC_MAX_LENGTH];
  } mqtt;
};

class PersistenceManager {
 public:
  PersistenceManager();

  void reset();
  void saveData(PersistendData data);
  PersistendData getData();
};


#endif /* _PERSISTENCEMANAGER_H_ */
