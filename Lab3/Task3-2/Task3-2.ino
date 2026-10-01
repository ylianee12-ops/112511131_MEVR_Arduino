const int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // 如果 Serial 有收到資料
  if (Serial.available() > 0) {

    // 讀取一個字元
    char command = Serial.read();

    // 收到 '1' → LED 亮
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }

    // 收到 '0' → LED 滅
    else if (command == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}