
# MQTT Topics

This device can only consume 1024 Bytes of mqtt messages. So make sure the messages
are minified and the topic names small than possible.

If you need to support bigger messages, you have to change the **MQTT_MAX_PACKET_SIZE** setting
inside the **platformio.ini**

## &lt;topic&gt;/text

This messages will trigger printing text to display pane. You have to provide
the following message format:
```json
[{
    "c": {
        "x": 0,   // cursor position x
        "y": 24   // cursor position y
    },
    "s": {
        "s": 24,  //font size. possible values: [9, 12, 18, 24]
        "b": 1,   //bold? 1 => yes; 0 => no
        "i": 0,   //italic? 1 => yes; 0 => no
        "f": 0    //font: 0 => "sans"; 1 => "mono"; 2 => "serif"
    },
    "t": "text"   //the text to print
}]
```

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