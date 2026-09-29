#include <TimerOne.h>

const int buttonA = 2;
const int ledA = 6;

const int buttonB = 3;
const int ledB = 7;

// 因為這個變數會在 ISR 裡被修改，所以加 volatile
volatile unsigned long timercount = 0;


// 每 50 ms 會進來一次
void timerISR() {

  // 記錄 Timer Interrupt 發生次數
  timercount++;

  // 讀取 Button A
  int stateA = digitalRead(buttonA);

  // Button 使用 INPUT_PULLUP
  // 所以按下 = LOW
  if (stateA == LOW) {
    digitalWrite(ledA, HIGH);
  } else {
    digitalWrite(ledA, LOW);
  }
}


void setup() {

  // 開啟 Serial Monitor
  Serial.begin(9600);

  // Button
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);

  // LED
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  // 每 50000 us = 50 ms 發生一次 Timer Interrupt
  Timer1.initialize(50000);

  // Interrupt 發生時執行 timerISR()
  Timer1.attachInterrupt(timerISR);
}


void loop() {

  // 處理 Button B
  int stateB = digitalRead(buttonB);

  if (stateB == LOW) {
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }

  // 印出目前 Timer Interrupt 發生幾次
  Serial.print("Timer Count: ");
  Serial.println(timercount);

  // 故意 blocking 1 秒
  delay(1000);
}