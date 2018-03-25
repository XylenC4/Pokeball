#include <SoftwareSerial.h>
 
#define rxPin 5
#define txPin 6
#define SendDataDelay 1
#define MaxBufferLenght 32
int iSendDataPeriodically;
int iLenght;
byte byBuffer[255];

String strData[MaxBufferLenght];
 
SoftwareSerial btSerial(rxPin, txPin);
String btData,btSend;
 
void setupBluetooth() {
  btSerial.begin(9600);
  btSerial.println("AT+NAMEPokeball");
  delay(1500);
}
 
void loopBluetooth() {
  iLenght = btSerial.available();
  if (btSerial.available()){
    btData = btSerial.readString();
    String bDataToLinefeed = btData.substring(0,btData.indexOf("\n"));
    SplitString(bDataToLinefeed);
    
    Serial.print("rec:");
    Serial.println(btData);
    
    SerialReceie();
  }
   
  if (Serial.available()){
    btData = Serial.readString();
    btSerial.println(btData);
    Serial.print("send:");
    Serial.println(btData);
  }


}

void SplitString(String sText) {
  int iLoop;
    for(iLoop=0;iLoop<MaxBufferLenght;iLoop++) {
      strData[iLoop] = "";
    }
  
    bool bExit = false;
    int iValue, iStringNewPos;
    
    while(iValue<MaxBufferLenght-1 && !bExit) {
      iStringNewPos = sText.indexOf("|");

      if(iStringNewPos <= 0) {
        strData[iValue] = sText;
        bExit = true;
      }
      else {
        strData[iValue] = sText.substring(0,iStringNewPos);
        sText = sText.substring(sText.indexOf("|")+1,sText.length());
      }
//      Serial.print("value");
//      Serial.print(iValue);
//      Serial.print(":");
//      Serial.println(strData[iValue]);

      iValue++;
    }
}

void SerialReceie() {
  long iControlCode;
  if(IsNumeric(strData[0])) {
    iControlCode = strData[0].toInt();

    switch (iControlCode) {
    case 1:
      if(strData[1]=="0") {
        btSerial.print("1|0");
        bDisableLED = false;
        Serial.println("LED Enabled");
      }
      else if(strData[1]=="1") {
        btSerial.print("1|1");
        bDisableLED = true;
        Serial.println("LED Disabled");
      }
      break;
    case 2:
      //do something when var equals 2
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  }
}



boolean IsNumeric(String str) {
    for(char i = 0; i < str.length(); i++) {
        if ( !(isDigit(str.charAt(i)) || str.charAt(i) == '.' )) {
            return false;
        }
    }
    return true;
}
