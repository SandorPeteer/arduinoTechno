void setup() {
  DDRD = 0xFF;
  Serial.begin(115200);
}

void loop() {
  byte PCM = analogRead(A1) >> 6;
  PORTD = PCM << 4;
  Serial.print((analogRead(A1) >> 2) * 5.0 / 256);
  Serial.print("\t");
  Serial.print(PCM);
  Serial.print("\t");
  Serial.println(PCM, BIN);
}
