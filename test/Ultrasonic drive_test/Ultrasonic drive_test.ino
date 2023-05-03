const int TrigPin=8;           //Set pin 8 as the launching pin position
const int EchoPin=9;           //Set pin 9 as the receiving pin position
float cm;                 

void setup() {
Serial.begin(9600);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
}

void loop() {
digitalWrite(7, LOW);
digitalWrite(TrigPin,LOW);        //Send level pulses to the Trigpin pins in low and high order
delayMicroseconds(2);             //Delay time
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
cm=pulseIn(EchoPin,HIGH)/58.0;    //Read the pulse width and convert it to centimeters
if(cm<=40){
  digitalWrite(7,HIGN);           //The distance is less than 40cm and the 7 pin changes from low to high
}
delay(1000);
}



