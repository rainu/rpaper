#ifndef _SETUP_MENU_H_
#define _SETUP_MENU_H_

#include "Display.h"
#include <ESP8266WebServer.h>
#include "PersistenceManager.h"

class SetupMenu {
 public:
  SetupMenu(GxEPD_Class *_display, PersistenceManager *_persistence)
      : display(_display), persistence(_persistence) {}

  void startAP();
  void loop();
  void printStatus();
 private:
  void handleMainCss();
  void handleMainJs();
  void handleDataJs();
  void handleScanJs();
  void handleIndexHtml();
  void handleRootPOST();

  bool statusChanged = true;
  bool accessPointStatus = false;
  ESP8266WebServer *webServer;
  String webServerUrl;

  String accessPointPassword;
  GxEPD_Class *display;
  PersistenceManager *persistence;
};

#endif