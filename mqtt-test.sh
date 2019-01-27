#!/bin/bash

MQTT_EMQX_HOST="localhost"
MQTT_EMQX_USER="admin"
MQTT_EMQX_PASSWORD="public"
MQTT_EMQX_PORT=18083
MQTT_ROOT_TOPIC="epaper"

read -r -d '' BITMAP << EOM
0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xf3, 0xff, 0xe7, 0xff, 0xcf
0xbf, 0x9f, 0x9f, 0x3f, 0x9e, 0x7f, 0xcc, 0xff, 0xe1, 0xff, 0xe7, 0xff, 0xff, 0xff, 0x7f, 0xfe
EOM
BITMAP=$(echo ${BITMAP} | sed 's/,//g' | sed 's/0x//g' | sed 's/ //g' | xxd -r -p | base64 -w 0)

read -r -d '' MESSAGE_TEXT_0 << EOM
{
    "t": {
        "c": 0,
        "b": 1,
        "i": 0,
        "t": 2
    },
    "p": {
        "x": 0,
        "y": 0
    },
    "c": {
      "s": 9,
      "c": 0,
      "i": 1,
      "f": 1,
      "t": "Hello World"
    }
}
EOM

read -r -d '' MESSAGE_BITMAP_0 << EOM
{
    "t": {
        "c": 1,
        "b": 1,
        "i": 1,
        "t": 2
    },
    "p": {
        "x": 50,
        "y": 50
    },
    "c": {
      "w": 16,
      "h": 16,
      "c": 0,
      "b": "${BITMAP}"
    }
}
EOM


# publish a message
# 1: topic
# 2: message
function sendMessage() {
  read -r -d '' CURL_BODY << EOM
  {
    "topic" : "__TOPIC__",
    "payload": "__PAYLOAD__",
    "qos": 1,
    "retain" : true,
    "client_id": "bash-test-client"
  }
EOM
  ESCAPED_MESSAGE=$(echo ${2} | sed 's/"/\\\\"/g')
  CURL_BODY=$(echo ${CURL_BODY} | sed "s|__TOPIC__|${1}|g" | sed "s|__PAYLOAD__|${ESCAPED_MESSAGE}|g" )

  echo ${CURL_BODY} | curl -q -u "${MQTT_EMQX_USER}:${MQTT_EMQX_PASSWORD}" -H "Content-Type: application/json" -X POST http://${MQTT_EMQX_HOST}:${MQTT_EMQX_PORT}/api/v3/mqtt/publish -d @-
}

function clearTopics() {
  for i in $(seq 1 10); do
    sendMessage "${MQTT_ROOT_TOPIC}/${i}" "" > /dev/null
  done
}

###
# MAIN

clearTopics
sendMessage "${MQTT_ROOT_TOPIC}/0" "${MESSAGE_TEXT_0}"
sendMessage "${MQTT_ROOT_TOPIC}/1" "${MESSAGE_BITMAP_0}"
