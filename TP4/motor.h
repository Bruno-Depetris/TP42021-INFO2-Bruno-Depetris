#ifndef motor_h
#define motor_h
#include <arduino.h>    

class MotorPAP{     
private:
  //Variables privadas
  int Pin1,Pin2,Pin3,Pin4;        
public:
  //Variable publica
  MotorPAP(int _Pin1, int _Pin2, int _Pin3, int _Pin4);   //Funcion para setear los pines
  void UnaBobina(int sentido);      //Movimiento de una bobina
  void DosBobina(int sentido);      //Movimiento de dos bobina
  void MedioPaso(int sentido);      //Movimiento de medio paso
  void CambioModoySen(int sentido, int modo);     //Funcion para cambiar el modo y el sentido
};
#endif
