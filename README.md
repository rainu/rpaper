# State
work in progress

# MQTT Topics

This device can only consume 1024Bytes of mqtt messages. So make sure the messages
are minified and the topic names small than possible.

If you need to support bigger messages, you have to change the **MQTT_MAX_PACKET_SIZE** setting
inside the **platformio.ini**

## text tile

This messages will trigger printing text to display pane. You have to provide
the following message format:
```json5
{
    "t": {  //infomation about tile
        "c": 0,   //the class of tile (0 => text; 1 => bitmap)
        "i": 0,   //the current tile id (must be a uniq integer)
        "b": 1,   //the background color of this tile (0 => black; 1 => white)
        "t": 1    //total count of tiles
    },
    "p": {  //information about cursor position
        "x": 0,   // cursor position x
        "y": 24   // cursor position y
    },
    "c": {  //information about content
      "s": 24,    //font size. possible values: [9, 12, 18, 24]
      "b": 1,     //bold? 1 => yes; 0 => no
      "i": 0,     //italic? 1 => yes; 0 => no
      "f": 0,     //font: 0 => "sans"; 1 => "mono"; 2 => "serif"
      "c": 0,     //the text color (0 => black; 1 => white)
      "t": "text" //the text to print
    }
}
```

## bitmap tile

This messages will trigger printing bitmap to display pane. You have to provide
the following message format:
```json5
{
    "t": {  //infomation about tile
        "c": 1,   //the class of tile (0 => text; 1 => bitmap)
        "i": 0,   //the current tile id (must be a uniq integer)
        "b": 1,   //the background color of this tile (0 => black; 1 => white)
        "t": 1    //total count of tiles
    },
    "p": {  //information about cursor position
        "x": 0,   // cursor position x
        "y": 24   // cursor position y
    },
    "c": {  //information about content
      //class specific content
      "w": 24,    //the width of the bitmap
      "h": 1,     //the hight of the bitmap
      "c": 0,     //the color for each set bit (0 => black; 1 => white)
      "b": "base64==" //the bitmap (base64 encoded)
    }
}
```

# construction manual
This program was primary build for the following hardware setup:
1. NodeMCU ESP8266 ESP-12E
1. Waveshare 1.54 Inch E-Paper Display Panel Module
1. push-button switch
1. 18650 Akku (3,6V)

![construction plan](/doc/rpaper_layout.png)

# HowTo flash

First off all you have to flash the init EEPROM state:
```bash
platformio run -e nodemcuv2-init -t upload
```
Let starts the device and wait some seconds. After that you can flash the real software
```bash
platformio run -e nodemcuv2-prod -t upload
```

# HowTo use

After flashing the init state and real software, the device will automatically boot in the "setup"-mode.
In this mode the device opens an access-point (AP) and shows you the connection details on the display.
Connect to this AP, open a browser and call the displayed server. Now you have to setup the shown details
such like the WLAN-AccessPoint to connect and MQTT-Settings. After saving and rebooting, the device
switch to the "listening"-mode. It will connect to the configured AP and MQTT-Broker and waits for
messages. 

If you want to reconfigure the device you have to do the following:
1. turn off the device
1. press and hold the push-button
1. turn on the device
1. after a few seconds the device should restart into the setup mode
  1. if not restart the device manually (power off; power on)

# HowTo debug

## Decode Exceptions

1. Copy the whole stack trace in a file. For example "stack.txt" :
```
Exception (28):
epc1=0x4020b89f epc2=0x00000000 epc3=0x00000000 excvaddr=0x00000030 depc=0x00000000

ctx: cont 
sp: 3ffffa10 end: 3fffffd0 offset: 01a0

>>>stack>>>
3ffffbb0:  3fffdad0 00000000 3ffffc20 3fff0544
....
3fffffc0:  feefeffe feefeffe 3ffe85e0 40100721  
<<<stack<<<
```

Now exceptions can be encoded via the following command:
```bash
./esp_decoder.py -p ESP8266 -e ./.pioenvs/nodemcuv2/firmware.elf
```