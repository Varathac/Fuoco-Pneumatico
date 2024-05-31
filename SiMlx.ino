#include <Adafruit_GFX.h>
#include <FlickerFreePrint.h>
#include <SPI.h>
#include "Adafruit_ST7796S_kbv.h"
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//IR sensor Address
#define IR1 0x0C
#define IR2 0x5A

#define TFT_CS A0
#define TFT_DC A2
#define TFT_RST A1


Adafruit_MLX90614 mlx;
Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);
FlickerFreePrint<Adafruit_ST7796S_kbv> Data1(&tft, ST7796S_WHITE, ST7796S_BLACK);
FlickerFreePrint<Adafruit_ST7796S_kbv> Data2(&tft, ST7796S_WHITE, ST7796S_BLACK);
FlickerFreePrint<Adafruit_ST7796S_kbv> Data3(&tft, ST7796S_WHITE, ST7796S_BLACK);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  

  mlx.begin(); 
  tft.begin();
  tft.setFont(&FreeMonoBold12pt7b);
  tft.setRotation(3);
  tft.fillScreen(ST7796S_WHITE);
}

void loop() {
  tft.setRotation(3);
  tempDisplay1();
  tempDisplay2();
  tempText();
  tempText2();
  ambientTemp();
  tempColor();
}
unsigned long tempDisplay1(){
  tft.setCursor(250, 50);
  tft.setTextSize(2);
  if (mlx.begin() == 1){
    Data1.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
    unsigned long start = micros();
    mlx.AddrSet(IR1); 
    Data1.print(round(mlx.readObjectTempF()));
    mlx.temp1 = mlx.readObjectTempF();
    return micros() - start;
  }
}
unsigned long tempDisplay2(){
  tft.setCursor(250, 200);
  tft.setTextSize(2);
  if (mlx.begin() == 1){
    Data3.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
    unsigned long start = micros();
    mlx.AddrSet(IR2); 
    Data3.print(round(mlx.readObjectTempF()));
    mlx.temp2 = mlx.readObjectTempF();
  }
}

unsigned long tempText(){
  unsigned long start = micros();
  tft.setCursor(50, 50);
  tft.setTextSize(2);
  Data1.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Front ");
  tft.cp437(true);
  tft.write(167);
}
unsigned long tempText2(){
  unsigned long start = micros();
  tft.setCursor(50, 200);
  tft.setTextSize(2);
  Data1.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Rear ");
  tft.cp437(true);
  tft.write(167);
}

unsigned long ambientTemp(){
  tft.setCursor(50, 290);
  tft.setTextSize(1);
  Data2.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
  tft.print("Ambient Temp ");
  if (mlx.begin()){
    Data2.setTextColor(ST7796S_BLACK, ST7796S_WHITE);
    unsigned long start = micros();
    Data2.print(round(mlx.readAmbientTempF()));
   }
}

//0x07FF - red
//0xF81F - green
unsigned long tempColor(){
  if ((mlx.temp2 > 90) && (mlx.temp1 > 90)){
    tft.fillRect(390, 0, 130, 320, 0xF81F);
  } else {
    tft.fillRect(390, 0, 130, 320, 0x07FF);
  }
  
}