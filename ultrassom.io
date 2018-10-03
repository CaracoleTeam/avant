#include <Ultrasonic.h>
 Ultrasonic ultrassom1(8,7);
 Ultrasonic ultrassom2(13,12);
 unsigned long startMillis=0,currentMillis;
 int tempo;
 
 // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(8) e o echo(7) respectivamente
 
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
 void setup() {
 Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
 long distancia1;
 long distancia2;
 
 }
 
// Função que se repete infinitamente quando a placa é ligada
 void loop()
 {
 
long distancia1=0;
long distancia2=0;
oi:;
distancia1 = ultrassom1.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
distancia2=ultrassom2.Ranging(CM);

if(distancia1<distancia2){
  distancia2=0;

if(distancia1<100){
  startMillis = millis();
  Serial.print(distancia1); //imprime o valor da variável distancia
   Serial.println("cm inicio sensor 1");
   delay(1000);
   
   while(distancia2==0){
    long   distancia2 = ultrassom2.Ranging(CM);
    
      if(distancia2<100){
      currentMillis=millis();
      Serial.print(distancia2); //imprime o valor da variável distancia
       Serial.println("cm fim sensor 2");
       delay(1000);
       
       tempo= currentMillis - startMillis;
        Serial.print(tempo); //imprime o valor da variável distancia
       Serial.println("s");
       delay(1000);
       goto oi;
      }
    }
   
  }// centímetros(CM) ou polegadas(INC)
}

if(distancia2<distancia1){
  distancia1=0;
  
  if(distancia2<100){
  startMillis = millis();
  Serial.print(distancia2); //imprime o valor da variável distancia
   Serial.println("cm inicio sensor 2");
   delay(1000);
   
   while(distancia1==0){
    long   distancia1 = ultrassom1.Ranging(CM);
    
      if(distancia1<100){
      currentMillis=millis();
      Serial.print(distancia1); //imprime o valor da variável distancia
       Serial.println("cm fim sensor 1");
       delay(1000);
       
       tempo= currentMillis - startMillis;
        Serial.print(tempo); //imprime o valor da variável distancia
       Serial.println("s");
       delay(1000);
       goto oi;
      }
    }
   
  }
  }

 }
