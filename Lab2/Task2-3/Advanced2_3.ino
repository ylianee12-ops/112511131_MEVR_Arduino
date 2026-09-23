const int buttonPinA = 2;
const int ledPinA = 5;

const int buttonPinB = 4;
const int ledPinB = 10;

// A 組：由 ISR 修改，所以加 volatile
volatile bool ledStateA = false;
volatile unsigned long lastInterruptTime = 0;

// B 組：由一般 loop() 修改
bool ledStateB = false;
bool lastButtonStateB = HIGH;

void setup()
{
  pinMode(ledPinA, OUTPUT);
  pinMode(buttonPinA, INPUT_PULLUP);

  pinMode(ledPinB, OUTPUT);
  pinMode(buttonPinB, INPUT_PULLUP);

  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinB, LOW);

  attachInterrupt(
    digitalPinToInterrupt(buttonPinA),
    buttonISR,
    FALLING
  );
}

void buttonISR()
{
  unsigned long currentTime = millis();

  // Button A 防彈跳
  if (currentTime - lastInterruptTime > 200)
  {
    ledStateA = !ledStateA;
    digitalWrite(ledPinA, ledStateA);

    lastInterruptTime = currentTime;
  }
}

void loop()
{
  // Polling：只有執行到這裡時才讀取 Button B
  bool currentButtonStateB = digitalRead(buttonPinB);

  // 偵測 HIGH → LOW，代表按鈕剛被按下
  if (lastButtonStateB == HIGH &&
      currentButtonStateB == LOW)
  {
    ledStateB = !ledStateB;
    digitalWrite(ledPinB, ledStateB);
  }

  lastButtonStateB = currentButtonStateB;

  // 模擬系統忙碌／阻塞
  delay(2000);
}