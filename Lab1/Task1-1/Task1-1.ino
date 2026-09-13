const int potPin = A0;   
const int ledPin = 9;    

unsigned long previousPrintTime = 0;
const unsigned long printInterval = 1000; 

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(potPin);

  // 將 A0 的 0～1023 映射成 PWM 使用的 0～255
  int brightness = map(analogValue, 0, 1023, 0, 255);

  analogWrite(ledPin, brightness);

  unsigned long currentTime = millis();

  if (currentTime - previousPrintTime >= printInterval) {
    Serial.print("Data is ");
    Serial.println(analogValue);

    previousPrintTime = currentTime;
  }
}