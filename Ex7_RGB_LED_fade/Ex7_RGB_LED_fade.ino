const int ledR = 6;
const int ledG = 5;
const int ledB = 10;

//some ports seem unable to make a gradual change in voltage, instead jumping directly from minimum to maximum when passing 127

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
    int lastRed = red;
    int lastGreen = green;
    int lastBlue = blue;
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();


    for (float i=0; i<1; i+=0.01) {
      //linear interpolation between the current color and the target color
      int redStep   = (lastRed   + i*((float)red   - lastRed  ));
      int greenStep = (lastGreen + i*((float)green - lastGreen));
      int blueStep  = (lastBlue  + i*((float)blue  - lastBlue ));

      //debug prints
      // Serial.print("Red = ");
      // Serial.print(redStep);
      // Serial.print(", green = ");
      // Serial.print(greenStep);
      // Serial.print(", blue = ");
      // Serial.println(blueStep);

      analogWrite(ledR, redStep);
      analogWrite(ledG, greenStep);
      analogWrite(ledB, blueStep);
      delay(50);
    }
  }
}
