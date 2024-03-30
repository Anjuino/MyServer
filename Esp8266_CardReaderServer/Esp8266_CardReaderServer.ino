#include <CardReader.h>
#include <MyServer.h>
#include <Wire.h>	 


ADC_MODE(ADC_VCC);

void setup() {
  Serial.begin(115200);
  
  if (CardReaderInit ()) Serial.println("Init SD Card Done");
  else Serial.println("Init SD Card false");

  if (APInit ()) Serial.println("Init AP Done");
  else Serial.println("Init AP false");
  
  ServerStart ();
}

void loop() {
  server.handleClient();
  //uint CpuFreg = ESP.getCpuFreqMHz();
  //int Vcc = ESP.getVcc(); 
}
