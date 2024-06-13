void setup() {
  Serial.begin(115200);
  DDRD = 0xFF;
}

void loop() {
  byte PCM = analogRead(A1) / 64;
  PORTD = PCM << 4;


  for (byte i = 1; i < 16; i++) {
    byte PCM = i;
    Serial.println(PCM);
    PORTD = PCM << 4;
    delay(10);
  }
  for (byte i = 0; i < 15; i++) {
    byte PCM = 14 - i;
    Serial.println(PCM);
    PORTD = PCM << 4;
    delay(10);
  }
}
