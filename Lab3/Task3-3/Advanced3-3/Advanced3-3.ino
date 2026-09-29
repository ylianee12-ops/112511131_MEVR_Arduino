#include <SoftwareSerial.h>

const int ledPin = 6;

// RX, TX
SoftwareSerial bluetooth(10, 11);

void setup() {
  pinMode(ledPin, OUTPUT);

  // USB Serial，留著 debug 用
  Serial.begin(9600);

  // HC-05 Serial
  bluetooth.begin(9600);

  Serial.println("Bluetooth ready");
}

void loop() {

  if (bluetooth.available() > 0) {

    char command = bluetooth.read();

    // 顯示收到的資料，方便 debug
    Serial.print("Received: ");
    Serial.println(command);

    if (command == '1') {
      digitalWrite(ledPin, HIGH);
    }

    else if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
}