
const int analogPin = A0;   
const int ledCount = 7;    // the number of LEDs in the bar graph
int out[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

int ledPins[] = {0,2,4,6,8,10,12};  


void setup() {
  
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
    
  }
  for (int i=0; i < 14; i++){
    pinMode(out[i] , OUTPUT);
  }
  pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   pinMode(A2, INPUT);
   pinMode(A3, INPUT);
   pinMode(A4, INPUT);
   pinMode(A5, INPUT);
 
}

void loop() {
  int a  = map(analogRead(A1), 0, 1023, 0, 255);
 analogWrite(1, a);
 analogWrite(3, a);
 analogWrite(5, a);
 analogWrite(7, a);
 analogWrite(9, a);
 analogWrite(11, a);

  
  
  int sensorReading =( analogRead(A0)+analogRead(A2)+analogRead(A4));
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);  
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {   
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } else {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  }

}



