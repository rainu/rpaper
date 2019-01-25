#include "SetupMenu.h"
#include "Logging.h"

const String KEY_DISPLAY_ROTATION = "displayRotation";
const String KEY_WIFI_SSID = "wifi_ssid";
const String KEY_WIFI_USERNAME = "wifi_username";
const String KEY_WIFI_PASSWORD = "wifi_password";
const String KEY_MQTT_HOST = "mqtt_host";
const String KEY_MQTT_PORT = "mqtt_port";
const String KEY_MQTT_CLIENT_ID = "mqtt_client_id";
const String KEY_MQTT_USERNAME = "mqtt_username";
const String KEY_MQTT_PASSWORD = "mqtt_password";
const String KEY_MQTT_SUBSCRIBE_TOPIC = "mqtt_topic_subscribe";
const String KEY_MQTT_STATE_TOPIC = "mqtt_topic_state";

void SetupMenu::handleMainCss() {
  Log::debug(F("Handle incoming request: /main.css"));
  this->webServer->send(200, F("text/css"), F(
      "/*!"
      "Pure v1.0.0"
      "Copyright 2013 Yahoo!"
      "Licensed under the BSD License."
      "https://github.com/yahoo/pure/blob/master/LICENSE.md"
      "*/"
      "/*!"
      "normalize.css v^3.0 | MIT License | git.io/normalize"
      "Copyright (c) Nicolas Gallagher and Jonathan Neal"
      "*/"
      "/*! normalize.css v3.0.3 | MIT License | github.com/necolas/normalize.css */.pure-button:focus,a:active,a:hover{outline:0}.pure-table,table{border-collapse:collapse;border-spacing:0}html{font-family:sans-serif;-ms-text-size-adjust:100%;-webkit-text-size-adjust:100%}body{margin:0}article,aside,details,figcaption,figure,footer,header,hgroup,main,menu,nav,section,summary{display:block}audio,canvas,progress,video{display:inline-block;vertical-align:baseline}audio:not([controls]){display:none;height:0}[hidden],template{display:none}a{background-color:transparent}abbr[title]{border-bottom:1px dotted}b,optgroup,strong{font-weight:700}dfn{font-style:italic}h1{font-size:2em;margin:.67em 0}mark{background:#ff0;color:#000}small{font-size:80%}sub,sup{font-size:75%;line-height:0;position:relative;vertical-align:baseline}sup{top:-.5em}sub{bottom:-.25em}img{border:0}svg:not(:root){overflow:hidden}figure{margin:1em 40px}hr{box-sizing:content-box;height:0}pre,textarea{overflow:auto}code,kbd,pre,samp{font-family:monospace,monospace;font-size:1em}button,input,optgroup,select,textarea{color:inherit;font:inherit;margin:0}.pure-button,input{line-height:normal}button{overflow:visible}button,select{text-transform:none}button,html input[type=button],input[type=reset],input[type=submit]{-webkit-appearance:button;cursor:pointer}button[disabled],html input[disabled]{cursor:default}button::-moz-focus-inner,input::-moz-focus-inner{border:0;padding:0}input[type=checkbox],input[type=radio]{box-sizing:border-box;padding:0}input[type=number]::-webkit-inner-spin-button,input[type=number]::-webkit-outer-spin-button{height:auto}input[type=search]{-webkit-appearance:textfield;box-sizing:content-box}.pure-button,.pure-form input:not([type]),.pure-menu{box-sizing:border-box}input[type=search]::-webkit-search-cancel-button,input[type=search]::-webkit-search-decoration{-webkit-appearance:none}fieldset{border:1px solid silver;margin:0 2px;padding:.35em .625em .75em}legend,td,th{padding:0}legend{border:0}.hidden,[hidden]{display:none!important}.pure-img{max-width:100%;height:auto;display:block}.pure-g{letter-spacing:-.31em;text-rendering:optimizespeed;font-family:FreeSans,Arimo,\"Droid Sans\",Helvetica,Arial,sans-serif;display:-webkit-box;display:-webkit-flex;display:-ms-flexbox;display:flex;-webkit-flex-flow:row wrap;-ms-flex-flow:row wrap;flex-flow:row wrap;-webkit-align-content:flex-start;-ms-flex-line-pack:start;align-content:flex-start}@media all and (-ms-high-contrast:none),(-ms-high-contrast:active){table .pure-g{display:block}}.opera-only :-o-prefocus,.pure-g{word-spacing:-.43em}.pure-u,.pure-u-1,.pure-u-1-1,.pure-u-1-12,.pure-u-1-2,.pure-u-1-24,.pure-u-1-3,.pure-u-1-4,.pure-u-1-5,.pure-u-1-6,.pure-u-1-8,.pure-u-10-24,.pure-u-11-12,.pure-u-11-24,.pure-u-12-24,.pure-u-13-24,.pure-u-14-24,.pure-u-15-24,.pure-u-16-24,.pure-u-17-24,.pure-u-18-24,.pure-u-19-24,.pure-u-2-24,.pure-u-2-3,.pure-u-2-5,.pure-u-20-24,.pure-u-21-24,.pure-u-22-24,.pure-u-23-24,.pure-u-24-24,.pure-u-3-24,.pure-u-3-4,.pure-u-3-5,.pure-u-3-8,.pure-u-4-24,.pure-u-4-5,.pure-u-5-12,.pure-u-5-24,.pure-u-5-5,.pure-u-5-6,.pure-u-5-8,.pure-u-6-24,.pure-u-7-12,.pure-u-7-24,.pure-u-7-8,.pure-u-8-24,.pure-u-9-24{letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto;display:inline-block;zoom:1}.pure-g [class*=pure-u]{font-family:sans-serif}.pure-u-1-24{width:4.1667%}.pure-u-1-12,.pure-u-2-24{width:8.3333%}.pure-u-1-8,.pure-u-3-24{width:12.5%}.pure-u-1-6,.pure-u-4-24{width:16.6667%}.pure-u-1-5{width:20%}.pure-u-5-24{width:20.8333%}.pure-u-1-4,.pure-u-6-24{width:25%}.pure-u-7-24{width:29.1667%}.pure-u-1-3,.pure-u-8-24{width:33.3333%}.pure-u-3-8,.pure-u-9-24{width:37.5%}.pure-u-2-5{width:40%}.pure-u-10-24,.pure-u-5-12{width:41.6667%}.pure-u-11-24{width:45.8333%}.pure-u-1-2,.pure-u-12-24{width:50%}.pure-u-13-24{width:54.1667%}.pure-u-14-24,.pure-u-7-12{width:58.3333%}.pure-u-3-5{width:60%}.pure-u-15-24,.pure-u-5-8{width:62.5%}.pure-u-16-24,.pure-u-2-3{width:66.6667%}.pure-u-17-24{width:70.8333%}.pure-u-18-24,.pure-u-3-4{width:75%}.pure-u-19-24{width:79.1667%}.pure-u-4-5{width:80%}.pure-u-20-24,.pure-u-5-6{width:83.3333%}.pure-u-21-24,.pure-u-7-8{width:87.5%}.pure-u-11-12,.pure-u-22-24{width:91.6667%}.pure-u-23-24{width:95.8333%}.pure-u-1,.pure-u-1-1,.pure-u-24-24,.pure-u-5-5{width:100%}.pure-button{display:inline-block;zoom:1;white-space:nowrap;vertical-align:middle;text-align:center;cursor:pointer;-webkit-user-drag:none;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none}.pure-button::-moz-focus-inner{padding:0;border:0}.pure-button-group{letter-spacing:-.31em;text-rendering:optimizespeed}.opera-only :-o-prefocus,.pure-button-group{word-spacing:-.43em}.pure-button{font-family:inherit;font-size:100%;padding:.5em 1em;color:#444;color:rgba(0,0,0,.8);border:1px solid #999;border:transparent;background-color:#E6E6E6;text-decoration:none;border-radius:2px}.pure-button-hover,.pure-button:focus,.pure-button:hover{filter:alpha(opacity=90);background-image:-webkit-linear-gradient(transparent,rgba(0,0,0,.05) 40%,rgba(0,0,0,.1));background-image:linear-gradient(transparent,rgba(0,0,0,.05) 40%,rgba(0,0,0,.1))}.pure-button-active,.pure-button:active{box-shadow:0 0 0 1px rgba(0,0,0,.15) inset,0 0 6px rgba(0,0,0,.2) inset;border-color:#000\9}.pure-button-disabled,.pure-button-disabled:active,.pure-button-disabled:focus,.pure-button-disabled:hover,.pure-button[disabled]{border:none;background-image:none;filter:alpha(opacity=40);opacity:.4;cursor:not-allowed;box-shadow:none;pointer-events:none}.pure-button-hidden{display:none}.pure-button-primary,.pure-button-selected,a.pure-button-primary,a.pure-button-selected{background-color:#0078e7;color:#fff}.pure-button-group .pure-button{letter-spacing:normal;word-spacing:normal;vertical-align:top;text-rendering:auto;margin:0;border-radius:0;border-right:1px solid #111;border-right:1px solid rgba(0,0,0,.2)}.pure-button-group .pure-button:first-child{border-top-left-radius:2px;border-bottom-left-radius:2px}.pure-button-group .pure-button:last-child{border-top-right-radius:2px;border-bottom-right-radius:2px;border-right:none}.pure-form input[type=password],.pure-form input[type=email],.pure-form input[type=url],.pure-form input[type=date],.pure-form input[type=month],.pure-form input[type=time],.pure-form input[type=datetime],.pure-form input[type=datetime-local],.pure-form input[type=week],.pure-form input[type=tel],.pure-form input[type=color],.pure-form input[type=number],.pure-form input[type=search],.pure-form input[type=text],.pure-form select,.pure-form textarea{padding:.5em .6em;display:inline-block;border:1px solid #ccc;box-shadow:inset 0 1px 3px #ddd;border-radius:4px;vertical-align:middle;box-sizing:border-box}.pure-form input:not([type]){padding:.5em .6em;display:inline-block;border:1px solid #ccc;box-shadow:inset 0 1px 3px #ddd;border-radius:4px}.pure-form input[type=color]{padding:.2em .5em}.pure-form input:not([type]):focus,.pure-form input[type=password]:focus,.pure-form input[type=email]:focus,.pure-form input[type=url]:focus,.pure-form input[type=date]:focus,.pure-form input[type=month]:focus,.pure-form input[type=time]:focus,.pure-form input[type=datetime]:focus,.pure-form input[type=datetime-local]:focus,.pure-form input[type=week]:focus,.pure-form input[type=tel]:focus,.pure-form input[type=color]:focus,.pure-form input[type=number]:focus,.pure-form input[type=search]:focus,.pure-form input[type=text]:focus,.pure-form select:focus,.pure-form textarea:focus{outline:0;border-color:#129FEA}.pure-form input[type=file]:focus,.pure-form input[type=checkbox]:focus,.pure-form input[type=radio]:focus{outline:#129FEA auto 1px}.pure-form .pure-checkbox,.pure-form .pure-radio{margin:.5em 0;display:block}.pure-form input:not([type])[disabled],.pure-form input[type=password][disabled],.pure-form input[type=email][disabled],.pure-form input[type=url][disabled],.pure-form input[type=date][disabled],.pure-form input[type=month][disabled],.pure-form input[type=time][disabled],.pure-form input[type=datetime][disabled],.pure-form input[type=datetime-local][disabled],.pure-form input[type=week][disabled],.pure-form input[type=tel][disabled],.pure-form input[type=color][disabled],.pure-form input[type=number][disabled],.pure-form input[type=search][disabled],.pure-form input[type=text][disabled],.pure-form select[disabled],.pure-form textarea[disabled]{cursor:not-allowed;background-color:#eaeded;color:#cad2d3}.pure-form input[readonly],.pure-form select[readonly],.pure-form textarea[readonly]{background-color:#eee;color:#777;border-color:#ccc}.pure-form input:focus:invalid,.pure-form select:focus:invalid,.pure-form textarea:focus:invalid{color:#b94a48;border-color:#e9322d}.pure-form input[type=file]:focus:invalid:focus,.pure-form input[type=checkbox]:focus:invalid:focus,.pure-form input[type=radio]:focus:invalid:focus{outline-color:#e9322d}.pure-form select{height:2.25em;border:1px solid #ccc;background-color:#fff}.pure-form select[multiple]{height:auto}.pure-form label{margin:.5em 0 .2em}.pure-form fieldset{margin:0;padding:.35em 0 .75em;border:0}.pure-form legend{display:block;width:100%;padding:.3em 0;margin-bottom:.3em;color:#333;border-bottom:1px solid #e5e5e5}.pure-form-stacked input:not([type]),.pure-form-stacked input[type=password],.pure-form-stacked input[type=email],.pure-form-stacked input[type=url],.pure-form-stacked input[type=date],.pure-form-stacked input[type=month],.pure-form-stacked input[type=time],.pure-form-stacked input[type=datetime],.pure-form-stacked input[type=datetime-local],.pure-form-stacked input[type=week],.pure-form-stacked input[type=tel],.pure-form-stacked input[type=color],.pure-form-stacked input[type=file],.pure-form-stacked input[type=number],.pure-form-stacked input[type=search],.pure-form-stacked input[type=text],.pure-form-stacked label,.pure-form-stacked select,.pure-form-stacked textarea{display:block;margin:.25em 0}.pure-form-aligned .pure-help-inline,.pure-form-aligned input,.pure-form-aligned select,.pure-form-aligned textarea,.pure-form-message-inline{display:inline-block;vertical-align:middle}.pure-form-aligned textarea{vertical-align:top}.pure-form-aligned .pure-control-group{margin-bottom:.5em}.pure-form-aligned .pure-control-group label{text-align:right;display:inline-block;vertical-align:middle;width:10em;margin:0 1em 0 0}.pure-form-aligned .pure-controls{margin:1.5em 0 0 11em}.pure-form .pure-input-rounded,.pure-form input.pure-input-rounded{border-radius:2em;padding:.5em 1em}.pure-form .pure-group fieldset{margin-bottom:10px}.pure-form .pure-group input,.pure-form .pure-group textarea{display:block;padding:10px;margin:0 0 -1px;border-radius:0;position:relative;top:-1px}.pure-form .pure-group input:focus,.pure-form .pure-group textarea:focus{z-index:3}.pure-form .pure-group input:first-child,.pure-form .pure-group textarea:first-child{top:1px;border-radius:4px 4px 0 0;margin:0}.pure-form .pure-group input:first-child:last-child,.pure-form .pure-group textarea:first-child:last-child{top:1px;border-radius:4px;margin:0}.pure-form .pure-group input:last-child,.pure-form .pure-group textarea:last-child{top:-2px;border-radius:0 0 4px 4px;margin:0}.pure-form .pure-group button{margin:.35em 0}.pure-form .pure-input-1{width:100%}.pure-form .pure-input-3-4{width:75%}.pure-form .pure-input-2-3{width:66%}.pure-form .pure-input-1-2{width:50%}.pure-form .pure-input-1-3{width:33%}.pure-form .pure-input-1-4{width:25%}.pure-form .pure-help-inline,.pure-form-message-inline{display:inline-block;padding-left:.3em;color:#666;vertical-align:middle;font-size:.875em}.pure-form-message{display:block;color:#666;font-size:.875em}@media only screen and (max-width :480px){.pure-form button[type=submit]{margin:.7em 0 0}.pure-form input:not([type]),.pure-form input[type=password],.pure-form input[type=email],.pure-form input[type=url],.pure-form input[type=date],.pure-form input[type=month],.pure-form input[type=time],.pure-form input[type=datetime],.pure-form input[type=datetime-local],.pure-form input[type=week],.pure-form input[type=tel],.pure-form input[type=color],.pure-form input[type=number],.pure-form input[type=search],.pure-form input[type=text],.pure-form label{margin-bottom:.3em;display:block}.pure-group input:not([type]),.pure-group input[type=password],.pure-group input[type=email],.pure-group input[type=url],.pure-group input[type=date],.pure-group input[type=month],.pure-group input[type=time],.pure-group input[type=datetime],.pure-group input[type=datetime-local],.pure-group input[type=week],.pure-group input[type=tel],.pure-group input[type=color],.pure-group input[type=number],.pure-group input[type=search],.pure-group input[type=text]{margin-bottom:0}.pure-form-aligned .pure-control-group label{margin-bottom:.3em;text-align:left;display:block;width:100%}.pure-form-aligned .pure-controls{margin:1.5em 0 0}.pure-form .pure-help-inline,.pure-form-message,.pure-form-message-inline{display:block;font-size:.75em;padding:.2em 0 .8em}}.pure-menu-fixed{position:fixed;left:0;top:0;z-index:3}.pure-menu-item,.pure-menu-list{position:relative}.pure-menu-list{list-style:none;margin:0;padding:0}.pure-menu-item{padding:0;margin:0;height:100%}.pure-menu-heading,.pure-menu-link{display:block;text-decoration:none;white-space:nowrap}.pure-menu-horizontal{width:100%;white-space:nowrap}.pure-menu-horizontal .pure-menu-list{display:inline-block}.pure-menu-horizontal .pure-menu-heading,.pure-menu-horizontal .pure-menu-item,.pure-menu-horizontal .pure-menu-separator{display:inline-block;zoom:1;vertical-align:middle}.pure-menu-item .pure-menu-item{display:block}.pure-menu-children{display:none;position:absolute;left:100%;top:0;margin:0;padding:0;z-index:3}.pure-menu-horizontal .pure-menu-children{left:0;top:auto;width:inherit}.pure-menu-active>.pure-menu-children,.pure-menu-allow-hover:hover>.pure-menu-children{display:block;position:absolute}.pure-menu-has-children>.pure-menu-link:after{padding-left:.5em;content:\"\25B8\";font-size:small}.pure-menu-horizontal .pure-menu-has-children>.pure-menu-link:after{content:\"\25BE\"}.pure-menu-scrollable{overflow-y:scroll;overflow-x:hidden}.pure-menu-scrollable .pure-menu-list{display:block}.pure-menu-horizontal.pure-menu-scrollable .pure-menu-list{display:inline-block}.pure-menu-horizontal.pure-menu-scrollable{white-space:nowrap;overflow-y:hidden;overflow-x:auto;-ms-overflow-style:none;-webkit-overflow-scrolling:touch;padding:.5em 0}.pure-menu-horizontal.pure-menu-scrollable::-webkit-scrollbar{display:none}.pure-menu-horizontal .pure-menu-children .pure-menu-separator,.pure-menu-separator{background-color:#ccc;height:1px;margin:.3em 0}.pure-menu-horizontal .pure-menu-separator{width:1px;height:1.3em;margin:0 .3em}.pure-menu-horizontal .pure-menu-children .pure-menu-separator{display:block;width:auto}.pure-menu-heading{text-transform:uppercase;color:#565d64}.pure-menu-link{color:#777}.pure-menu-children{background-color:#fff}.pure-menu-disabled,.pure-menu-heading,.pure-menu-link{padding:.5em 1em}.pure-menu-disabled{opacity:.5}.pure-menu-disabled .pure-menu-link:hover{background-color:transparent}.pure-menu-active>.pure-menu-link,.pure-menu-link:focus,.pure-menu-link:hover{background-color:#eee}.pure-menu-selected .pure-menu-link,.pure-menu-selected .pure-menu-link:visited{color:#000}.pure-table{empty-cells:show;border:1px solid #cbcbcb}.pure-table caption{color:#000;font:italic 85%/1 arial,sans-serif;padding:1em 0;text-align:center}.pure-table td,.pure-table th{border-left:1px solid #cbcbcb;border-width:0 0 0 1px;font-size:inherit;margin:0;overflow:visible;padding:.5em 1em}.pure-table td:first-child,.pure-table th:first-child{border-left-width:0}.pure-table thead{background-color:#e0e0e0;color:#000;text-align:left;vertical-align:bottom}.pure-table td{background-color:transparent}.pure-table-odd td,.pure-table-striped tr:nth-child(2n-1) td{background-color:#f2f2f2}.pure-table-bordered td{border-bottom:1px solid #cbcbcb}.pure-table-bordered tbody>tr:last-child>td{border-bottom-width:0}.pure-table-horizontal td,.pure-table-horizontal th{border-width:0 0 1px;border-bottom:1px solid #cbcbcb}.pure-table-horizontal tbody>tr:last-child>td{border-bottom-width:0}"

      //custom css here
      ".main {"
          "width: 90%;"
          "max-width: 800px;"
          "margin: 0 auto;"
      "}"
      ".hidden {"
        "display: none;"
      "}"
  ));
}

