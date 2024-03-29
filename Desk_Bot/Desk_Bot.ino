#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#ifndef APSSID
#define APSSID "trieutu"
#define APPWD "123456789"
#endif

const char *_ssid = APSSID;
const char *_pwd =APPWD;

ESP8266WebServer server(80);



void handleRoot() {
  
    String html = R"(
    <html>
    <head>
      <link href='https://fonts.googleapis.com/css?family=Lato:300,400,700' rel='stylesheet' type='text/css'>
      <style>
        
        :root {
            --dimension-lion: 308px;
            --c-head: #ff3c00;
            
            /* mouth and beard */
            --c-lip: yellow;
            --c-beard: yellow;
            --c-mouth-base: #ffd586;
            --c-mouth-outline: orange;
            --middle-left-beard-x-pos: 148px;
            --beard-y-pos: 288px;
            --beard-offset: 8px;
            --h-beard-1: 88px;
            --h-beard-2: 83px;
            --h-beard-3: 78px;
            --h-beard-4: 68px;
            --h-beard-5: 58px;
            --h-beard-6: 48px;
            --h-beard-7: 38px;
            --h-beard-8: 28px;
            --beard-shadow-y-1: 48px;
            --beard-shadow-y-2: 44px;
            --beard-shadow-y-3: 38px;
            --beard-shadow-y-4: 34px;
            --beard-shadow-y-5: 28px;
            --beard-shadow-y-6: 24px;
            --beard-shadow-y-7: 18px;
            --beard-shadow-y-8: 14px;
            --c-beard-highlight: red;
            --c-beard-shadow: orange;

            /* eyes */
            --c-eye: yellow;
            --c-eyeball-primary: #2a2a2a;
            --c-eyeball-secondary: #ffecec;
            --c-eyeball-shadow: #ffecec;
            --c-eye-shadow: orange;
            --c-eyelids: #2a2a2a;
            
            /* horn */
            --c-horn-1: red;
            --c-horn-2: orange;
            --c-horn-3: yellow;

            /* ears */
            --b-rad-ear-left: 58px 28px 0 0;
            --b-rad-ear-right: 28px 58px 0 0;
            --c-ear-inside: #909090;
            --c-ear: yellow;
            --c-ear-shadow: orange;

            /* nose*/
            --c-nose: orange;
            --c-nose-2: darkmagenta;
            --c-nose-sides-primary: red;
            --c-nose-sides-secondary: orange;
            --c-thing-1: yellow;
            --c-thing-2: darkmagenta;
            --c-thing-3: limegreen;


            /* diamond */
            --c-diamond: red;
            --c-diamond-border: yellow;
        }

        body {
            margin: 0;
        }

        .content {
            display: grid;
            place-items: center;
            height: 100vh;
        }

        .content > * {
            grid-column: 1;
            grid-row: 1;
        }

        .diamond {
            background-color: var(--c-diamond);
            height: calc(var(--dimension-lion) + 38px);
            width: calc(var(--dimension-lion) + 38px);
            transform: rotate(45deg);
            outline: 8px solid var(--c-diamond-border);
            box-shadow: 0px 0px 0px 18px var(--c-diamond),
                18px 18px 58px 8px;
        }

        .lion {
            height: var(--dimension-lion);
            width: var(--dimension-lion);
        }

        .lion > * {
            position: absolute;
        }

        .head {
            background: var(--c-head);
            width: 218px;
            height: 168px;
            border-radius: 88px 88px 68px 68px;
            transform: translate(48px, 48px);
            box-shadow: inset 0 0 18px 0px darkred, 
                0 18px 18px var(--c-mouth-outline),
                0 28px 0 4px var(--c-lip),
                0 28px 8px 4px var(--c-lip);
        }

        .eye {
            background: var(--c-eye);
            width: 118px;
            height: 108px;
            box-shadow: 0 0 4px 8px var(--c-eye-shadow), 
            inset 8px 8px 18px var(--c-eye-shadow), 
            inset -8px 0px 18px var(--c-eye-shadow);
            border-radius: var(--eye-border-radius);
            transform: var(--eye-transform);
        }
        .eye.eye-left {
            --eye-border-radius: 38px 58px 48px;
            --eye-transform: translate(18px, 78px) rotate(8deg);
        }
        .eye.eye-right {
            --eye-border-radius: 58px 38px 58px 48px;
            --eye-transform: translate(178px, 78px) rotate(-8deg);
        }
        .eye .eyeball {
            background: var(--c-eyeball-primary);
            position: absolute;
            border-radius: 48px;
            width: 18px;
            height: 18px;
            box-shadow: 0 0 0 4px var(--c-eyeball-secondary), 
                0px -2px 0 8px var(--c-eyeball-primary),
                0px -4px 0 12px var(--c-eyeball-secondary), 
                0px -7px 0px 18px var(--c-eyeball-primary),
                0 -8px 18px 18px var(--c-eyeball-shadow);
            transform: translate(48px, 68px);
            animation: blink 3.8s infinite;
        }

        @keyframes blink {
            0%, 20%, 100% {
                --c-eyeball-primary: #2a2a2a;
                --c-eyeball-secondary: #ffecec;
            }
            18% {
                --c-eyeball-primary: var(--c-eyelids);
                --c-eyeball-secondary:var(--c-eyelids);
            }
        }

        .horn {
            width: 18px;
            height: 18px;
            background: var(--c-horn-1);
            transform: translate(148px, 68px);
            border-radius: 48%;
            box-shadow: 0 0 8px, 
                0 0 0 8px var(--c-horn-2), 
                0 0 8px 8px,  
                0 4px 0 18px var(--c-horn-3),
                0 5px 8px 18px;
        }

        .ear {
            width: 78px;
            height: 58px;
            background: var(--c-ear);
            box-shadow: inset 0 0 18px 8px var(--c-ear-shadow),
                0 0 8px 4px var(--c-ear-shadow);
            transform-origin: bottom;
            transform: var(--ear-translate) var(--ear-rotate-1);
            animation: earRotate 2.8s infinite both;
        }
        .ear::before {
            content: '';
            position: absolute;
            height: 28px;
            width: 28px;
            background: var(--c-ear-inside);
            transform: var(--ear-inside-translate);
            box-shadow: inset var(--ear-inside-inset-shadow-x) 4px 18px 0px black, 
                0 0 8px 8px var(--c-ear-shadow);
        }
        .ear.ear-left, .ear.ear-left::before { 
            border-radius: var(--b-rad-ear-left);
            --ear-translate: translate(58px, 12px);
            --ear-rotate-1: rotate(-18deg);
            --ear-rotate-2: rotate(-38deg);
            --ear-inside-translate: translate(11px, 24px);
            --ear-inside-inset-shadow-x: -4px;
        }
        .ear.ear-right, .ear.ear-right::before { 
            border-radius: var(--b-rad-ear-right);
            --ear-translate: translate(178px, 12px);
            --ear-rotate-1: rotate(18deg);
            --ear-rotate-2: rotate(38deg);
            --ear-inside-translate: translate(37px, 24px);
            --ear-inside-inset-shadow-x: 4px;
        }
        
        @keyframes earRotate {
            28%, 48% {
                transform: var(--ear-translate) var(--ear-rotate-1);
            }
            18%, 38% {
                transform: var(--ear-translate) var(--ear-rotate-2);
            }
        }

        .nose {
            width: 48px;
            height: 48px;
            background: var(--c-nose);
            transform: translate(134px, 168px);
            border-radius: 50%;
            box-shadow: inset 0 -8px 18px 8px var(--c-nose-2),
                0 0 18px;
        }
        .nose::before { /* left */
            --nose-side-translate: translate(-28px, 18px);
            --nose-side-translate-2: translate(-30px, 15px);
            --nose-side-translate-3: translate(-28px, 21px);
            --is-nose-side-left: 1;
            --wiggle-delay: 0s;
        }
        .nose::after { /* right */
            --nose-side-translate: translate(62px, 18px);
            --nose-side-translate-2: translate(64px, 15px);
            --nose-side-translate-3: translate(62px, 21px);
            --is-nose-side-left: -1;
            --wiggle-delay: 0.3s;
        }
        .nose::before, .nose::after {
            content: '';
            position: absolute;
            background: var(--c-nose-sides-primary);
            height: 13px;
            width: 13px;
            border-radius: 50%;
            transform: var(--nose-side-translate);
            box-shadow: calc(1px * var(--is-nose-side-left)) 2px 0 5px var(--c-nose-sides-secondary), 
            calc(2px * var(--is-nose-side-left)) 4px 0px 8px var(--c-nose-sides-primary), 
            calc(3px * var(--is-nose-side-left)) 6px 0px 10px var(--c-nose-sides-secondary),
            calc(3px * var(--is-nose-side-left)) 8px 18px 8px;
            animation: wiggle 1.8s ease-in var(--wiggle-delay) infinite;
        }

        @keyframes wiggle {
            0%, 15%, 20%, 100% {
                transform: var(--nose-side-translate);
            }
            5% {
                transform: var(--nose-side-translate-2);
            }
            10%, 17% {
                transform: var(--nose-side-translate-3);
            }
        }

        .thing-between-eyes {
            width: 23px;
            height: 23px;
            background: var(--c-thing-1);
            transform: translate(145px, 132px);
            border-radius: 50%;
            box-shadow: inset 0px 0px 5px,
                0 0 0 3px var(--c-thing-2),
                0 0 18px 5px,
                0 0 0 10px var(--c-thing-3),
                0 0 18px 5px;
        }
    
        .mouth {
            width: 138px;
            height: 38px;
            border-radius: 0px 0px 88px 88px;
            box-shadow: inset 0px 8px 18px grey,
                0 8px 18px 8px var(--c-mouth-outline),
                0 0 0 2px var(--c-mouth-outline), 
                0px 7px 0 18px var(--c-lip);
            background: repeating-linear-gradient(
                90deg,
                var(--c-mouth-base) 0%, var(--c-mouth-base) 12%,
                var(--c-mouth-outline) 12%, var(--c-mouth-outline) 13%
            );
            transform: translate(88px, 238px);
            --mouth-translate: translate(88px, 218px);
        }

        .beard {
            --mouth-translate: translateY(-20px);
        }
        
        .beard, .mouth {
            animation: gaping 3s infinite;
        }

        @keyframes gaping {
            60% {
                transform: var(--mouth-translate);
            }   
        }

        .beard-left { border-bottom-left-radius: 88% }
        .beard-left:nth-child(1) { --x-pos: var(--middle-left-beard-x-pos) }
        .beard-left:nth-child(2) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 1)) }
        .beard-left:nth-child(3) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 2)) }
        .beard-left:nth-child(4) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 3)) }
        .beard-left:nth-child(5) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 4)) }
        .beard-left:nth-child(6) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 5)) }
        .beard-left:nth-child(7) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 6)) }
        .beard-left:nth-child(8) { --x-pos: calc(var(--middle-left-beard-x-pos) - (var(--beard-offset) * 7)) }
        .beard-right { border-bottom-right-radius: 88% }
        .beard-right:nth-child(9) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 1)) }
        .beard-right:nth-child(10) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 2)) }
        .beard-right:nth-child(11) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 3)) }
        .beard-right:nth-child(12) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 4)) }
        .beard-right:nth-child(13) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 5)) }
        .beard-right:nth-child(14) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 6)) }
        .beard-right:nth-child(15) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 7)) }
        .beard-right:nth-child(16) { --x-pos: calc(var(--middle-left-beard-x-pos) + (var(--beard-offset) * 8)) }
        .beard-left:nth-child(1), .beard-right:nth-child(9) {
            --h-beard: var(--h-beard-1);
            --beard-shadow-y: var(--beard-shadow-y-1);
        }
        .beard-left:nth-child(2), .beard-right:nth-child(10) {
            --h-beard: var(--h-beard-2);
            --beard-shadow-y: var(--beard-shadow-y-2);
        }
        .beard-left:nth-child(3), .beard-right:nth-child(11) {
            --beard-shadow-y: var(--beard-shadow-y-3);
            --h-beard: var(--h-beard-3);
        }
        .beard .beard-left:nth-child(4), .beard-right:nth-child(12) {
            --beard-shadow-y: var(--beard-shadow-y-4);
            --h-beard: var(--h-beard-4);
        }
        .beard .beard-left:nth-child(5), .beard-right:nth-child(13) {
            --beard-shadow-y: var(--beard-shadow-y-5);
            --h-beard: var(--h-beard-5);
        }
        .beard > div:nth-child(6), .beard-right:nth-child(14) {
            --beard-shadow-y: var(--beard-shadow-y-6);
            --h-beard: var(--h-beard-6);
        }
        .beard .beard-left:nth-child(7), .beard-right:nth-child(15) {
            --beard-shadow-y: var(--beard-shadow-y-7);
            --h-beard: var(--h-beard-7);
        }
        .beard .beard-left:nth-child(8), .beard-right:nth-child(16) {
            --beard-shadow-y: var(--beard-shadow-y-8);
            --h-beard: var(--h-beard-8);
        }
        .beard > div {
            position: absolute;
            width: 8px;
            height: 78px;
            background: var(--c-beard);
            transform: translate(var(--x-pos), var(--beard-y-pos));
            height: var(--h-beard);
            box-shadow: inset 0px var(--beard-shadow-y) 8px var(--c-beard-shadow);
        }
        .happy-new-year {
            color: gold; /* Change the text color to gold */
            font-size: 36px; /* Increase the font size */
            font-weight: bold; /* Set font weight to bold */
            position: absolute;
            bottom: 20px;
            text-align: center; /* Center-align the text */
            width: 100%; /* Make the text span the entire width */
        }
      </style>
    </head>
    <body>
      <div class="content">
        <div class="diamond"></div>
        <div class="lion">
          <div class="ear ear-left"></div>
            <div class="ear ear-right"></div>

            <div class="beard">
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>
                <div class="beard-left"></div>

                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
                <div class="beard-right"></div>
            </div>

            <div class="mouth"></div>


            <div class="head"></div>

            <div class="horn"></div>
            
            <div class="eye eye-left">
                <div class="eyeball"></div>
            </div>
            <div class="eye eye-right">
                <div class="eyeball"></div>
            </div>

            <div class="thing-between-eyes"></div>

            <div class="nose"></div>
        </div>
        <div class="happy-new-year">Happy New Year TUONG LINH</div>
      </div>
    </body>
    </html>
  )";
  server.send(200, "text/html", html);
}

void setup(){
  delay(200);
  Serial.begin(115200);
  WiFi.softAP(_ssid,_pwd);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/",handleRoot);
  server.begin();
}

void loop(){
  server.handleClient();
}