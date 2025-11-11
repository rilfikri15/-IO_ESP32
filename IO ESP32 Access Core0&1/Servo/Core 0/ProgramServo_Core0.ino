#include <ESP32Servo.h>

const int servoPin = 18; 
Servo myservo;

void servoTaskCore0(void *pvParameters) {
  Serial.println("Task Servo dimulai di Core 0");
  myservo.attach(servoPin);
  for (;;) {
   
    myservo.write(50);
    delay(500);
    Serial.println("Servo berada di 50");
    myservo.write(100);
    delay(500);
    Serial.println("Servo berada di 100");
   
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(
      servoTaskCore0,   
      "ServoTask",    
      2048,        
      NULL,      
      1,   
      NULL,     
      0);               
}

void loop() {

   
}