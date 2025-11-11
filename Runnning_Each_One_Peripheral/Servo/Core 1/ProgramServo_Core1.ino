#include <ESP32Servo.h>

const int servoPin = 8;

Servo myservo;

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
  Serial.println("Servo berjalan di Core 1 (Default)");
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15); 
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}