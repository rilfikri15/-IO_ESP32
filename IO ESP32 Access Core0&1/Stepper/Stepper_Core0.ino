#include <Arduino.h>

#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

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

TaskHandle_t stepperTaskHandle;

void setStepperPins(int a, int b, int c, int d) {
  digitalWrite(IN1, a);
  digitalWrite(IN2, b);
  digitalWrite(IN3, c);
  digitalWrite(IN4, d);
}

void stepperTask(void *parameter) {
  Serial.print("Stepper task running on core: ");
  Serial.println(xPortGetCoreID());

  while (true) {
    for (int i = 0; i < 8; i++) {
      setStepperPins(stepSequence[i][0], stepSequence[i][1], stepSequence[i][2], stepSequence[i][3]);
      vTaskDelay(pdMS_TO_TICKS(3));
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  
  xTaskCreatePinnedToCore(
    stepperTask,      
    "Stepper Task",     
    2048,              
    NULL,              
    1,               
    NULL, 
    0                  
  );

  delay(500);
}

void loop() {
}