void SetupMenu::handleIndexHtml() {
  Log::debug(F("Handle incoming request: /"));
  this->webServer->send(200, F("text/html"), R"(<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Setup</title>
        <link rel="stylesheet" type="text/css" href="/main.css">
    </head>
    <body>
        <noscript><h1>YOU HAVE TO ENABLE JAVASCRIPT!</h1></noscript>
        <div class="main">
            <header>
                <h1>Device Setup</h1>
            </header>
            <form method="POST" class="pure-form pure-form-aligned">
                <fieldset>
                    <legend>Device</legend>

                    <div class="pure-control-group">
                        <label for="displayRotation">Display rotation</label>
                        <select id="displayRotation">
                            <option value="0">0°</option>
                            <option value="1">90°</option>
                            <option value="2">180°</option>
                            <option value="3">270°</option>
                        </select>
                    </div>
                </fieldset>

                <fieldset>
                    <legend>Wifi</legend>

                    <div class="pure-control-group">
                        <label for="wifi_ssid">SSID</label>
                        <input type="text" id="wifi_ssid" required></input>
                        <select id="wifi_ssid_found" class="hidden" onchange="selectScanSSID(this.value);"></select>
                    </div>

                    <div class="pure-control-group">
                        <label>Wifi mode</label>
                        <label for="wifi_personal" class="pure-radio">
                            <input id="wifi_personal" type="radio" name="wifi_mode" value="personal" checked>
                            Personal
                        </label>
                        <label for="wifi_eap" class="pure-radio">
                            <input id="wifi_eap" type="radio" name="wifi_mode" value="eap">
                            Enterprise
                        </label>
                    </div>

                    <div class="pure-control-group wifi-eap hidden">
                        <label for="wifi_username">Username</label>
                        <input type="text" id="wifi_username"></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="wifi_password">Password</label>
                        <input type="password" id="wifi_password" required></input>
                        <button type="button" value="wifi_password" class="pure-button" onclick="togglePw('wifi_password');">show/hide password</button>
                    </div>
                </fieldset>

                <fieldset>
                    <legend>MQTT</legend>

                    <div class="pure-control-group">
                        <label for="mqtt_host">Host</label>
                        <input type="text" id="mqtt_host" required></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_port">Port</label>
                        <input type="text" id="mqtt_port" required></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_client_id">ClientId</label>
                        <input type="text" id="mqtt_client_id" required></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_username">Username</label>
                        <input type="text" id="mqtt_username"></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_password">Password</label>
                        <input type="text" id="mqtt_password"></input>
                        <button type="button" value="mqtt_password" class="pure-button" onclick="togglePw('mqtt_password');">show/hide password</button>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_topic_subscribe">Topic</label>
                        <input type="text" id="mqtt_topic_subscribe" required></input>
                    </div>

                    <div class="pure-control-group">
                        <label for="mqtt_topic_state">State Topic</label>
                        <input type="text" id="mqtt_topic_state" required></input>
                    </div>

                </fieldset>

                <button type="submit" name="saveMode" value="0" disabled="disabled" class="pure-button">Save</button>
                <button type="submit" name="saveMode" value="1" disabled="disabled" class="pure-button">Save and restart device</button>
                <button type="submit" name="saveMode" value="2" disabled="disabled" class="pure-button pure-button-primary">Save and exit setup</button>
            </form>
        </div>
        <script src="data.js"></script>
        <script src="main.js"></script>
        <script src="scan.js"></script>
    </body>
</html>)");
}

