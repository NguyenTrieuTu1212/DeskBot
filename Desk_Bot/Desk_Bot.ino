#include <ESP8266WiFi.h>//Import ESP 8266 WiFi library
#include <WiFiClient.h>//Import WiFi library
#include <ESP8266WebServer.h> //Import ESP 8266 WiFi Webserver



#ifndef APSSID
#define APSSID "microdigisoft"
#define APPSK  "microdigisoft"
#endif

const char *ssid = APSSID;
const char *password = APPSK;
ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "You are connected");
}
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
}