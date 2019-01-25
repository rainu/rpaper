#include "Listener.h"
#include "Logging.h"
#include "Bitmaps.h"

void Listener::handleImage(JsonObject& payload) {
  int16_t positionX;
  int16_t positionY;
  int16_t width;
  int16_t height;
  uint8_t *bitmap;

  if(height > this->display->height() - BITMAP_WIDTH) {
    Log::error(F("Image is higher than available space!"));
    return;
  }

  if(width > this->display->width()) {
    Log::error(F("Image is wider than available space!"));
    return;
  }

  this->display->drawBitmap(
      positionX, positionY,
      bitmap,
      width, height,
      GxEPD_BLACK);
}