#define LCDI2C
//#undef LCDI2c

#define THERMO
//#undef THERMO


#define INPUTBT
//undef INPUTBT


#include "configuration.h"
#include <PID_v1.h>

double Setpoint, Input, Output, Kp=10, Ki=1.2, Kd=2;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

double temp = 0;
int _time = 0;
int samplingTime = 200;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  
  Serial.begin(9600);
  Serial.println("start");
  //pinMode(PIN_HEAT,OUTPUT);
  pinMode(PIN_FAN2, OUTPUT);
  init_button();
  

  digitalWrite(PIN_FAN2,HIGH);
  #ifdef LCDI2C
  init_lcd();
  #endif 

  Setpoint = DEFAULT_T;
  myPID.SetMode(AUTOMATIC);
}

// the loop function runs over and over again forever
void loop() {

  //Serial.println(String(bt0.getState()) + " " + String(bt1.getState()) + " " + String(bt2.getState()));
  Input = readThermo();
  
  refreshLcd(Input,Setpoint);
  myPID.Compute();
  //Serial.print(Output);
  //Serial.print(" ");
  //Serial.println(Input);
  
  if(!bt2.getState()){
    analogWrite(PIN_HEAT,Output);
  }else{
    analogWrite(PIN_HEAT,0);
  }

  if(bt1.getState()){
    Setpoint += 10;
  }
  if(bt0.getState()){
    Setpoint -= 10;
  }

  Serial.print(int(Input));
  Serial.print(";");
  Serial.print(int(Output));
  Serial.print(";");
  Serial.println(0);
  delay(samplingTime);
}
