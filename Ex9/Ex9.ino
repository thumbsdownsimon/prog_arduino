const byte A0pin = A0;
const double LM35 = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int A0input = analogRead(A0pin);
  double mVolt = A0input / LM35 * 5000; //convert it into millivolt since we know 10 millitvolt is 1° celcius
  double C = mVolt / 10.0 + 2;//conver the millivolt into celsius


  Serial.print(C);
  Serial.println(" C°");
}
