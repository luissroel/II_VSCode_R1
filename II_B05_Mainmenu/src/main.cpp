#include <Arduino.h>
#define btnIN A0 //Entrada analogica
#define LED 10 //Salida digital

enum funMode {
  OFF,
  BLINK1,
  BLINK2,
  BLINK3,
  BLINK4,
  FADE1,
  NBSTATE

};

int L_STD = LOW;
unsigned long pre_Millis, pas_Millis;
unsigned long lastDeTime = 0; 
int LstBSTD = HIGH;
int btnSTD = 0; //Estado presente
int funcSTD = 0; //Estados para la seleccion de menu
int BP1 = 50, BP2 = 100, BP3 = 200; 
int interB = 100; 

int brillo = 0;//Estado del brillo
int fadeLed = 2;//valores del LED
int pwm = 11; //salida Led
unsigned long tiempoActual;
unsigned long tiempoloop;
int intervalo = 50; //el valor al que tarda a llegar para cumplor primer if

 
void setup() {
  /////////////////////////////////////////////
  pinMode(btnIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
//////////////////////////////////////////////
}

void loop() {
  func1();
  func2();
}
//////////////////////////////////////////////////
  void func1(){
    int reading = digitalWrite(btnIN);
  if(reading != LstBSTD){ //Ultimo estado del boton definido
  lastDeTime = millis();
if((millis() - lastDeTime) > 100){
  if(reading != btnSTD){
    btnSTD = reading;
}
if(btnSTD == HIGH){
  funcSTD += 1;
}
  } 
  }
  LstBSTD = reading;
  funcSTD = funcSTD%NBSTATE; 
  }
  /////////////////////////////////////////////
  void func2(){
    switch (funcSTD){
    case OFF:
    digitalWrite(LED,LOW);
    break;
    case BLINK1:
    funcB1(BP1);
    break;
    case BLINK2:
    funcB2(BP2);
    break;
    case BLINK3:
    funcB3(BP3);
    break;
    case BLINK4:
    funcB4(interB);
    break;
    case FADE1:
    funcB5(intervalo);
    break;
  } 
  }

///////////////////////////////////////////////
void funcB1(int BP1){
    delay(BP1);
    digitalWrite(LED,LOW);
    delay(BP1);
    digitalWrite(LED,HIGH);
}

void funcB2(int BP2){
    delay(BP2);
    digitalWrite(LED,LOW);
    delay(BP2);
    digitalWrite(LED,HIGH);
}

void funcB3(int BP3){
    delay(BP3);
    digitalWrite(LED,LOW);
    delay(BP3);
    digitalWrite(LED,HIGH);
}

void funcB4(int interB){
  pre_Millis = millis();
  if((pre_Millis-pas_Millis) >= interB){
    pas_Millis = pre_Millis;
    if(L_STD == LOW){
      L_STD == HIGH;
    } else {
        L_STD = LOW;
    }
    }
  }

void funcB5(int intervalo){
  tiempoActual=millis();
   if(tiempoActual>= (tiempoloop+intervalo)){
   analogWrite(pwm,brillo);
   brillo = brillo+fadeLed; //variable que aumenta el valor de pwm
   if(brillo == 255){
   fadeLed = -fadeLed; //Invierte valor pwm
   }
   tiempoloop = tiempoActual;
 }
}
