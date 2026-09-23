const int enablePin = 5;
const int pin1A = 8;
const int pin2A = 9;
const int potPin = A0;

const int centerValue = 512;
const int deadZone = 50;

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(pin1A, OUTPUT);
  pinMode(pin2A, OUTPUT);

  pinMode(potPin, INPUT);
}

void loop()
{
  int potValue = analogRead(potPin);
  int motorSpeed = 0;

  // 可變電阻轉向一側
  if (potValue < centerValue - deadZone)
  {
    digitalWrite(pin1A, LOW);
    digitalWrite(pin2A, HIGH);

    motorSpeed = map(
      potValue,
      centerValue - deadZone - 1,
      0,
      0,
      255
    );
  }

  // 可變電阻轉向另一側
  else if (potValue > centerValue + deadZone)
  {
    digitalWrite(pin1A, HIGH);
    digitalWrite(pin2A, LOW);

    motorSpeed = map(
      potValue,
      centerValue + deadZone + 1,
      1023,
      0,
      255
    );
  }

  // 可變電阻在中央停止區
  else
  {
    digitalWrite(pin1A, LOW);
    digitalWrite(pin2A, LOW);

    motorSpeed = 0;
  }

  motorSpeed = constrain(motorSpeed, 0, 255);
  analogWrite(enablePin, motorSpeed);
}