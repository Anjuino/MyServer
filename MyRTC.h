#include <ThreeWire.h>                            
#include <RtcDS1302.h> 

ThreeWire myWire (0,3,16);                                   // Указываем вывода IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc (myWire);

/*
void RtcSetTime () {
  RtcDateTime compiled = RtcDateTime (__DATE__, __TIME__);   // Копирование даты и времени в compiled
  Rtc.SetDateTime (compiled);                                // Установка времени
}
*/
void RtcSetTimeServer (int Year, int Month, int Day, int Hour, int Minute, int Second) {
  RtcDateTime compiled = RtcDateTime (Year, Month, Day, Hour, Minute, Second);   // Копирование даты и времени в compiled
  Rtc.SetDateTime (compiled);                                    // Установка времени
}

String RtcTime (bool In1, bool In2) {
  RtcDateTime now = Rtc.GetDateTime ();
  String Time;
  if (In2) Time =  String (now.Day ())    + String (".");
  Time += String (now.Month ())  + String (".");
  if (In2) Time += String (now.Year ())   + String ("~");
  if (In2) Time += String (now.Hour ())   + String ("-");
  if (In2) Time += String (now.Minute ());
  if (In1) Time += String ("-") + String(now.Second ());
  //Serial.println (Time);
  return Time;
}