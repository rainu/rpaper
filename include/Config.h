#ifndef _CONFIG_H_
#define _CONFIG_H_

//outcomment this for development mode
#define DEV_MODE

//outcomment this if you want to flash the default EEPROM-Values
//#define INIT_EEPROM

/**
 * General settings
 */

#define SERIAL_BAUDRATE         9600                //The baudrate for serial port
#define SPI_FREQUENCY           8000000L
#define USED_ADC_MODE           ADC_VCC

/**
 * EEPROM
 */
#define DEFAULT_DISPLAY_ROTATION        2           //values from 1-4 are possible
#define WIFI_SSID_MAX_LENGTH            32
#define WIFI_USERNAME_MAX_LENGTH        64
#define WIFI_PASSWORD_MAX_LENGTH        64
#define MQTT_HOSTNAME_MAX_LENGTH        256
#define MQTT_TOPIC_MAX_LENGTH           256
#define MQTT_CLIENT_MAX_LENGTH          64
#define MQTT_USERNAME_MAX_LENGTH        64
#define MQTT_PASSWORD_MAX_LENGTH        64
#define MQTT_DEFAULT_STATE_TOPIC        "state"

/**
 * Listener
 */
#define WIFI_CONNECTION_WAIT_INTERVAL   500
#define MQTT_CONNECTION_RETRY           5000

/**
 * Setup Menu
 */
#define ACCESS_POINT_SSID       "ePaper_AP"
#define ACCESS_POINT_IP         192, 168, 4, 1      //192.168.4.1
#define ACCESS_POINT_GATEWAY_IP 192, 168, 4, 1      //192.168.4.1
#define ACCESS_POINT_SUBNET     255, 255, 255, 0    //255.255.255.0
#define WEB_SERVER_PORT         80

/**
 * PIN SETUP
 */
#define PIN_DISPLAY_CS          D1
#define PIN_DISPLAY_DC          D3
#define PIN_DISPLAY_RST         D4
#define PIN_DISPLAY_BUSY        -1

/**
 * LOGGING
 */

#define LOG_LEVEL_DEBUG         0
#define LOG_LEVEL_INFO          1
#define LOG_LEVEL_WARN          2
#define LOG_LEVEL_ERROR         3
#define LOG_LEVEL_NONE          10
#define LOG_LEVEL               LOG_LEVEL_DEBUG     //the used log level

/**
 * Font Matrix. (comment unwanted font combinations out)
 * More fonts => more program space
 * Less fonts => less program space
 */
#ifndef DEV_MODE      //in dev mode we support only one to speedup compile- and flash- time
  #define FONT_MONO_9
  #define FONT_MONO_12
  #define FONT_MONO_18
  #define FONT_MONO_24

  #define FONT_MONO_BOLD_9
  #define FONT_MONO_BOLD_12
  #define FONT_MONO_BOLD_18
  #define FONT_MONO_BOLD_24

  #define FONT_MONO_OBLIQUE_9
  #define FONT_MONO_OBLIQUE_12
  #define FONT_MONO_OBLIQUE_18
  #define FONT_MONO_OBLIQUE_24

  #define FONT_MONO_BOLD_OBLIQUE_9
  #define FONT_MONO_BOLD_OBLIQUE_12
  #define FONT_MONO_BOLD_OBLIQUE_18
  #define FONT_MONO_BOLD_OBLIQUE_24

  #define FONT_SANS_9
  #define FONT_SANS_12
  #define FONT_SANS_18
  #define FONT_SANS_24

  #define FONT_SANS_BOLD_9
  #define FONT_SANS_BOLD_12
  #define FONT_SANS_BOLD_18
  #define FONT_SANS_BOLD_24

  #define FONT_SANS_OBLIQUE_9
  #define FONT_SANS_OBLIQUE_12
  #define FONT_SANS_OBLIQUE_18
  #define FONT_SANS_OBLIQUE_24

  #define FONT_SANS_BOLD_OBLIQUE_9
  #define FONT_SANS_BOLD_OBLIQUE_12
  #define FONT_SANS_BOLD_OBLIQUE_18
  #define FONT_SANS_BOLD_OBLIQUE_24

  #define FONT_SERIF_12
  #define FONT_SERIF_18
  #define FONT_SERIF_24

  #define FONT_SERIF_BOLD_9
  #define FONT_SERIF_BOLD_12
  #define FONT_SERIF_BOLD_18
  #define FONT_SERIF_BOLD_24

  #define FONT_SERIF_ITALIC_9
  #define FONT_SERIF_ITALIC_12
  #define FONT_SERIF_ITALIC_18
  #define FONT_SERIF_ITALIC_24

  #define FONT_SERIF_BOLD_ITALIC_9
  #define FONT_SERIF_BOLD_ITALIC_12
  #define FONT_SERIF_BOLD_ITALIC_18
  #define FONT_SERIF_BOLD_ITALIC_24
#endif

#endif /* _CONFIG_H_ */
