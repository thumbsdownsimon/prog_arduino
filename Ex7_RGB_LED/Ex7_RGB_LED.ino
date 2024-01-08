const int ledR = 2;
const int ledG = 4;
const int ledB = 6;
int red = 0;
int green = 0;
int blue = 0;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
    analogWrite(ledR, red);
    analogWrite(ledG, green);
    analogWrite(ledB, blue);
  }
}
