int mosfetPin = 5;

void setup() {
  pinMode(mosfetPin, OUTPUT);
}

void loop() {
  digitalWrite(mosfetPin, HIGH); // LED ON
  delay(3000);
  digitalWrite(mosfetPin, LOW);  // LED OFF
  delay(3000);
}
