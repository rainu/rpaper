#include "Listener.h"
#include "Logging.h"
#include "Fonts.h"

void Listener::handleText(JsonObject& payload) {
  int16_t cursorX = payload["c"]["x"].as<int16_t>();
  int16_t cursorY = payload["c"]["y"].as<int16_t>();
  uint8_t textSize = 1;

  bool bold = payload["s"]["b"].as<String>() == "1";
  bool italic = payload["s"]["i"].as<String>() == "1";
  uint8_t size = payload["s"]["s"].as<uint8_t>();
  const GFXfont *font = &FreeSerif9pt7b; //default font
  uint8_t yAdvance = FreeSerif9pt7b.yAdvance;
  
  if (payload["s"]["f"].as<String>() == "0") {
    font = &FreeSerif9pt7b; yAdvance = FreeSerif9pt7b.yAdvance;

    if (bold && italic) {
      switch (size) {
#ifdef FONT_SERIF_BOLD_ITALIC_12
        case 12: font = &FreeSerifBoldItalic12pt7b; yAdvance = FreeSerifBoldItalic12pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_ITALIC_18
        case 18: font = &FreeSerifBoldItalic18pt7b; yAdvance = FreeSerifBoldItalic18pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_ITALIC_24
        case 24: font = &FreeSerifBoldItalic24pt7b; yAdvance = FreeSerifBoldItalic24pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_ITALIC_9
        case 9:
        default: font = &FreeSerifBoldItalic9pt7b; yAdvance = FreeSerifBoldItalic9pt7b.yAdvance; break;
#endif
      }
    } else if (bold) {
      switch (size) {
#ifdef FONT_SERIF_BOLD_12
        case 12: font = &FreeSerifBold12pt7b; yAdvance = FreeSerifBold12pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_18
        case 18: font = &FreeSerifBold18pt7b; yAdvance = FreeSerifBold18pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_24
        case 24: font = &FreeSerifBold24pt7b; yAdvance = FreeSerifBold24pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_BOLD_9
        case 9:
        default: font = &FreeSerifBold9pt7b; yAdvance = FreeSerifBold9pt7b.yAdvance; break;
#endif
      }
    } else if (italic) {
      switch (size) {
#ifdef FONT_SERIF_BOLD_ITALIC_12
        case 12: font = &FreeSerifItalic12pt7b; yAdvance = FreeSerifItalic12pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_ITALIC_18
        case 18: font = &FreeSerifItalic18pt7b; yAdvance = FreeSerifItalic18pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_ITALIC_24
        case 24: font = &FreeSerifItalic24pt7b; yAdvance = FreeSerifItalic24pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_ITALIC_9
        case 9:
        default: font = &FreeSerifItalic9pt7b; yAdvance = FreeSerifItalic9pt7b.yAdvance; break;
#endif
      }
    } else {
      switch (size) {
#ifdef FONT_SERIF_12
        case 12: font = &FreeSerif12pt7b; yAdvance = FreeSerif12pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_18
        case 18: font = &FreeSerif18pt7b; yAdvance = FreeSerif18pt7b.yAdvance; break;
#endif
#ifdef FONT_SERIF_24
        case 24: font = &FreeSerif24pt7b; yAdvance = FreeSerif24pt7b.yAdvance; break;
#endif
        case 9:
        default:
          font = &FreeSerif9pt7b; yAdvance = FreeSerif9pt7b.yAdvance; break;
      }
    }
  } else if (payload["s"]["f"].as<String>() == "1") {
#ifdef FONT_MONO_9
    font = &FreeMono9pt7b; yAdvance = FreeMono9pt7b.yAdvance;
#endif

    if (bold && italic) {
      switch (size) {
#ifdef FONT_MONO_BOLD_OBLIQUE_12
        case 12: font = &FreeMonoBoldOblique12pt7b; yAdvance = FreeMonoBoldOblique12pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_OBLIQUE_18
        case 18: font = &FreeMonoBoldOblique18pt7b; yAdvance = FreeMonoBoldOblique18pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_OBLIQUE_24
        case 24: font = &FreeMonoBoldOblique24pt7b; yAdvance = FreeMonoBoldOblique24pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_OBLIQUE_9
        case 9:
        default: font = &FreeMonoBoldOblique9pt7b; yAdvance = FreeMonoBoldOblique9pt7b.yAdvance; break;
#endif
      }
    } else if (bold) {
      switch (size) {
#ifdef FONT_MONO_BOLD_12
        case 12: font = &FreeMonoBold12pt7b; yAdvance = FreeMonoBold12pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_18
        case 18: font = &FreeMonoBold18pt7b; yAdvance = FreeMonoBold18pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_24
        case 24: font = &FreeMonoBold24pt7b; yAdvance = FreeMonoBold24pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_BOLD_9
        case 9:
        default: font = &FreeMonoBold9pt7b; yAdvance = FreeMonoBold9pt7b.yAdvance; break;
#endif
      }
    } else if (italic) {
      switch (size) {
#ifdef FONT_MONO_OBLIQUE_12
        case 12: font = &FreeMonoOblique12pt7b; yAdvance = FreeMonoOblique12pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_OBLIQUE_18
        case 18: font = &FreeMonoOblique18pt7b; yAdvance = FreeMonoOblique18pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_OBLIQUE_24
        case 24: font = &FreeMonoOblique24pt7b; yAdvance = FreeMonoOblique24pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_OBLIQUE_9
        case 9:
        default: font = &FreeMonoOblique9pt7b; yAdvance = FreeMonoOblique9pt7b.yAdvance; break;
#endif
      }
    } else {
      switch (size) {
#ifdef FONT_MONO_12
        case 12: font = &FreeMono12pt7b; yAdvance = FreeMono12pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_18
        case 18: font = &FreeMono18pt7b; yAdvance = FreeMono18pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_24
        case 24: font = &FreeMono24pt7b; yAdvance = FreeMono24pt7b.yAdvance; break;
#endif
#ifdef FONT_MONO_9
        case 9:
        default: font = &FreeMono9pt7b; yAdvance = FreeMono9pt7b.yAdvance; break;
#endif
      }
    }
  } else if (payload["s"]["f"].as<String>() == "2") {
#ifdef FONT_SANS_9
    font = &FreeSans9pt7b; yAdvance = FreeSans9pt7b.yAdvance;
#endif

    if (bold && italic) {
      switch (size) {
#ifdef FONT_SANS_BOLD_OBLIQUE_12
        case 12: font = &FreeSansBoldOblique12pt7b; yAdvance = FreeSansBoldOblique12pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_OBLIQUE_18
        case 18: font = &FreeSansBoldOblique18pt7b; yAdvance = FreeSansBoldOblique18pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_OBLIQUE_24
        case 24: font = &FreeSansBoldOblique24pt7b; yAdvance = FreeSansBoldOblique24pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_OBLIQUE_9
        case 9:
        default: font = &FreeSansBoldOblique9pt7b; yAdvance = FreeSansBoldOblique9pt7b.yAdvance; break;
#endif
      }
    } else if (bold) {
      switch (size) {
#ifdef FONT_SANS_BOLD_12
        case 12: font = &FreeSansBold12pt7b; yAdvance = FreeSansBold12pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_18
        case 18: font = &FreeSansBold18pt7b; yAdvance = FreeSansBold18pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_24
        case 24: font = &FreeSansBold24pt7b; yAdvance = FreeSansBold24pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_BOLD_9
        case 9:
        default: font = &FreeSansBold9pt7b; yAdvance = FreeSansBold9pt7b.yAdvance; break;
#endif
      }
    } else if (italic) {
      switch (size) {
#ifdef FONT_SANS_OBLIQUE_12
        case 12: font = &FreeSansOblique12pt7b; yAdvance = FreeSansOblique12pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_OBLIQUE_18
        case 18: font = &FreeSansOblique18pt7b; yAdvance = FreeSansOblique18pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_OBLIQUE_24
        case 24: font = &FreeSansOblique24pt7b; yAdvance = FreeSansOblique24pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_OBLIQUE_9
        case 9:
        default: font = &FreeSansOblique9pt7b; yAdvance = FreeSansOblique9pt7b.yAdvance; break;
#endif
      }
    } else {
      switch (size) {
#ifdef FONT_SANS_12
        case 12: font = &FreeSans12pt7b; yAdvance = FreeSans12pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_18
        case 18: font = &FreeSans18pt7b; yAdvance = FreeSans18pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_24
        case 24: font = &FreeSans24pt7b; yAdvance = FreeSans24pt7b.yAdvance; break;
#endif
#ifdef FONT_SANS_9
        case 9:
        default: font = &FreeSans9pt7b; yAdvance = FreeSans9pt7b.yAdvance; break;
#endif
      }
    }
  }

  String text = payload["t"].as<String>();

  this->display->setCursor(cursorX, cursorY + yAdvance);
  this->display->setTextSize(textSize);
  this->display->setFont(font);
  this->display->print(text);
}
