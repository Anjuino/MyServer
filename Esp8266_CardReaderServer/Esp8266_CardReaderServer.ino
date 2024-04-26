#include <Wire.h>
#include <MyBME280.h>
#include <MyRTC.h>
#include <CardReader.h>
#include <MyServer.h>
 
ADC_MODE(ADC_VCC);

void setup () {
  Serial.begin (115200);
  Wire.begin(); 

  if (CardReaderInit ()) Serial.println ("Init SD Card Done");
  else Serial.println ("Init SD Card false");

  if (APInit ()) Serial.println ("Init AP Done");
  else Serial.println ("Init AP false");

  if (BmeInit()) Serial.println ("Init BME280 Done");
  else Serial.println ("Init BME280 false");

  Rtc.Begin ();
  //RtcSetTime (); // Установить время

  ServerStart ();
}

void loop() {
  server.handleClient ();
  //printDirectory(SD.open("/Diary"));
  //delay (10000);
  //RtcTime ();
  //delay (10000);                                  
  //uint CpuFreg = ESP.getCpuFreqMHz();
  //int Vcc = ESP.getVcc(); 
}
