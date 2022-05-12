#include<Arduino.h>
#define BOTON 13 // boton o pulsador
#define LEDV 12  // Led verde
#define LEDA 11  //Led amarillo
#define LEDR 10  // Led ROjo

int READY=1;
int STOP=0;
int START=2;
int bandera=0;
char IN; 
int conta=0;
int band=1;


void setup() {
  pinMode(BOTON ,INPUT); //EL BOTON ES UNA ENTRADA
  pinMode(LEDV ,OUTPUT); //EL LED VERDE ES UNA SALIDA
  pinMode(LEDA ,OUTPUT); //EL LED AMARILLO ES UNA SALIDA
  pinMode(LEDR ,OUTPUT);  //EL LED ROJO ES UNA SALIDA
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()>0)

  {
    IN=Serial.read();

   //usando un switch case 

    switch(IN)
    { 

      case 'r':
      
        digitalWrite (LEDV,HIGH);
        digitalWrite (LEDA,LOW);
        digitalWrite (LEDR,LOW);
        bandera=READY;
        break;
      

      case 's':
      
        digitalWrite (LEDV,LOW);
        digitalWrite (LEDA,HIGH);
        digitalWrite (LEDR,LOW);
        bandera=START;
        break;
      
      case 'S':
      
        digitalWrite (LEDV,LOW);
        digitalWrite (LEDA,LOW);
        digitalWrite (LEDR,HIGH);
        bandera=STOP;
        Serial.write(conta);
        break;

      

      default:
        break;
      
    }
  }
  
 //delay(1000);
if(bandera==READY && band==1)
  {
    if(digitalRead(13)==HIGH)
    {
      conta++; 
      //Serial.print(conta);
      band=0;
      
    }
  
}

 else if(bandera==READY && band==0){
  if(digitalRead(13)==LOW){
    band=1;
    
    
}
}

}

