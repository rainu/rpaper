#include "SetupMenu.h"

#include <ESP8266WiFi.h>
#include <Fonts/FreeSerifBoldItalic9pt7b.h>
#include <ESP8266TrueRandom.h>

#include "Config.h"
#include "Logging.h"

void SetupMenu::startAP() {
  if (!this->accessPointStatus) {
#ifdef DEV_MODE
    this->accessPointPassword = "123456789";
#else
    byte uuidNumber[16];
    ESP8266TrueRandom.uuid(uuidNumber);

    this->accessPointPassword = ESP8266TrueRandom.uuidToString(uuidNumber).substring(0, 8);
#endif

    WiFi.softAPConfig(
        IPAddress(ACCESS_POINT_IP),
        IPAddress(ACCESS_POINT_GATEWAY_IP),
        IPAddress(ACCESS_POINT_SUBNET));
    this->accessPointStatus =
        WiFi.softAP(ACCESS_POINT_SSID, this->accessPointPassword.c_str());
  }

  if (this->webServer == NULL) {
    Log::info(F("Starting webserver"));
    this->webServerUrl = "http://" + IPAddress(ACCESS_POINT_IP).toString() + (WEB_SERVER_PORT == 80 ? "" : (":" + WEB_SERVER_PORT));

    this->webServer = new ESP8266WebServer(WEB_SERVER_PORT);
    this->webServer->on("/", HTTP_GET, std::bind(&SetupMenu::handleIndexHtml, this));
    this->webServer->on("/main.css", HTTP_GET, std::bind(&SetupMenu::handleMainCss, this));
    this->webServer->on("/main.js", HTTP_GET, std::bind(&SetupMenu::handleMainJs, this));
    this->webServer->on("/data.js", HTTP_GET, std::bind(&SetupMenu::handleDataJs, this));
    this->webServer->on("/scan.js", HTTP_GET, std::bind(&SetupMenu::handleScanJs, this));
    this->webServer->on("/", HTTP_POST, std::bind(&SetupMenu::handleRootPOST, this));
    this->webServer->begin();
  }
}

void SetupMenu::loop() {
  if (this->statusChanged) {
    this->printStatus();
    this->statusChanged = false;
  }

  this->webServer->handleClient();
}

void SetupMenu::printStatus() {
  this->display->fillScreen(GxEPD_WHITE);
  this->display->setCursor(0, 15);
  this->display->setTextColor(GxEPD_BLACK);
  this->display->setFont(&FreeSerifBoldItalic9pt7b);

  this->display->print("SSID: ");
  this->display->print(ACCESS_POINT_SSID);
  this->display->print("\nPW: ");
  this->display->print(this->accessPointPassword);
  this->display->print("\nServer: ");
  this->display->print(this->webServerUrl);
  this->display->print("\nBattery: ");
  this->display->print(String(ESP.getVcc()));

  this->display->update();
}