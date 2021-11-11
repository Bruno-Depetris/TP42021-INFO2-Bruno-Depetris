#include "motor.h"          
#define pin1 8              
#define pin2 9               
#define pin3 10              
#define pin4 11              

#define pulsadorSentido 3          //pulsador de cambio de sentido
#define pulsadorModo 2          //pulsador de cambio de modo


int _Modo = 0;                //Varible utilizada para indicar cual es el modo
int _Sentido = 1;             //Varible utilizada para indicar cual es el sentido
//antirrebote
int AntR_1 = 0;               
int AntR_2 = 0;               
unsigned long AntR_4 = 0;       
unsigned long AntR_5 = 0;       
//Funciones para las interrupciones al precionar un pulsador
void Mod();              
void Sen();              

MotorPAP motor(pin1,pin2,pin3,pin4);//Se llama a una funcion de la libreria para setear pines

void setup() {
  //Pines de las bobinas como salidas
  pinMode(pin1, OUTPUT);             
  pinMode(pin2, OUTPUT);             
  pinMode(pin3, OUTPUT);             
  pinMode(pin4, OUTPUT); 
              
  //Pines de los pulsadores como entradas
  pinMode(pulsadorSentido, INPUT);         
  pinMode(pulsadorModo, INPUT);   

        
  attachInterrupt(digitalPinToInterrupt(2),Sen,FALLING);   //Interrupcion para el cambio de sentido
  attachInterrupt(digitalPinToInterrupt(3),Mod,FALLING);   //Interrupcion para el cambio de modo
  Serial.begin(9600);
}

void loop() {
  motor.CambioModoySen(_Sentido,_Modo);//Funcion controladora del motor
}
void Mod(){                   //Funcion antirrebote para el cambio de modo
  int AntR_3 = digitalRead(pulsadorModo);  //Valor actual del pulsador
  
  if ((AntR_3 == 1) && (AntR_1 == 0)){
    if(millis()>(AntR_4 + 250)){
      _Modo++;       //Se cambia  el valor de la variable2 modo" para que sepa en que modo debe girar
      if(_Modo == 3){                 
        _Modo = 0;
      }
      AntR_4 = millis();
    }
  }
  AntR_1 = AntR_3;
}
  
void Sen(){  //Funcion antirrebote para el cambio de sentido
  int AntR_3 = digitalRead(pulsadorSentido);   //Valor del pulsador
    
  if ((AntR_3 == 1) && (AntR_2 == 0)){
    if(millis()>(AntR_5 + 250)){
      if(_Sentido == 0){   //Se cambia el valor de la variable "sentido" para que la libreria sepa en que sentido debe girar
        _Sentido = 1;
      }else{
        _Sentido = 0;
      }
      AntR_5 = millis();
      Serial.println("Cambio de sentido");
    }
  }
  AntR_2 = AntR_3;
}
