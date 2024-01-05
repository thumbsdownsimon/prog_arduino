<<<<<<< HEAD
const int buttonPin = 12;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;

int buttonState = 0;
int delayMills = 200;
int points = 0;
//int incorrects = 0;
bool ongoingClick = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  Serial.begin(9600);
}

void loop() {
  if (points <= 9) {
    //run a regular pattern
    pattern1();
  } else {
    //run a random pattern
    randomPattern();
  }
}

void pattern1() {
  //lights running back and forth, after the light is turned on one of two functions is called: wrongLight() or rightLight(). 
  //those functions wait for a specified time and watch out for button presses. The difference is whether they award a point or lose the game.
  light(1);
  wrongLight(delayMills);
  light(2);
  wrongLight(delayMills);
  light(3);
  rightLight(delayMills);
  light(4);
  wrongLight(delayMills);
  light(5);
  wrongLight(delayMills);
  light(4);
  wrongLight(delayMills);
  light(3);
  rightLight(delayMills);
  light(2);
  wrongLight(delayMills);
  light(1);
  wrongLight(delayMills);
}

void randomPattern() {
  //the active light randomly hops between the 5 LEDs. LED 3 (the middle one) is the correct one to press.
  int num = random(1,6);  
  light(num);
  if (num == 3) {
    rightLight(200);
  } else {
    wrongLight(200);
  }

}

void rightLight(int milliseconds) {
  bool pointGiven = false; //keeps track of whether a point has already been awarded for this light. More relevant back when the button continuously pressed before click() was implemented.
  for (int i = 0; i < milliseconds; i++) { //the for loop runs for the specified delay, with a delay of 1 millisecond (give or take) between loops. For each loop the button is checked.

    if (click() && !pointGiven) {
      givePoint();
      pointGiven = true;
    }
    delay(1);
  }
}
void wrongLight(int milliseconds) { //same as rightLight, but you lose the game instead.
  for (int i = 0; i < milliseconds; i++) {
    if (click()) {
      wrongPress();
    }
    delay(1);
  }
}

void givePoint() { //awards the player a point, prints the point total, makes every LED flash to give visual feedback, and makes the game faster.
  points++;
  Serial.print("WOW! You have ");
  Serial.print(points);
  Serial.println(" points!");
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delayMills -= 10;
  if (points == 10) { //10 points and you win the game, so you get a little lightshow
    flash();
  }
}
void wrongPress() { //if the player pressed the button during wrongLight(), this fires. You lose the game, every variable is reset, all the lights are turned off for a second.
  Serial.println("You lose");
  points = 0;
  delayMills = 200;
  light(0);
  delay(1000);
}

bool click() { //this function only activates a click when the button is lifted again after being pressed. It only ensures that one button press only activates one click, instead of continuously clicking.
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    ongoingClick = true;
    return false;
  } else if (ongoingClick && buttonState == LOW) {
    ongoingClick = false;
    return true;
  } else {
    return false;
  }
}

void flash() { //long pattern of LED flashes for victory.
  int a = 100; //delay between flashes
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(a);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(a);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(a);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(a);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(a);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(500);
}

void light(int number) { //function to light up one LED and turn off the others.
  if (number == 1) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (number == 2) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (number == 3) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  } else if (number == 4) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
  } else if (number == 5) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
}
=======
int led1 = 2;
int led2 = 4;
int led3 = 6;
int led4 = 8;
int led5 = 10;
const int speed = 5;
const time = 100;
void setup() {

  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {


}
>>>>>>> 0ab425f2dde3ffd88eb4a2c485db8334a220e984
