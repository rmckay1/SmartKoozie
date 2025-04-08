
void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(A0);
  float voltage = raw * (3.3 / 4095.0);  // Scale for ESP32's ADC
  float degreesC = (voltage - 0.5) * 100.0;
  float degreesF = degreesC * 9.0 / 5.0 + 32.0;

  Serial.print("Degrees C: ");
  Serial.print(degreesC);
  Serial.print(" °C");

  Serial.print("    Degrees F: ");
  Serial.print(degreesF);
  Serial.println(" °F");

  delay(1000);
}
