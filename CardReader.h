#include <SPI.h>
#include <SD.h>

#define CS 15   // Номер CS esp

File myFile;

/// @brief 
/// @param  begin() - Номер пина для esp.
/// @return Статус инициализации SD карты

bool CardReaderInit (void) {
  Serial.print("Init SD Card.");
  if (!SD.begin(CS)) {
    return false;
  }
  return true;
}

String ReadSdCardFile (String FileName) {
  bool check = SD.exists(FileName);
  if (check) {
    String buffer;
    myFile = SD.open(FileName);                //Откроем файл
    while (myFile.available())                 //Читаем содержимое файла
    {
      buffer += myFile.readStringUntil('\n');  //Считываем с карты все данные в строку до символа окончания.
    }
    Serial.println(buffer);                    //Для отладки отправляем по UART все что прочитали с карты.
    myFile.close();                            //Закроем файл
    return buffer;
  } 
  return "File Not exist" ;
}