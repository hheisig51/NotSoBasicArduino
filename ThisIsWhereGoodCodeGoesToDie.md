digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level) 
delay(dely);                       // wait for a second 
Serial.println(tim); 
digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW 
delay(dely);                       // wait for a second tim++;
