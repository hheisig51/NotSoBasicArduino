/*
  Yes, this is entirely borrowed from the tutorial, with a little modification.
*/

int dely = 0; // Sets time for delay when blinking on and off.
int delayVar = -10; // For counting up our speed. Dumb math does dumb thing.
int messagePrint = 0; // Toggle that sets off a figurative nuclear explosion. Will be used once maximum speed is reached.

void setup() {
  // initialize digital pin 9 as an output.
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int dely = delayVar * -100;
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(dely);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  delay(dely);

 
  else if (delayVar == -1 && messagePrint == 0) {
    Serial.println("Reached fastest speed!");
    Serial.end();
    messagePrint++;
  }
}
