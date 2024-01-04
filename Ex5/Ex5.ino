int incomingByte = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.print(incomingByte, DEC);
    Serial.print(" or ");
    Serial.println((char)incomingByte);
  }
}
