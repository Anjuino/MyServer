#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String SendHTML(void)
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>Control</title>\n"; 
  ptr += "<link rel='stylesheet' href='styles.css'>";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP8266 Web Server</h1>\n";
  ptr +="<h3>Using Access Point(AP) Mode</h3>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

String SendCSS(void)
{
String ptr = "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: blue;margin-bottom: 50px;}\n";
ptr +=".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
ptr +=".button-on {background-color: #1abc9c;}\n";
ptr +=".button-on:active {background-color: #16a085;}\n";
ptr +=".button-off {background-color: #34495e;}\n";
ptr +=".button-off:active {background-color: #2c3e50;}\n";
ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
ptr +="</style>\n";
return ptr;
}

bool APInit (void) {
    bool result;
    return result = WiFi.softAP("ESP8266", "Mesn72154_");
}

void handleStartPage(void) {
  server.send(200, "text/html", SendHTML());
}

void handleCSS(void) {
  server.send(200, "text/css", SendCSS());
}

void ServerStart(void) {
  server.on("/", handleStartPage);
  server.on("/styles.css", handleCSS);
  server.begin();
}


