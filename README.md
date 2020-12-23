# NotSoBasicArduino
 The follwing files are my second foray into Arduino
 
 
## Table of Contents
* [Table of Contents](#TableOfContents)
* [LED_Fade](#LED_Fade)
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

[If you're feeling extra funky, here's the .ino file](https://raw.githubusercontent.com/hheisig51/NotSoBasicArduino/main/Code/Fade_2_LED.ino)

### Images

Here's the .svg file I made in Adobe Illustrator, which took me about 3 hours or so.

<img src="https://raw.githubusercontent.com/hheisig51/NotSoBasicArduino/main/Images/Fade%20(2%20LED's).svg" width=500></img>

Here's a blurry .png made from Autodesk Tinkercad's Circuit design tool. Took me about an hour.

<img src="https://raw.githubusercontent.com/hheisig51/NotSoBasicArduino/main/Images/Fade%202%20Led's.png" width=500></img>

Be the judge of what you like. (:

### Reflection

Honestly, the hardest parts of this were the modifications I made. Learning how to stray off the path, and fix problems I made myself, that was very important to learn. If you're reading this, and want to modify something like that, I really recomend just saying the step-by-step out loud. The devil is in the details, and the proof is in the pudding. It may sound rather simple and even slightly dumb, but so is adding a second LED and making it fade. My school email is [hheisig51@charlottesvilleschools.org](mailto:hheisig51@charlottesvilleschools.org) if you would like to discuss this. 

## Variable Blink

### Description & Code

Alright, time to get this variable blink down. Once again, I have my board setup with 2 LED's, so I'm showing you how to do 2 LED's. We're gonna take a quick little shortcut, and reference/borrow bits off of our [LED_Fade code](https://github.com/hheisig51/NotSoBasicArduino/blob/main/README.md#evidence)

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

### Evidence
link goes here

### Images
draw it yourself, take a picture, make a fritzing, whatever you want to EFFECTIVELY communicate how its put together.

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
Description goes here

Here's how you make code look like code:

```C++
Code goes here
```
Talk about how the code works, here....

### Evidence
link goes here

### Images
<img src="https://github.com/hheisig51/NotSoBasicArduino/blob/main/Images/Photoresistor.png?raw=true" width=500></img>

### Reflection
