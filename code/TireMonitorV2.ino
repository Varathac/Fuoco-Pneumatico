#include <Adafruit_GFX.h>
#include <FlickerFreePrint.h>
#include <SPI.h>
#include "Adafruit_ST7796S_kbv.h"
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

// MLX90614 sensor addresses
#define IR_FRONT 0x0C
#define IR_REAR  0x5A

// TFT pins
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8

// Two MLX sensors
Adafruit_MLX90614 mlxFront = Adafruit_MLX90614();
Adafruit_MLX90614 mlxRear  = Adafruit_MLX90614();

// TFT and FlickerFreePrint
Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);
FlickerFreePrint<Adafruit_ST7796S_kbv> DataFront(&tft, ST7796S_WHITE, ST7796S_BLACK);
FlickerFreePrint<Adafruit_ST7796S_kbv> DataRear(&tft, ST7796S_WHITE, ST7796S_BLACK);
FlickerFreePrint<Adafruit_ST7796S_kbv> DataAmbient(&tft, ST7796S_WHITE, ST7796S_BLACK);

void setup() {
  Serial.begin(9600);
  Serial.println("Tire Sensor Start");

  // Initialize both sensors
  if (!mlxFront.begin(IR_FRONT)) {
    Serial.println("Error connecting to front sensor!");
    while (1);
  }
  if (!mlxRear.begin(IR_REAR)) {
    Serial.println("Error connecting to rear sensor!");
    while (1);
  }

  tft.begin();
  tft.setFont(&FreeMonoBold12pt7b);
  tft.setRotation(3);
  tft.fillScreen(ST7796S_WHITE);
}

void loop() {
  tft.setRotation(3);

  displayTempFront();
  displayTempRear();
  displayLabels();
  displayAmbient();
  displayTempColor();

  delay(100);
}

// Display front tire temperature
void displayTempFront() {
  tft.setCursor(250, 50);
  tft.setTextSize(2);
  DataFront.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  float temp = mlxFront.readObjectTempF();
  DataFront.print(round(temp));
}

// Display rear tire temperature
void displayTempRear() {
  tft.setCursor(250, 200);
  tft.setTextSize(2);
  DataRear.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  float temp = mlxRear.readObjectTempF();
  DataRear.print(round(temp));
}

// Display "Front" and "Rear" labels
void displayLabels() {
  tft.setCursor(50, 50);
  tft.setTextSize(2);
  DataFront.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Front: ");
  tft.cp437(true); tft.write(167);

  tft.setCursor(325, 50);
  tft.setTextSize(2);
  DataFront.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("F");
  tft.cp437(true); tft.write(167);

  tft.setCursor(50, 200);
  tft.setTextSize(2);
  DataRear.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Rear: ");
  tft.cp437(true); tft.write(167);

  tft.setCursor(325, 200);
  tft.setTextSize(2);
  DataRear.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("F");
  tft.cp437(true); tft.write(167);
}

// Display ambient temperature from front sensor
void displayAmbient() {
 tft.setCursor(50, 290);
  tft.setTextSize(1);
  DataAmbient.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Ambient Temp: ");
  float ambient = mlxFront.readAmbientTempF();
  DataAmbient.print(round(ambient));
}

// Fill right-side rectangle red if both temps > 90F, green otherwise
void displayTempColor() {
  float tempFront = mlxFront.readObjectTempF();
  float tempRear  = mlxRear.readObjectTempF();

  if ((tempFront > 90) && (tempRear > 90)) {
    tft.fillRect(390, 0, 130, 320, 0xF81F); // red
  } else {
    tft.fillRect(390, 0, 130, 320, 0x07FF); // green
  }
}

