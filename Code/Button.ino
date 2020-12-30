/*
  Button time
*/

int LED = 9;
int buttonPin = 7;
int delayVar = -10;
int dely = 0;         // Sets time for delay when blinking on and off.
int buttonState = 0;
int messagePrint = 0;

void setup() {
  // initialize digital pin 9 as an output.
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonState == 1) {
    int dely = delayVar * -100;
    digitalWrite(LED, HIGH);
    delay(dely);
    digitalWrite(LED, LOW);
    delay(dely);
    if (delayVar < -1) {
      Serial.println(dely);
      delayVar++;
    }
    else if (delayVar == -1 && messagePrint == 0) {
      Serial.println("Reached fastest speed!");
      messagePrint++;
    }
  }
  else if (buttonState == 0) {
    delayVar = -10;
   	messagePrint--;
  }
}
