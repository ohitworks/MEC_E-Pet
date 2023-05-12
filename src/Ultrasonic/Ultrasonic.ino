#include "message_manager.hpp"

namespace ult{
#ifdef IS_MAIN
  int put_message(char *name, int message_info, void * data_ptr) {
    return 0;
  }
#endif

void setup() {
Serial.begin(9600);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
}

void loop(mmg::MessageManager &msg_manager) {
digitalWrite(7, LOW);
digitalWrite(TrigPin,LOW);        //Send level pulses to the Trigpin pins in low and high order
delayMicroseconds(2);             //Delay time
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
cm=pulseIn(EchoPin,HIGH)/58.0;    //Read the pulse width and convert it to centimeters
Serial.print(cm);
if(cm<=40.0){
  digitalWrite(7, HIGH);
}
Serial.println(); 
delay(1000);
}
}


#ifndef IS_MAIN
void setup() {
  ult::setup();
}

void loop() {
  // put your main code here, to run repeatedly:
    ult::loop(<#initializer#>);
}
#endif