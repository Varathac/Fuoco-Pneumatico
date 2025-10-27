Libraries and Hardware Configuration Overview:
SPI TFT Display
<hr>
Use the following library for the ST7796 SPI TFT display module:

-  Repository: https://github.com/prenticedavid/Adafruit_ST7796S_kbv

-  Since the display communicates over SPI, it does not interfere with the I²C bus.
<hr>

Displaying the information:
<hr>
I use another library to prevent the whole screen from refreshing when new information is recieved from the sensor.

- Repository: https://github.com/KrisKasprzak/FlickerFreePrint

- Just import the .ZIP files to the arduino and follow the written guide
  
<hr>

Dual MLX90614 Infrared Sensors (I²C):
<hr>
Both MLX90614 sensors share the same SDA and SCL lines. To prevent address conflicts:

- The I²C address of at least one sensor must be changed

- Recommended library for modifying sensor addresses:

    - Repository: https://github.com/sparkfun/SparkFun_MLX90614_Arduino_Library

        - Navigate to: examples/Example4_Change_i2c_Address

        - Upload and follow the code instructions to set a new address

Once addressed uniquely, both sensors can operate on the same I²C pins without issue.
<hr>

Important Display Selection Note:
<hr>

If choosing a display that uses I²C rather than SPI:

  - Ensure the microcontroller supports multiple I²C buses
  or

  - Avoid I²C displays entirely in multi-sensor projects to prevent bus conflicts

Using an SPI TFT display, as specified, completely avoids this problem.
