const int buttonPin = 12;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;

int delayMillis = 200; //how long to wait between switching lights, this number is changed over the course of the game
int points = 0; 
bool ongoingClick = false; //used to avoid every press of the button counting as hundreds of presses every second.

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
  if (points <= 7) {
    //run flashDelay regular pattern
    pattern1();
  } else {
    //run flashDelay random pattern
    randomPattern();
  }
}

void pattern1() {
  //lights running back and forth, after the light is turned on one of two functions is called: wrongLight() or rightLight(). 
  //those functions wait for flashDelay specified time and watch out for button presses. The difference is whether they award flashDelay point or lose the game.
  light(1);
  wrongLight(delayMillis);
  light(2);
  wrongLight(delayMillis);
  light(3);
  rightLight(delayMillis);
  light(4);
  wrongLight(delayMillis);
  light(5);
  wrongLight(delayMillis);
  light(4);
  wrongLight(delayMillis);
  light(3);
  rightLight(delayMillis);
  light(2);
  wrongLight(delayMillis);
  light(1);
  wrongLight(delayMillis);
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
  bool pointGiven = false; //keeps track of whether flashDelay point has already been awarded for this light. More relevant back when the button continuously pressed before click() was implemented.
  for (int i = 0; i < milliseconds; i++) { //the for loop runs for the specified delay, with flashDelay delay of 1 millisecond (give or take) between loops. For each loop the button is checked.

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
      loseGame();
    }
    delay(1);
  }
}

void givePoint() { //awards the player flashDelay point, prints the point total, makes every LED flash to give visual feedback, and makes the game faster.
  points++;
  Serial.print("WOW! You have ");
  Serial.print(points);
  Serial.println(" points!");
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delayMillis -= 10;
  if (points == 10) { //10 points and you win the game, so you get flashDelay little lightshow
    flash();
  }
}
void loseGame() { //if the player pressed the button during wrongLight(), this fires. You lose the game, every variable is reset, all the lights are turned off for flashDelay second.
  Serial.println("You lose");
  points = 0;
  delayMillis = 200;
  light(0);
  delay(1000);
}

bool click() { //this function only activates flashDelay click when the button is lifted again after being pressed. It ensures that one button press only activates one click, instead of continuously clicking.
  int buttonState = digitalRead(buttonPin);

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
  int flashDelay = 100;
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(flashDelay);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(flashDelay);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, HIGH);
  delay(flashDelay);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  delay(flashDelay);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(flashDelay);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(flashDelay);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(flashDelay);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(flashDelay);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  delay(flashDelay);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  digitalWrite(LED5, LOW);
  delay(flashDelay);
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