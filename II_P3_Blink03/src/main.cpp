#include <arduino.h>
#define btnIN A0
#define LED 10

 

 enum funMode {
OFF,
BLINK1,
BLINK2,
BLINK3,
FADE1,
FADE2,
NBSTATE
 };

 

unsigned long lastDeTime = 0; //ultimo tiempo definido como 0 ó inicio (rebote)
int LstBSTD = HIGH; //ultimo estado pre definido es alto
int btnSTD = 0; //estado presente
int funcSTD = 0; //estado para la seleccion del menu
int BP1 = 100, BP2 = 50, BP3 = 200;
int interB = 100;

 

int brillo = 0;//Estado del brillo
int fadeLed = 2;//valores del LED
int pwm = 11; //salida Led
unsigned long tiempoActual;
unsigned long tiempoloop;
int intervalo=50; //el valor al que tarda a llegar para cumplor primer if

 

 

void setup(){
  pinMode(btnIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(pwm,OUTPUT);
  tiempoActual = millis(); //define el tiempo presente
  tiempoloop = tiempoActual; //valor fijo hasta que termina el if
  
}

 

 void loop(){
/////////////////////////////////////////////////////////////////
func1();
func2();
///////////////////////////////////////////////////

 

   }/////////////////////////voidloop

 

  //////////////////////////////////////
  void func1(){
  int reading = digitalWrite(btnIN);

 

if(reading!=LstBSTD){//ÚLTIMO ESTADO DEL BOTON DEFINIDO
  lastDeTime = millis();//
  
  if((millis()-lastDeTime)>100){
    if(reading!=btnSTD){
      btnSTD = reading;
    }
    if(btnSTD == HIGH){
      funcSTD += 1;
    }
  }
}

 

LstBSTD = reading;
funcSTD = funcSTD %NBSTATE;
}
 }//////////////////////////////////////

 

 void func2(){
  switch(funcSTD) {
case OFF;
digitalWrite(LED,LOW);
break;
case BLINK1;
funcB1(BP1);
break;
case BLINK2;
funcB2(BP2)
break;
case BLINK3;
funcB3(BP3);
break;
case FADE1(interB);
break;
case FADE2;
funcB5(int intervalo);
break;

 

}//swtich
  }

 

void funcB1(int BP1){
  delay(100);
  digitalWrite(LED,LOW);
  delay(100);
  digitalWrite(LED,HIGH);
   }

 

   void funcB2(int BP2){
  delay(50);
  digitalWrite(LED,LOW);
  delay(50);
  digitalWrite(LED,HIGH);
   }

 

   void funcB3(int BP3){
  delay(200);
  digitalWrite(LED,LOW);
  delay(200);
  digitalWrite(LED,HIGH);
   }

 

void funcB4(int interB){
pre_millis=millis();
if((pre_millis - pas_millis) >= interB){
pas_millis = pre_millis;

 

if(L_STD = LOW){
L_STD = HIGH;
}
else{
L_STD = LOW;
  }
}
}
  
void funcB5(int intervalo){
 tiempoActual=millis();
if(tiempoActual>= (tiempoloop+intervalo))
{
analogWrite(pwm,brillo);
brillo = brillo+fadeLed; //variable que aumenta el valor de pwm
if(brillo == 255){
  fadeLed = -fadeLed; //Invierte valor pwm
  }
  tiempoloop = tiempoActual;
}
}