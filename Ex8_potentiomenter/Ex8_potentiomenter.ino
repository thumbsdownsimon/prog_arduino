const int ledR = 2;
const int ledG = 4;
const int ledB = 6;
const byte A0pin = A0;

void setup() {
  pinMode(A0pin, INPUT);
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  int potentiometerOutput = analogRead(A0pin);
  int adjusted = map(potentiometerOutput, 0, 569, 0, 100); //mapping the output values of the potentiometer to the range of numbers between 0 and 100
  Serial.print("Output = ");
  Serial.print(potentiometerOutput);
  Serial.print(", adjusted = ");
  Serial.println(adjusted);

  //inelegant if-else to cycle through the colors of the rainbow
  if (adjusted > 90) {
    analogWrite(ledR, 255);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
  } else if (adjusted > 85) {
    analogWrite(ledR, 255);
    analogWrite(ledG, 50);
    analogWrite(ledB, 0);
  } else if (adjusted > 80) {
    analogWrite(ledR, 255);
    analogWrite(ledG, 255);
    analogWrite(ledB, 0);
  } else if (adjusted > 70) {
    analogWrite(ledR, 125);
    analogWrite(ledG, 255);
    analogWrite(ledB, 0);
  } else if (adjusted > 60) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 255);
    analogWrite(ledB, 0);
  } else if (adjusted > 50) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 255);
    analogWrite(ledB, 125);
  } else if (adjusted > 40) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 255);
    analogWrite(ledB, 255);
  } else if (adjusted > 30) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 125);
    analogWrite(ledB, 255);
  } else if (adjusted > 20) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 255);
  } else if (adjusted > 10) {
    analogWrite(ledR, 125);
    analogWrite(ledG, 0);
    analogWrite(ledB, 255);
  } else {
    analogWrite(ledR, 255);
    analogWrite(ledG, 0);
    analogWrite(ledB, 255);
  }
  delay(100);
}
