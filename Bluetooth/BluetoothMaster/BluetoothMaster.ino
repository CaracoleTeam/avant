

#include <EasyTransfer.h> //https://github.com/madsci1016/Arduino-EasyTransfer




char temperatureChar[10];
char humidityChar[10];

struct WEATHER_DATA_STRUCTURE
{
  float temperature ;
  float humidity ;
};



WEATHER_DATA_STRUCTURE data;


EasyTransfer ETin, ETout; 


void setup() {
  
  Serial.begin(9600);
  
  ETin.begin(details(data), &Serial);
  
}

void loop() {

  if(ETin.receiveData()){

    String temperatureString = String(data.temperature,1);
    temperatureString.toCharArray(temperatureChar,10);
    Serial.println(temperatureString);
  }
}
