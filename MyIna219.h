#include <Adafruit_INA219.h> 

Adafruit_INA219 ina219;         

bool InaInit(void) 
{ 
  if (ina219.begin()) return true;  
  else return false;     
}

String GetAdc (void)
{
  float voltage = 0;  
  voltage = ina219.getBusVoltage_V();
  int voltagepercent = (1 - (4.20 - voltage)) * 100;

  if (voltagepercent > 100) voltagepercent = 100;

  if (voltagepercent < 2) voltagepercent = 1;
  
  return String (voltagepercent);
}

String GetCurrent (void)
{
  float current = 0;
  current = ina219.getCurrent_mA();       
  return String (abs(current));
}
