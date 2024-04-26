#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define TEMP 1
#define HUM  2
#define PRES 3

ESP8266WebServer server (80);

bool APInit (void) {
    bool result;
    return result = WiFi.softAP ("ESP8266", "Mesn72154_");
}

void handleStartPage (void) {
  server.send (200, "text/html", ReadSdCardFile ("/", "index.html"));
}

void handleInfoPage (void) {
  server.send (200, "text/html", ReadSdCardFile ("/","info.html"));
}

void handleDiaryPage (void) {
  server.send (200, "text/html", ReadSdCardFile ("/","diary.html"));
}

void handleWriteNotePage (void) {
  server.send (200, "text/html", ReadSdCardFile ("/","writeNote.html"));
}

void handleCSS (void) {
  server.send (200, "text/css", ReadSdCardFile ("/","styles.css"));
}

void sensor_data (void)  // 
{
 String time = RtcTime (false, true);
 server.send (200, "text/plane", time);
}

void sensor_dataTemp (void)  // 
{
 String Temp = GetData (TEMP);
 server.send (200, "text/plane", Temp);
}
void sensor_dataHum (void)  // 
{
 String Hum = GetData (HUM);
 server.send (200, "text/plane", Hum);
}
void sensor_dataPres (void)  // 
{
 String Pres = GetData (PRES);
 server.send (200, "text/plane", Pres);
}

void dataDiary (void)  // 
{
 String Dat = server.arg ("Month");
 String Folder = String ("/") + Dat;
 String CountNote = printDirectory (SD.open (Folder));
 server.send (200, "text/plane", CountNote);
}

void writeDiary (void)   // Делаем запись полученных данных на карту памяти
{
 String Dat = server.arg ("NoteWr");
 WriteSdCardFile (Dat);
 server.send (200, "text/plane", "Успех записи");
}

void readNote (void)   // Чтение файла и отправка
{
 String Month = server.arg ("Month");
 String Folder = Month + String ("/");
 String Dat = server.arg ("Note");
 String Note = ReadSdCardFile (Folder, Dat);
 server.send (200, "text/plane", Note);
}

void ServerStart (void) {
  server.on ("/", handleStartPage);                     // Страница при первом запуске
  server.on ("/index.html", handleStartPage);           // Главная стрница
  server.on ("/diary.html", handleDiaryPage);           // Дневник
  server.on ("/info.html", handleInfoPage);             // Датчики
  server.on ("/writeNote.html", handleWriteNotePage);   // Запись в дневник
  server.on ("/styles.css", handleCSS);                 // Стили

  server.on ("/read", sensor_data);            // Отправка показаний датчиков
  server.on ("/temp", sensor_dataTemp);        // Отправка показаний датчиков
  server.on ("/hum", sensor_dataHum);          // Отправка показаний датчиков  
  server.on ("/pres", sensor_dataPres);        // Отправка показаний датчиков    
  server.on ("/writeNote", writeDiary);        // Прием записи в дневник
  server.on ("/note", dataDiary);              // Вывод содержимого каталога
  server.on ("/readNote", readNote);           // Чтение файла

  server.begin ();
}