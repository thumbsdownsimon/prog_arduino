const int a = 2;
const int b = 4;
const int c = 6;
const int d = 8;
const int e = 10;
int incomingByte = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if ((char)incomingByte == 'a') {
      digitalWrite(a, HIGH);
    } else if ((char)incomingByte == 'b') {
      digitalWrite(b, HIGH);
    } else if ((char)incomingByte == 'c') {
      digitalWrite(c, HIGH);
    } else if ((char)incomingByte == 'd') {
      digitalWrite(d, HIGH);
    } else if ((char)incomingByte == 'e') {
      digitalWrite(e, HIGH);
    } else if (incomingByte == 10) {
      //all Serial inputs include a newline byte (decimal value 10), which would ordinarily count turn off all the lights if not for this condition.
    } else {
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
    }
  }
}