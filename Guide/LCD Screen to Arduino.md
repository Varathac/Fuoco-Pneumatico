Arduino Pinout Document:
https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf
The link above guides you to Arduino's documentation on what each pin on the board does.

![Arduino R3 pin layout](https://github.com/Varathac/Fuoco-Pneumatico/assets/142264466/3dfd6110-0fbc-45b8-ae2e-af7fe794facf)
(Arduino Uno Rev3 Pin Layout)

![LCD1 screen](https://github.com/Varathac/Fuoco-Pneumatico/assets/142264466/fe967372-4e59-4042-878a-3127444baa95)
![LCD2 screen](https://github.com/Varathac/Fuoco-Pneumatico/assets/142264466/e3ddf8ec-0b30-414b-a297-c3f450899510)

(LCD Screen Pin Layout)

Pin Connections From Arduino to LCD Screen (A: Arduino | L: LCDScreen)
-
- A: 5v -> L: VCC
- A: GND -> L: GND
- A: A0 -> L: LCD_CS
- A: A1 -> L: LCD_RST
- A: A2 -> L: LCD_RS
- A: 11 -> L: SDI(MOSI)
- A: 12 -> L: SDO(MISO)
- A: 13 -> L: SCK
- A: 2 -> L: LED

<hr>
For my specific display which uses an ST7796U touch interface. The drivers it uses are Adafruit_ST7796S_kbv, Adafruit_GFX.h, and SPI.h.
Other screens may require different drivers to make it work and different boards you use will require a different library.

There are Libraries made already in the Arduino Sketch where you will be uploading and will be doing most of your programming.
To find the Libraries go to the top right -> Manage Libraries -> (Then type the name of the Library you want to add)
