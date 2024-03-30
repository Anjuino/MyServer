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

void handleInfoPage(void) {
  server.send(200, "text/html", ReadSdCardFile("info.html"));
}

void handleDiaryPage(void) {
  server.send(200, "text/html", ReadSdCardFile("diary.html"));
}

void handleWriteNotePage(void) {
  server.send(200, "text/html", ReadSdCardFile("writeNote.html"));
}

void handleCSS(void) {
  server.send(200, "text/css", ReadSdCardFile("styles.css"));
}

void sensor_data(void)  // Отправка времени работы МК
{
 unsigned long timer;
 timer = millis();
 String time = String(timer);
 server.send(200, "text/plane", time);
}

void writeDiary(void)   // Делаем запись полученных данных на карту памяти
{
 String Dat = server.arg ("Note");
 //string Name = RTC.read(datetime);
 WriteSdCardFile ("1Note.txt", Dat);
 //server.send(200, "text/plane", time);
}

void ServerStart(void) {
  server.on("/", handleStartPage);                     // Страница при первом запуске
  server.on("/index.html", handleStartPage);           // Главная стрница
  server.on("/diary.html", handleDiaryPage);           // Дневник
  server.on("/info.html", handleInfoPage);             // Датчики
  server.on("/writeNote.html", handleWriteNotePage);   // Запись в дневник
  server.on("/styles.css", handleCSS);                 // Стили

  server.on("/read", sensor_data);       // Отправка показаний датчиков          
  server.on("/writeNote", writeDiary);   // Прием записи в дневник
  server.begin();
}