    /////////////////////////////////////////////////////////////////
   //         Arduino Bluetooth Weather Station v1.01             //
  //       Get the latest version of the code here:              //
 //   http://educ8s.tv/arduino-two-way-bluetooth-communication  //
/////////////////////////////////////////////////////////////////

#include <EasyTransfer.h> //https://github.com/madsci1016/Arduino-EasyTransfer


struct SEND_DATA_STRUCTURE
{
  float temperature ;
  float humidity ;
};


int counter = 0;

SEND_DATA_STRUCTURE data;


EasyTransfer  ETout; //We need two EasyTransfer object, one for the data we send, and one for the data we receive.

void setup() {
  Serial.begin(9600); //Baudrate of the Bluetooth modules
  
  ETout.begin(details(data), &Serial);
  
}

void loop() {
  
  counter ++;
  if(counter == 8)//Send data once every two seconds
  {
   data.temperature = 2.0;
   data.humidity =5.0;
   ETout.sendData();
   counter = 0;
  }
  delay(250);
  
}
