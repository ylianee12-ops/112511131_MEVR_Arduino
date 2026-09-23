#include <Servo.h>

Servo myservo;

const int servoPin = 9;
const int trigPin = 7;
const int echoPin = 6;

const float minDistance = 5.0;
const float maxDistance = 30.0;

void setup()
{
  Serial.begin(9600);

  myservo.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
  myservo.write(90);
}

void loop()
{
  // 送出至少 10 微秒的 Trigger 訊號
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // 測量 Echo 保持 HIGH 的時間
  unsigned long duration =
      pulseIn(echoPin, HIGH, 30000);

  // 如果沒有收到回波
  if (duration == 0)
  {
    Serial.println("No echo");
    delay(60);
    return;
  }

  float distance =
      duration * 0.0343 / 2.0;

  // 限制距離範圍
  float limitedDistance =
      constrain(distance, minDistance, maxDistance);

  // 將 5～30 cm 對應成 0～180 度
  int angle =
      (limitedDistance - minDistance)
      * 180.0
      / (maxDistance - minDistance);

  angle = constrain(angle, 0, 180);

  myservo.write(angle);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Angle: ");
  Serial.print(angle);
  Serial.println(" degrees");

  delay(60);
}