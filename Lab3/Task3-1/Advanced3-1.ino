#include <TimerOne.h>

const int buttonA = 2;
const int ledA = 6;

const int buttonB = 3;
const int ledB = 7;


volatile unsigned long timercount = 0;



void timerISR() {

  
  timercount++;

 
  int stateA = digitalRead(buttonA);

 
  if (stateA == LOW) {
    digitalWrite(ledA, HIGH);
  } else {
    digitalWrite(ledA, LOW);
  }
}


void setup() {


  Serial.begin(9600);

  
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);

   
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  Timer1.initialize(50000);
  Timer1.attachInterrupt(timerISR);
}


void loop() {


  int stateB = digitalRead(buttonB);

  if (stateB == LOW) {
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }

  Serial.print("Timer Count: ");
  Serial.println(timercount);

  // 故意 blocking 1 秒
  delay(1000);
}
