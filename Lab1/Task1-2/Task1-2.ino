const int potPin = A0;
const int buttonPin = 2;

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

bool redOn = false;
bool greenOn = false;

// 按鈕防彈跳
int lastReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // 共陽極：HIGH 代表熄滅
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);

  Serial.begin(9600);
}

void loop() {
  // 可變電阻控制藍光
  int analogValue = analogRead(potPin);
  int brightness = map(analogValue, 0, 1023, 0, 255);
  analogWrite(bluePin, 255 - brightness);

  // 讀取按鈕並進行防彈跳
  int reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime >= debounceDelay) {
    if (reading != stableButtonState) {
      stableButtonState = reading;

      // 每次按下，切換紅光
      if (stableButtonState == LOW) {
        redOn = !redOn;

        if (redOn) {
          Serial.println("Red ON");
        } else {
          Serial.println("Red OFF");
        }
      }
    }
  }

  lastReading = reading;

  // Serial Monitor 輸入 1 開啟綠光，輸入 0 關閉
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      greenOn = true;
      Serial.println("Green ON");
    } else if (command == '0') {
      greenOn = false;
      Serial.println("Green OFF");
    }
  }

  // 共陽極：LOW 開啟，HIGH 關閉
  digitalWrite(redPin, redOn ? LOW : HIGH);
  digitalWrite(greenPin, greenOn ? LOW : HIGH);
}