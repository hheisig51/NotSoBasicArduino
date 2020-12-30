/*
  Yes, this is entirely borrowed from the tutorial, with a little modification.
*/

int dely = 0; // set's time for delay when blinking on and off
int delayVar = 10;
int messagePrint = 0;

void setup() {
  // initialize digital pin 9 as an output.
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int dely = delayVar * 100;
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(dely);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  delay(dely);
  
  if (delayVar > 1) {
    Serial.println(dely);
    delayVar--;
  }
  else if (delayVar == 1 && messagePrint == 0) {
    Serial.println(dely);
    Serial.println("Reached fastest speed!");
	messagePrint++;
  }
}