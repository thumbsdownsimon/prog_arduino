#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte A0pin = A0;
const double LM35 = 1023;

void setup() {
  pinMode(A0pin, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {


  double runningC=0;

//Make a for loop to sum ten temperature observations to take the mean
  for (int i = 0; i < 10; i++) {
    int A0input = analogRead(A0pin);
    double mVolt = A0input / LM35 * 5000;  //convert it into millivolt since we know 10 millitvolt is 1° celcius
    double C = mVolt / 10.0;           //conver the millivolt into celsius
    runningC = runningC + C;
  }

  double newC=0;
  newC = runningC / 10; //the mean
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(newC);

  if (newC < 26) {
    lcd.setCursor(0, 1);
    lcd.print("Too COLD!!");

  } else if (newC < 29) {
    lcd.setCursor(0, 1);
    lcd.print("Aah dats nice!");

  } else {
    lcd.setCursor(0, 1);
    lcd.print("SAUNA!!");
  }


  delay(1000);//only update each second
}