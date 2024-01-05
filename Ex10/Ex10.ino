const int coldLed = 2;
const int midLed = 4;
const int warmLed = 6;
const byte A0pin = A0;
const double LM35 = 1023;

void setup() {
  pinMode(A0pin, INPUT);
  pinMode(coldLed, OUTPUT);
  pinMode(midLed, OUTPUT);
  pinMode(warmLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int A0input = analogRead(A0pin);
  double mVolt = A0input / LM35 * 5000; //convert it into millivolt since we know 10 millitvolt is 1° celcius
  double C = mVolt / 10.0 + 2;//conver the millivolt into celsius
  
  
  if (C < 26) {
    digitalWrite(coldLed, HIGH);
    digitalWrite(midLed, LOW);
    digitalWrite(warmLed, LOW);
  } else if (C < 29) {
    digitalWrite(coldLed, LOW);
    digitalWrite(midLed, HIGH);
    digitalWrite(warmLed, LOW);
  } else {
    digitalWrite(coldLed, LOW);
    digitalWrite(midLed, LOW);
    digitalWrite(warmLed, HIGH);
  }

}