void SetupMenu::handleMainJs() {
  Log::debug(F("Handle incoming request: /main.js"));
  this->webServer->send(200, F("application/javascript"), F(
      "for(let e of document.getElementsByName('saveMode')) e.disabled = false;"
      "for(let field in data){"
          "let value = data[field];"
          "let e = document.getElementById(field);"
          "e.value = value;"
          "e.name = field;"
      "}"
      "let onWifi = function(evt){"
          "for(let e of document.getElementsByClassName('wifi-eap')){"
            "e.classList.toggle('hidden');"
          "}"
      "};"
      "document.getElementById('wifi_eap').onchange = onWifi;"
      "document.getElementById('wifi_personal').onchange = onWifi;"
      "let togglePw = function(eId){"
        "let e = document.getElementById(eId);"
        "if(e.type === 'password') e.type = 'text';"
        "else e.type = 'password';"
      "};"
      "let selectScanSSID = function(ssid){"
        "document.getElementById('wifi_ssid').value = ssid;"
      "}"
  ));
}

void SetupMenu::handleDataJs() {
  Log::debug(F("Handle incoming request: /data.js"));
  PersistendData data = this->persistence->getData();

  this->webServer->send(200, F("application/javascript"),
    "let data = {" +
        KEY_DISPLAY_ROTATION + ": " + String(data.displayRotation) + "," +

        KEY_WIFI_SSID + ": '" + String(data.wifi.ssid) + "'," +
        KEY_WIFI_USERNAME + ": '" + String(data.wifi.username) + "'," +
        KEY_WIFI_PASSWORD + ": '" + String(data.wifi.password) + "'," +

        KEY_MQTT_HOST + ": '" + String(data.mqtt.host) + "'," +
        KEY_MQTT_PORT + ": " + String(data.mqtt.port) + "," +
        KEY_MQTT_CLIENT_ID + ": '" + String(data.mqtt.clientId) + "'," +
        KEY_MQTT_USERNAME + ": '" + String(data.mqtt.username) + "'," +
        KEY_MQTT_PASSWORD + ": '" + String(data.mqtt.password) + "'," +
        KEY_MQTT_SUBSCRIBE_TOPIC + ": '" + String(data.mqtt.subcribeTopic) + "'," +
        KEY_MQTT_STATE_TOPIC + ": '" + String(data.mqtt.stateTopic) + "'," +
    "};"
  );
}

