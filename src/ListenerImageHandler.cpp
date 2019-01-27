#include "Listener.h"
#include "Logging.h"
#include "Bitmaps.h"
#include <Base64.h>

const uint8_t * extractBitmap(JsonObject& payload){
  String b64Bitmap = payload["c"]["b"].as<const char*>();

  int decodedLength = base64_dec_len(strdup(b64Bitmap.c_str()), b64Bitmap.length());
  char rawBitmap[decodedLength];
  base64_decode(rawBitmap, strdup(b64Bitmap.c_str()), b64Bitmap.length());

  return (const uint8_t*) rawBitmap;
}

void Listener::handleImage(JsonObject& payload) {
  int16_t positionX = payload["p"]["x"].as<int16_t>();
  int16_t positionY = payload["p"]["y"].as<int16_t>();
  int16_t width = payload["c"]["w"].as<int16_t>();
  int16_t height = payload["c"]["h"].as<int16_t>();
  bool useBlack = payload["c"]["c"].as<String>() == "0";

  if(height > this->display->height() - BITMAP_WIDTH) {
    Log::error(F("Image is higher than available space!"));
    return;
  }

  if(width > this->display->width()) {
    Log::error(F("Image is wider than available space!"));
    return;
  }

  const uint8_t* rawBitmap = extractBitmap(payload);

  int16_t byteWidth = (width + 7) / 8; // Bitmap scanline pad = whole byte
  uint8_t byte = 0;

  for(int16_t j=0; j<height; j++, positionY++) {
    for(int16_t i=0; i<width; i++) {
      if(i & 7) byte <<= 1;
      else      byte   = (uint8_t)rawBitmap[j * byteWidth + i / 8];
      if(byte & 0x80) this->display->drawPixel(positionX+i, positionY, GxEPD_BLACK);
    }
  }
}
