#include "motor.h"              //Se invcluye libreria creada anteriormente

MotorPAP::MotorPAP(int _Pin1, int _Pin2, int _Pin3, int _Pin4){     //Funcion para setear los pines de las bobinas
  Pin1=_Pin1;
  Pin2=_Pin2;
  Pin3=_Pin3;
  Pin4=_Pin4;
}

void MotorPAP::UnaBobina(int sentido){        //Movimiento de una bobina
  if(sentido == 1){                           //Segun si el sentido va para un lado u otro, le guarda a la matriz los valores de las bobinas para ese sentido y ese modo
    int UnPaso[4][4] ={
    {1, 0, 0, 0},{0, 1, 0, 0},{0, 0, 1, 0}, {0, 0, 0, 1}
    };

    for (int i = 0; i < 4; i++){              //For utilizado para enviar los valore de UnPaso a las salidas y que el motor se mueva en dicho movimiento
      digitalWrite(Pin1, UnPaso[i][0]);
      digitalWrite(Pin2, UnPaso[i][1]);
      digitalWrite(Pin3, UnPaso[i][2]);
      digitalWrite(Pin4, UnPaso[i][3]);
      delay(10);
    }
  }else{
    int UnPaso[4][4] ={
    {0, 0, 0, 1},{0, 0, 1, 0},{0, 1, 0, 0},{1, 0, 0, 0}
    };
    //Serial.println("una bobinas");
    for (int i = 0; i < 4; i++){
      digitalWrite(Pin1, UnPaso[i][0]);
      digitalWrite(Pin2, UnPaso[i][1]);
      digitalWrite(Pin3, UnPaso[i][2]);
      digitalWrite(Pin4, UnPaso[i][3]);
      delay(10);
    }
  }
}

void MotorPAP::DosBobina(int sentido){          //Movimiento de dos bobinas
  if(sentido==1){                               //Segun si el sentido va para un lado u otro, le guarda a la matriz los valores de las bobinas para ese sentido y ese modo
    int DosPaso[4][4] ={
    {1, 1, 0, 0},{0, 1, 1, 0},{0, 0, 1, 1},{1, 0, 0, 1}
    };
    //Serial.println("dos bobinas");
    for (int i = 0; i < 4; i++){
      digitalWrite(Pin1, DosPaso[i][0]);
      digitalWrite(Pin2, DosPaso[i][1]);
      digitalWrite(Pin3, DosPaso[i][2]);
      digitalWrite(Pin4, DosPaso[i][3]);
      delay(10);
    }
  }else{
    int DosPaso[4][4] ={
    {1, 0, 0, 1},{0, 0, 1, 1},{0, 1, 1, 0},{1, 1, 0, 0}
    };
    
    for (int i = 0; i < 4; i++){
      digitalWrite(Pin1, DosPaso[i][0]);
      digitalWrite(Pin2, DosPaso[i][1]);
      digitalWrite(Pin3, DosPaso[i][2]);
      digitalWrite(Pin4, DosPaso[i][3]);
      delay(10);
    }
  }
}

void MotorPAP::MedioPaso(int sentido){          //Movimiento de dos bobinas
  if(sentido==1){//Segun si el sentido va para un lado u otro, le guarda a la matriz los valores de las bobinas para ese sentido y ese modo
    int medioPaso[8][4] = {
    {1, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0},{0, 0, 1, 0},{0, 0, 1, 1},{0, 0, 0, 1}, {1, 0, 0, 1}
    };

    for (int i = 0; i < 8; i++){         
      digitalWrite(Pin1, medioPaso[i][0]);  
      digitalWrite(Pin2, medioPaso[i][1]);
      digitalWrite(Pin3, medioPaso[i][2]);
      digitalWrite(Pin4, medioPaso[i][3]);
      delay(10);
    }
  }else{
    int medioPaso[8][4] ={
    {1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 1, 1},{0, 0, 1, 0},{0, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}
    };

    for (int i = 0; i < 8; i++){        
      digitalWrite(Pin1, medioPaso[i][0]);  
      digitalWrite(Pin2, medioPaso[i][1]);
      digitalWrite(Pin3, medioPaso[i][2]);
      digitalWrite(Pin4, medioPaso[i][3]);
      delay(10);
    }
    
  }
}

void MotorPAP::CambioModoySen(int sentido, int modo){       //Funcion para cambiar de modo y el sentido segun el sentido y el modo que se le indica desde main
  switch(modo){                                        
  case 0:                                             //Si modo == '0' hace el movimiento de 1 bobina
    Serial.println("Una Bobina");
    UnaBobina(sentido);
    break;
  case 1:                                             //Si modo == '1' hace el movimiento de 2 bobinas
    Serial.println("Dos Bobinas");
    DosBobina(sentido);
    break;
  case 2:                                             //Si modo == '2' hace el movimiento de medio paso
    Serial.println("Medio Paso");
    MedioPaso(sentido);
    break;
  }
}
