
#define ENCODER_PIN_CLK 4 
#define ENCODER_PIN_DT  5 

volatile long encoderCount = 0;


void IRAM_ATTR updateEncoder() {
  // Baca pin DT untuk menentukan arah
  if (digitalRead(ENCODER_PIN_DT) == LOW) {
    encoderCount++; // Searah jarum jam
  } else {
    encoderCount--; // Berlawanan arah jarum jam
  }
}

void encoderTaskCore0(void *pvParameters) {
  Serial.println("Task Encoder dimulai di Core 0.");
  long lastPrintedCount = 0;

  // Loop tak terbatas untuk task ini
  for (;;) {
    noInterrupts();
    long currentCount = encoderCount;
    interrupts();

    // Hanya cetak jika nilainya berubah
    if (currentCount != lastPrintedCount) {
      Serial.print("CORE 0 | Hitungan: ");
      Serial.println(currentCount);
      lastPrintedCount = currentCount;
    }
    
    delay(50); // Cek setiap 50ms
  }
}


void setup() {
  Serial.begin(115200);
  

  pinMode(ENCODER_PIN_CLK, INPUT_PULLUP);
  pinMode(ENCODER_PIN_DT, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_CLK), updateEncoder, RISING);

  Serial.println("Setup() berjalan di Core 1.");


  xTaskCreatePinnedToCore(
      encoderTaskCore0,   
      "EncoderTask",      
      2048,              
      NULL,   
      1,              
      NULL,             
      1);                
}


void loop() {


}