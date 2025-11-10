#include <Arduino.h>

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4


#define STEP_DELAY 3 


int stepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(115200);
  Serial.print("Loop() berjalan di core: ");
  Serial.println(xPortGetCoreID());  

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  for (int i = 0; i < 8; i++) {
    digitalWrite(IN1, stepSequence[i][0]);
    digitalWrite(IN2, stepSequence[i][1]);
    digitalWrite(IN3, stepSequence[i][2]);
    digitalWrite(IN4, stepSequence[i][3]);
    delay(STEP_DELAY);
  }
}
