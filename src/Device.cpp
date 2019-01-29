#include <Esp.h>
#include "Logging.h"
#include "Device.h"

void Device::restartDevice() {
  Log::info(F("Restart device now ..."));
  ESP.restart();
}

bool Device::hwButtonPushed(){
  return digitalRead(PIN_SETUP_SWITCH) == LOW;
}