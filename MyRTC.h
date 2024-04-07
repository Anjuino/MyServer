#include <ThreeWire.h>                            
#include <RtcDS1302.h> 

ThreeWire myWire(0,3,16);                                   // Указываем вывода IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void RtcSetTime () {
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);   // Копирование даты и времени в compiled
  Rtc.SetDateTime(compiled);                                // Установка времени
}

String RtcTime () {
  RtcDateTime now = Rtc.GetDateTime();
  String Time;
  Time =  String(now.Day())    + String("-");
  Time += String(now.Month())  + String("-");
  Time += String(now.Year())   + String("~");
  Time += String(now.Hour())   + String("-");
  Time += String(now.Minute());
  //Serial.println (Time);
  return Time;
}