# NotSoBasicArduino
 The follwing files are my second foray into Arduino
 
 
## Table of Contents
* [Table of Contents](#TableOfContents)
* [LED_Fade](#LED_Fade)
* [Variable_Blink](#Variable_Blink)
* [Button](#Button)
* [HelloFunctions](#HelloFunctions)
* [NewPing](#NewPing)
* [Photoresistor](#Photoresistor)
---

## LED_Fade

### Description & Code

So, first thing. The intial setup can be borrowed from the [official Arduino tutorial here](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade).
Copying the code, and using the schematic they illustrate, you can get a perfectly working fade. They're a better teacher and explain-er than I will ever be.

**But...**
We're not doing a single LED, we're doing **two**!

*Note: please keep up the borrowed Fade code as you work on this. All my adjustments are added on top of the existing code.*

Now, we have to adjust the code to handle a second LED. In the first section where you name your variables, rename led to led1, and add a line for led2. (or whatever names you want, just make sure it's clear one is for a certain LED, and one is for another. Additionally, make sure led2 is then defined as whatever PWM you will attach the wire to. It can't be the one you're already using.
```C++
int led1 = 9;           // the PWM pin the 1st LED is attached to
int led2 = 11;          // the PWM pin the 2nd LED is attached to
```
*Note: CTRL + F can let you replace every instance of ```led ``` with ```led1```. Whatever you do, replace all continued ```led``` variables with ```led1```. Please make sure you don't accidentally make an ```led11```, like I did.*

Now, move on to void setup(). Here, we add ```led2```, and also start the serial monitor on 9600 baud.
```C++
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
};
```

Finally, on the code-front, we finish off by adding led2 using the same ```analogWrite``` code used for led1. Here's what your code should look similar to.
```C++
void loop() {
  // set the brightness of pin 9:
  analogWrite(led1, brightness);
  analogWrite(led2, brightness);
```
... other code you don't need to change
```
}
```

Boom! Now, you have the code setup. 
### Evidence

[Look, you give me a dollar, I give you the link to the code. No questions asked.](https://create.arduino.cc/editor/hheisig51/e8faace7-f646-4134-b6a5-62a50cc688a8/preview)

[If you're feeling extra funky, here's the .ino file](https://github.com/hheisig51/NotSoBasicArduino/blob/main/Code/Fade_2_LED.ino)

### Images

Here's the .svg file I made in Adobe Illustrator, which took me about 3 hours or so.

<img src="https://raw.githubusercontent.com/hheisig51/NotSoBasicArduino/main/Images/Fade%20(2%20LED's).svg" width=500></img>

Here's a blurry .png made from Autodesk Tinkercad's Circuit design tool. Took me about an hour.

<img src="https://raw.githubusercontent.com/hheisig51/NotSoBasicArduino/main/Images/Fade%202%20Led's.png" width=500></img>

Be the judge of what you like. (:

### Reflection

Honestly, the hardest parts of this were the modifications I made. Learning how to stray off the path, and fix problems I made myself, that was very important to learn. If you're reading this, and want to modify something like that, I really recomend just saying the step-by-step out loud. The devil is in the details, and the proof is in the pudding. It may sound rather simple and even slightly dumb, but so is adding a second LED and making it fade. My school email is [hheisig51@charlottesvilleschools.org](mailto:hheisig51@charlottesvilleschools.org) if you would like to discuss this. 

## Variable_Blink

### Description & Code

Alright, time to get this variable blink down. Once again, I have my board setup with 2 LED's, so I'm showing you how to do 2 LED's. We're gonna take a quick little shortcut, and reference/borrow bits off of our [LED_Fade code](https://github.com/hheisig51/NotSoBasicArduino/blob/main/README.md#evidence)

**Just to say it again, the board is setup the EXACT same as the Fade with 2 LED's above.**

Setting up all the ```int``` is easier this time, only 2:
```
int dely = 0; // Sets time for delay when blinking on and off.
int delayVar = -10; // For counting up our speed. Dumb math does dumb thing.
int messagePrint = 0; // Toggle that sets off a figurative nuclear explosion. Will be used once maximum speed is reached.
````

```void setup()``` is ***almost* the EXACT SAME.** START YOUR SERIAL MONITOR, or I take away your Arduino priveleges. Just copy it from Fade, but make sure you write the LED numbers, instead of the ```led1``` and ```led2``` variables.

```void loop()``` is **different**, which really isn't that hard to imagine. We first set up dely's relationship to delayVar, and I really don't know how to make my joke here.

```  int dely = delayVar * -100;```

*Hint: we'll use ++ later to make things easier. Do you know what we're doing?*

Next, we just set up a standard blink function (on both LED's!!), while using dely as our delay amount. Literally just borrow the code from the [Offical Arduino Blink tutorial](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink), and modify it to use the 2 LED pins you're using, plus put dely in as your delay.

```
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  delay(dely);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  delay(dely);
```

What's a person's best friend? **```if``` and ```else``` statements!**

Time to set those puppies up!
First, the thing that adds to DelayVar, speeding up the delay. This is where we use the ++.

```
 if (delayVar < -1) {
    Serial.println(dely);
    delayVar++;
  }
```

This ```if``` statement is what counts up the delayVar, thus making the delay/```dely``` faster and faster! We're gonna be going from -10 to -1 with this, aka 1000 ms to 100 ms.

```
 else if (delayVar == -1 && messagePrint == 0) {
    Serial.println("Reached fastest speed!");
    Serial.end();
    messagePrint++;
  }
```
*I'm going to be 100% honest and frank, I never use ```else``` statements. I've only used ```else if```.*

This ```else if``` statement basically let's us know the LED has reached maximum speed, then self destructs the serial monitor. Nothing more gets printed, nada.

Now, you're done! Test it to see if it works! Please use this annoying, flashing light responsibly.

### Evidence
[A properly formatted link to the code, first try? It's a miracle!](https://create.arduino.cc/editor/hheisig51/ebbdf36b-1cd9-4a06-9bf8-108cb6cad2d7/preview)

[http://ardu.ino (Link to the .ino file)](https://github.com/hheisig51/NotSoBasicArduino/blob/main/Code/Variable_Blink_2_LED.ino)

### Images
<img src="https://github.com/hheisig51/NotSoBasicArduino/blob/main/Images/Variable%20Blink%202%20LED's.png?raw=true" width=500></img>

### Reflection

The [official Arduino Reference](https://www.arduino.cc/reference/en/) and [official Arduino Tutorials](https://www.arduino.cc/en/Tutorial/HomePage) (More specificlly, the [Built-In Tutorials](https://www.arduino.cc/en/Tutorial/BuiltInExamples)). In fact, the whole [entire arduino.cc site](arduino.cc) is so entirely useful.

The internet itself is such a vast resource, and I'm pretty I spend almost a quarter of my time perusing resources. It's so interesting, and just informing to look at. There's no structure, no barriers, just pure streams of information. It's amazing, yet also definitely reminds me why I like having class.

When in doubt, look it up, and figure it out.

## Button

### Description & Code

Alright, let's set up a button! We will use this button to trigger a variable blink (as seen [above](#Variable_Blink), and reset it when the button is released.



### Evidence
[Link to the online code!](https://create.arduino.cc/editor/hheisig51/1021ade9-b6f5-4384-9aeb-5858a6593207/preview)

[The best link to the .ino ever, verified by my grandparents and I.](https://github.com/hheisig51/NotSoBasicArduino/blob/main/Code/Button.ino)

### Images
<img src="https://github.com/hheisig51/NotSoBasicArduino/blob/main/Images/Button.png?raw=true" width=500></img>

### Reflection

## HelloFunctions

### Description & Code
Description goes here

Here's how you make code look like code:

```C++
Code goes here
```
Talk about how the code works, here....

### Evidence
link goes here

### Images
draw it yourself, take a picture, make a fritzing, whatever you want to EFFECTIVELY communicate how its put together.

### Reflection

## NewPing

### Description & Code
Description goes here

Here's how you make code look like code:

```C++
Code goes here
```
Talk about how the code works, here....

### Evidence
link goes here

### Images
draw it yourself, take a picture, make a fritzing, whatever you want to EFFECTIVELY communicate how its put together.

### Reflection

## Photoresistor

### Description & Code

 Hi everybody! Welcome back to the show! Today, we're gonna set up a photoresistor night light! The photoresistor lets a certain amount of electricity through based on the amount of light it detects, and we're going to measure that. We're going to set it up to turn on the LED once the light level dips below a certain point!


 So, let's wire up the photoresistor. Follow the diagram I've put below:
 
<img src="https://github.com/hheisig51/NotSoBasicArduino/blob/main/Images/SoloPhotoresistor.png?raw=true" width=250></img>

Now you've done that, do you see the little wire going to A0? That's what we're going to use to measure the photoresistor's signal. Let's code that. I will include explanations in the comments of the code below

Setup:
```
int lightlevel = 0;  // This will be what we write to from A0.

void setup() {
  pinMode(9, OUTPUT);  // This will be for our LED later
  Serial.begin(9600);  // Starts serial monitor. ALWAYS START YOUR SERIAL MONITOR
}
```

Now, let's go back to wiring up our LED. There's an [diagram below](#Images-4) with the full wiring. Look up to above for other examples of LED wiring. It's super simple.

Code time! ```void loop()``` time! Below, we will setup the ```lightlevel``` integer (from earlier) to read from the A0 pin. From there, we measure it and turn on the LED.

```
void loop() {
  lightlevel = analogRead(A0);        // Takes A0 and writes it to lightlevel
  delay(500);                         // Makes sure we're not just spamming the serial monitor
  Serial.print("Light Level: \t");    
  Serial.println(lightlevel);         // These two lines write the light level to the serial monitor
  if (lightlevel <= 940) {            // If the light level is equal to or less than 940. You can tweak this to your light levels.
    digitalWrite(9, HIGH);            // Turns the LED on
  }
  else if (lightlevel > 940) {        // Pretty self explanatory! When it's more than 940, it
    digitalWrite(9, LOW);             // Turns the LED off
  }
}
```

Now, all the wiring and code is in place! Test it to make sure it works! Now test the nightlight.

### Evidence

[Link to the code, all nice and lit up for the Holidays](https://create.arduino.cc/editor/hheisig51/77ee47c7-8bb7-475f-99c2-7601ce5c02c6/preview)

> "I would never claim to be no Ray Benzino
>
> An 83-year-old fake Pacino,
>
> [Here's the link to my .ino](https://github.com/hheisig51/NotSoBasicArduino/blob/main/Code/Photoresistor.ino)"
>
> - Eminem, *Nail in the Coffin*, 2002 (I don't know, I just needed something to rhyme with ino)

### Images
<img src="https://github.com/hheisig51/NotSoBasicArduino/blob/main/Images/Photoresistor.png?raw=true" width=500></img>

### Reflection

Honestly, it's just flowing with what you remember that really helps here. I've wired an LED dozens of times, I've started and printed to the serial monitor much more than that. Wiring the photoresistor was just following a diagram. You don't need to reinvent the wheel each time you do something, just keep rolling it down the hill. This seems cheesy and anti-climatic, but it's true.
