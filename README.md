Fuoco-Pneumatico (WORK IN PROGRESS)

Fuoco-Pneumatico is a tire heat monitoring system that lets you know when your tires are warm and ready to push.
After studying Javascript and Python, I decided to create a tire heat monitoring system as my first project. I wanted to make something that would be useful to me when I take a ride. Whether it be on a motorcycle or a track car, having warm tires is important for grip. This project all started when I experienced an unfortunate high side when taking my motorcycle out one day. I had thought that my tires were warmed up and ready for intense speeds. Unfortunately, I was mistaken. The rear tire completely lost grip and my bike began to fishtail, which left me in the air falling to scratches, rashes, and bruises. The worst part was the damage to my bike. After this accident, I decided it was time to develop a device that told me when my tires were ready rather than guessing and suffering unwelcome consequences. 
To use Fuoco-Pneumatico you must know how to solder. This device is to be wired directly into the motorcycle. When wiring it is important to tap into a wire that sends power only when the ignition is on to avoid any unwanted parasitic draw. Mounting a toggle switch to power Fuoco-Pneumatico from a 12v source is another option as well. It is ideal to check out a wiring diagram for your motorcycle or car manufacturer to pinpoint which wires are able to be used when the ignition is on. If finding a wiring diagram proves difficult, utilizing a multimeter to measure voltages can prove just as effective so long as you ensure there is no parasitic draw. 

DISCLAIMER: I am not responsible for any damages to your vehicle or motorcycle.

<hr>
Parts used:
<hr>

- LCD: Hosyond 3.5 inch 320x480 IPS Capacitive Touch Screen LCD
  (Any screen can be used but I will be using this one)
  ST7796S
  ILI19488 driver

- Arduino Mini w/ printer cable to code 

- EC Buying GY-906 MLX90614 Non-Contact IR infrared Temperature sensor Module x2

 THESE SENSOR PINS DID NOT COME SOLDERED. YOU WOULD HAVE TO SOLDER THE PINS TO THE BOARD IF YOU PLAN TO USE THE PIN AS A CONNECTION.
 I used a HAKKO soldering station to solder mines in place then tested with a multimeter with a wire connected to the pin to make sure they weren’t shorting each other out.

<hr>
WIRES:
<hr>

- DC Connector pigtail MALE and FEMALE. (8 pin)
  
- 22 AWG wire shielded
  
- Soldered connections between Arduino Mini

<hr>
Libraries used:
<hr>

- "Adafruit_GFX.h"

- "Adafruit_ST7796S_kbv.h"
  
- <Fonts/FreeMonoBold12pt7b.h>
  
- <FlickerFreePrint.h>
  
- <SPI.h>
  
- <Wire.h>
  
- <Adafruit_MLX90614.h>
  
- <SparkFunMLX90614.h>

If anyone have any suggestions or more familiar with C++ that would help
greatly thanks!
