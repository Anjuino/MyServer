#include <Wire.h>
#include <MyIna219.h>
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

  if (STAInit()) {
    Serial.println ("Init STA Done");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println ("Init STA false");
    if (APInit ()) Serial.println ("Init AP Done");
    else Serial.println ("Init AP false");
  }
  

  if (BmeInit()) Serial.println ("Init BME280 Done");
  else Serial.println ("Init BME280 false");

  if (InaInit()) Serial.println ("Init Ina219 Done");
  else Serial.println ("Init Ina219 false");

  Rtc.Begin ();

  ServerStart ();
}

void loop() {
  server.handleClient ();
}
