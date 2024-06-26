#include <SPI.h>
#include <SD.h>


#define CS 15   // Номер CS esp

File myFile;

/// @brief 
/// @param  begin() - Номер пина для esp.
/// @return Статус инициализации SD карты

bool CardReaderInit (void) {
  Serial.print ("Init SD Card.");
  if (!SD.begin (CS)) {
    return false;
  }
  return true;
}

String ReadSdCardFile (String DirNameIn, String FileNameIn) {
  String FileName = DirNameIn + FileNameIn;
  bool check = SD.exists (FileName);
  if (check) {
    String buffer;
    myFile = SD.open (FileName);                //Откроем файл
    while (myFile.available ())                 //Читаем содержимое файла
    {
      buffer += myFile.readStringUntil ('\n');  //Считываем с карты все данные в строку до символа окончания.
    }
    //Serial.println(buffer);                  //Для отладки отправляем по UART все что прочитали с карты.
    myFile.close ();                            //Закроем файл
    return buffer;
  } 
  return "File Not exist";
}

String RemoveSdCardFile (String DirNameIn, String FileNameIn) {
  String FileName = DirNameIn + FileNameIn;
  bool check = SD.exists (FileName);
  if (check) {
    if (SD.remove (FileName)) return "File delete";
  } 
  return "File not delete";
}

void WriteSdCardFile (String Data) {
  String Folder = RtcTime(false, false) + "/";
  String FileName = String (Folder) + RtcTime(true, true);
  myFile = SD.open(FileName, FILE_WRITE);
  bool check = SD.exists(FileName);
  if (check) {
    myFile.println(Data);
    myFile.close();
    Serial.println("WriteOk");
  } else Serial.println("WriteFail");
}

String printDirectory(File dir) {
  String Note;
  while (true) {
    File entry =  dir.openNextFile();
    if (!entry) {
      return Note;
    }
    Note += String(entry.name()) + String(" ");
    entry.close();
  }
}