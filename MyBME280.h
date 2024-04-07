#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

bool BmeInit () {
  if (bme.begin(0x76)) return true;
  else                 return false;
}

String GetData (int In) {
  String Result;
  float res;
  switch (In)
  {
    case 1:
      res = bme.readTemperature();
      break;

    case 2:
      res = bme.readHumidity();
      break;

    case 3:
      res = bme.readPressure() / 133.3;
      break;

    default:
      return "False parametr";
  }

  Result = String (res);
  return Result;
}