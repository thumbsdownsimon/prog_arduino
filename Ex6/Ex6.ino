const int a = 2;
const int b = 4;
const int c = 6;
const int d = 8;
const int e = 10;
int incomming = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    incomming = Serial.read();
    if ((char)incomming == 'a') {
      digitalWrite(a, HIGH);
    } else if ((char)incomming == 'b') {
      digitalWrite(b, HIGH);
    } else if ((char)incomming == 'c') {
      digitalWrite(c, HIGH);
    } else if ((char)incomming == 'd') {
      digitalWrite(d, HIGH);
    } else if ((char)incomming == 'e') {
      digitalWrite(e, HIGH);
    } else{
      digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
    }
  }
}
