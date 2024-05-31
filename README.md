# Fuoco-Pneumatico
This is a tire heat monitoring system so you'll know when you're tires are nice and warm to push.

Hello, this is my first project after learning how to code. I started with Javascript then studied Python in college. With this knowledge, I wanted to make something that would help me a lot as well as others. I, unfortunately, experienced a high side on my motorcycle one day because I thought my tires were warm and good to go. Then it happened, the rear tire lost grip and started fishtailing, sending me in the air. I luckily walked away with soreness, road rash, and bruises. My motorcycle was different, it was scratched and cracked. So instead of guessing whether a tire is warm enough, I will be making a device that’ll simply measure the outer tire heat to let you know the optimal temperature for spirited driving on a Sunday. This is not limited to just motorcycles, I plan to use it on my track car as well.

SOLDERING IS REQUIRED
You would have to learn how to solder(RECOMMENDED) as you will be wiring this to your motorcycle. It's important that you tap into a wire that sends power when the ignition is on otherwise it will cause a parasitic draw. You can also mount a toggle switch to power the board and wire directly to a 12v source. Best to look at the wiring diagram of your motorcycle manufacturer to see which wire is hot when the key is switched to ignition. Another method is to use a multimeter and measure the voltage when the key is flipped between on and off for ignition. 
DISCLAIMER: I am not responsible for any damages to your vehicle or motorcycle.

Parts used:
===============================================================

LCD: Hosyond 3.5 inch 320x480 IPS Capacitive Touch Screen LCD
(Any screen can be used but I will be using this one)
ST7796S
ILI19488 driver

===============================================================

Arduino Uno REV3 [A000066]
The printer cable was not supplied (need for coding)

===============================================================

EC Buying GY-906 MLX90614 Non-Contact IR infrared Temperature sensor Module x2

===============================================================

THESE SENSOR PINS DID NOT COME SOLDERED. YOU WOULD HAVE TO SOLDER THE PINS TO THE BOARD IF YOU PLAN TO USE THE PIN AS A CONNECTION.

I used a HAKKO soldering station to solder mines in place then tested with a multimeter with a wire connected to the pin to make sure they weren’t shorting each other out.

===============================================================

WIRES:
DC Connector pigtail MALE
I used 22 AWG for mine.
Dupont male/female connector pins
Dupont pin housing

===============================================================

Libraries used:
"Adafruit_GFX.h"
"Adafruit_ST7796S_kbv.h"
<Fonts/FreeMonoBold12pt7b.h>
<FlickerFreePrint.h>
<SPI.h>
<Wire.h>
<Adafruit_MLX90614.h>
<SparkFunMLX90614.h>
