# NotSoBasicArduino
 The follwing files are my second foray into Arduino
 
 
## Table of Contents
* [Table of Contents](#TableOfContents)
* [LED_Fade](#LED_Fade)
* [HelloFunctions](#HelloFunctions)
* [NewPing](#NewPing)
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

[If you're feeling extra funky, here's the .ino file](placeholder)

### Images

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

