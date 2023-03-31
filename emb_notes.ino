println(" "); //prints to console
serial monitor displays final output. Serial.begin(9600) before that. 9600 is baud rate. it is written in constructor

void setup(){
//this is constructor
}
void loop(){
//this is executed continuously
}

pinMode(pin_no,mode) //digital pins only. mode is INPUT or OUTPUT. also in constructor.
INPUT_PULLUP //port 0 requires pullup resistor
LED_BUILTIN is 13th led

digitalWrite(pin_no, mode); //digitalWrite(4,HIGH) => turns led on 5th on
digitalRead(pin_no, mode);

analogRead()
analogWrite() 3,5,6,9,10,11 are PWM pins. 
