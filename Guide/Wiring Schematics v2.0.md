Arduino Pinout Document:

(https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf)

The link above guides you to Arduino's documentation on what each pin on the board does.

![Arduino Nano A000005](https://raw.githubusercontent.com/Varathac/Fuoco-Pneumatico/main/Images/Nano_A000005.png)
(Arduino Nano A000005 Pin Layout)

![LCD1 screen](https://github.com/Varathac/Fuoco-Pneumatico/assets/142264466/fe967372-4e59-4042-878a-3127444baa95)
![LCD2 screen](https://github.com/Varathac/Fuoco-Pneumatico/assets/142264466/e3ddf8ec-0b30-414b-a297-c3f450899510)

(LCD Screen Pin Layout)

(We will be using the Custom Wire to connect them)

Pin Connections From Arduino to LCD Screen (A: Arduino | L: LCDScreen)
-
TFT Label	Arduino Nano Pin	Wire Color	Note
- VCC	- 5V	- Display power
- GND	- GND	- Common ground
- LCD_CS	- D10	- Chip Select
- LCD_RS / DC	- D9	- Data/Command
- LCD_RST	- D8 - Hardware reset
- SDI (MOSI)	- D11	- Arduino → Display data
- SCK	SCK - D13	- SPI clock
- SDO (MISO)	- D12	- Display → Arduino read
- LED (Backlight)	- D2	- Controlled backlight enable

<hr>
You can pin the touch screen capabilities for the LCD to the D pins on the Arduino and define it in the code but in our application
we will not be using it.


For my specific display which uses an ST7796U touch interface. The drivers it uses are Adafruit_ST7796S_kbv, Adafruit_GFX.h, and SPI.h.
Other screens may require different drivers to make it work and different boards you use will require a different library.

<hr>

Sensors to Arduino NANO

IR Sensor          |        Nano

- SCL(WHITE/BLUE)            A5
- SDA (WHITE)                A4