void SetupMenu::handleScanJs() {
  Log::debug(F("Handle incoming request: /scan.js"));

  int n = WiFi.scanNetworks();
  String result = "let e = document.getElementById('wifi_ssid_found');"
                  "e.classList.toggle('hidden');"
                  "e.innerHTML = '';"
                  "let o = null;";

  for (int i = 0; i < n; ++i) {
    result += "o = document.createElement('option');";
    result += "o.text = '" + WiFi.SSID(i) + "';";
    result += "o.label = '" + WiFi.SSID(i) + " (" + WiFi.RSSI(i) + "dBm)';";
    result += "e.add(o);";
    delay(10);
  }

  this->webServer->send(200, F("application/javascript"), result);
}

void setStringValue(ESP8266WebServer *webServer, String argName, char *target, size_t size) {
  if (webServer->arg(argName).length() > 0) {
    memset(target, 0, size);
    webServer->arg(argName).toCharArray(target, size, 0);
  }
}

void SetupMenu::handleRootPOST() {
  PersistendData data = this->persistence->getData();
  data.displayRotation = (uint8_t) this->webServer->arg(KEY_DISPLAY_ROTATION).toInt();
  int saveMode = this->webServer->arg("saveMode").toInt();

  if (saveMode == 2) {
    data.runMode = RUN_MODE_LISTENING;
  }

  setStringValue(this->webServer, KEY_WIFI_SSID, data.wifi.ssid, sizeof(data.wifi.ssid));
  setStringValue(this->webServer, KEY_WIFI_USERNAME, data.wifi.username, sizeof(data.wifi.username));
  setStringValue(this->webServer, KEY_WIFI_PASSWORD, data.wifi.password, sizeof(data.wifi.password));

  setStringValue(this->webServer, KEY_MQTT_HOST, data.mqtt.host, sizeof(data.mqtt.host));
  data.mqtt.port = (uint16_t)this->webServer->arg(KEY_MQTT_PORT).toInt();
  setStringValue(this->webServer, KEY_MQTT_CLIENT_ID, data.mqtt.clientId, sizeof(data.mqtt.clientId));
  setStringValue(this->webServer, KEY_MQTT_USERNAME, data.mqtt.username, sizeof(data.mqtt.username));
  setStringValue(this->webServer, KEY_MQTT_PASSWORD, data.mqtt.password, sizeof(data.mqtt.password));
  setStringValue(this->webServer, KEY_MQTT_SUBSCRIBE_TOPIC, data.mqtt.subcribeTopic, sizeof(data.mqtt.subcribeTopic));

  this->persistence->saveData(data);
  this->webServer->sendHeader(F("Location"), "/");
  this->webServer->send(303);

  if (saveMode != 0) {
    Log::info(F("Restart device now ..."));
    ESP.restart();
  }
}