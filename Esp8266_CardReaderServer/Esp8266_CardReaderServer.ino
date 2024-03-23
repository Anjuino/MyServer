#include <CardReader.h>

void setup() {
  Serial.begin(115200);
  
  if (CardReaderInit ()) {
    Serial.println("Init Done");
  } else Serial.println("Init false");

}

void loop() {

}
