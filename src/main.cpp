#include "Display.h"
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
#include "Config.h"
#include "Logging.h"
#include "PersistenceManager.h"
#include "SetupMenu.h"
#include "Listener.h"
#include "Bitmaps.h"
#include "Device.h"

ADC_MODE(USED_ADC_MODE);

GxIO_Class io(SPI, PIN_DISPLAY_CS, PIN_DISPLAY_DC, PIN_DISPLAY_RST);
GxEPD_Class display(io, PIN_DISPLAY_RST, PIN_DISPLAY_BUSY);
PersistenceManager persistence;
SetupMenu *setupMenu;
Listener *listener;

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void setup() {
  pinMode(PIN_SETUP_SWITCH, INPUT_PULLUP);
  Serial.begin(SERIAL_BAUDRATE);

#ifdef DEV_MODE
  while (!Serial) {}
#endif

  delay(1000);
  SPI.setFrequency(SPI_FREQUENCY);
  display.init();

#ifdef INIT_EEPROM
  Log::debug(F("EEPROM INIT MODE! This device is not production ready!"));
  const uint16_t x = display.width() / 2;
  const uint16_t y = display.height() / 2;

  for(int r = display.height() / 2; r >= 1 && r <= display.height(); r -= 3) {
    display.fillCircle(x, y, r,
      r % 2 == 0 ? GxEPD_BLACK : GxEPD_WHITE);
  }
  display.update();
  persistence.reset();
#else
  Log::debug(F("Starting device"));
  PersistendData data = persistence.getData();

  if(data.runMode != RUN_MODE_SETUP && Device::hwButtonPushed()) {
    Log::debug(F("Force setup"));
    data.runMode = RUN_MODE_SETUP;
    persistence.saveData(data);
    Device::restartDevice();
    return;
  }

  display.setRotation(data.displayRotation);
  if (data.runMode == RUN_MODE_SETUP) {
    Log::debug(F("Setup SetupMenu"));
    setupMenu = new SetupMenu(&display, &persistence);
    setupMenu->startAP();
  } else if (data.runMode == RUN_MODE_LISTENING) {
    Log::debug(F("Setup Listener"));
    listener = new Listener(&display, &persistence, &mqttClient);
  }
#endif
}

void loop() {
  PersistendData data = persistence.getData();

#ifndef INIT_EEPROM
  if (data.runMode == RUN_MODE_SETUP) {
    setupMenu->loop();
  } else if (data.runMode == RUN_MODE_LISTENING) {
    listener->loop();
  }
#endif
  delay(500);
}
 