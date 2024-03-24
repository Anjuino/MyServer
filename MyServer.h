#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

bool APInit (void) {
    bool result;
    return result = WiFi.softAP("ESP8266", "Mesn72154_");
}

void handleStartPage(void) {
  server.send(200, "text/html", ReadSdCardFile("index.html"));
}

void handleCSS(void) {
  server.send(200, "text/css", ReadSdCardFile("styles.css"));
}

void ServerStart(void) {
  server.on("/", handleStartPage);
  server.on("/styles.css", handleCSS);
  server.begin();
}


