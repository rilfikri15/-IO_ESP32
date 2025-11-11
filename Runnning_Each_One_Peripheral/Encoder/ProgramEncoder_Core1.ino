#define ENCODER_PIN_CLK 4  
#define ENCODER_PIN_DT  5

volatile long encoderCount = 0;


long lastPrintedCount = 0;


void IRAM_ATTR updateEncoder() {

  if (digitalRead(ENCODER_PIN_DT) == LOW) {
    encoderCount++; // Searah jarum jam
  } else {
    encoderCount--; // Berlawanan arah jarum jam
  }
}

void setup() {
  Serial.begin(115200);
  
  // Atur pin encoder sebagai INPUT_PULLUP
  pinMode(ENCODER_PIN_CLK, INPUT_PULLUP);
  pinMode(ENCODER_PIN_DT, INPUT_PULLUP);

  // Pasang interrupt ke pin CLK
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_CLK), updateEncoder, RISING);

  Serial.println("Encoder berjalan di Core 1 (Main Loop)");
  Serial.println("Silakan putar encoder...");
}


void loop() {
  noInterrupts();
  long currentCount = encoderCount;
  interrupts();

  if (currentCount != lastPrintedCount) {
    Serial.print("CORE 1 | Hitungan: ");
    Serial.println(currentCount);
    lastPrintedCount = currentCount;
  }

  delay(10); 
}