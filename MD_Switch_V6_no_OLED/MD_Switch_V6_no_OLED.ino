/// change test

// LCD SETUP
#define sclk 13
#define mosi 7
#define cs   10
#define rst  9
#define dc   8

// Color definitions
#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

// LIBs to include
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);  

float p = 3.1415926;
byte ButtonStateRegion;
byte ButtonStateClock;
byte ButtonStateLang;
byte lastStateRegion = LOW;
byte lastStateLang = LOW;
byte lastStateClock = LOW;
byte countRegion = 0;
byte countLang = 0;
byte countClock = 0;
const byte ButtonRegion = A0;
const byte ButtonLang = A1;
const byte ButtonClock = A2;
const int JP1 = 2;
const int JP3 = 3;
const int JPHalt = 4;
// Depending if i use relay or transitsor
const int Mhz7 = 5;
const int Mhz10 = 6;

// Region JP3 = PAL 50hz, NTSC 60hz
// Lang JP1 = USA, JAP, UK
// Clock = 7Mhz, 10Mhz  

void setup() {

  pinMode(ButtonRegion, INPUT);
  pinMode(JP1, OUTPUT);
  pinMode(JP3, OUTPUT);
  pinMode(JPHalt, OUTPUT);
  pinMode(Mhz7, OUTPUT);
  pinMode(Mhz10, OUTPUT);
  // pin13 to turn arduino nano light off
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  int stateMhz7 = HIGH;
  int stateJP1 = LOW;
  int stateJP3 = LOW;
  int stateJPHalt = LOW;
  
  display.begin();
  display.fillScreen(BLUE);
  delay(100);
  display.setTextColor(BLACK);
  display.setTextSize(2);
  display.setCursor(0,5);
  display.print("  SEGA ");
  delay(1000);
  display.fillScreen(BLACK);
  display.setTextSize(1);
  
}

void loop() {
  //delay(3000);
  ButtonStateRegion = digitalRead(ButtonRegion);
  
  if(ButtonStateRegion && ButtonStateRegion != lastStateRegion)  // button latch, no debounce needed!!!!!
  {
    if(countRegion < 1) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      countRegion += 1; // same as count = count + 1;
    else
      countRegion = 0;

  } 
  lastStateRegion = ButtonStateRegion;

  if    (countRegion == 0){
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, HIGH);}
   //UK
   

  
  else if(countRegion == 1){ 
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, LOW);}
   //USA
 
  ButtonStateLang = digitalRead(ButtonLang);
  
  if(ButtonStateLang && ButtonStateLang != lastStateLang)  // button latch, no debounce needed!!!!!
  {
    if(countLang < 2) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      countLang += 1; // same as count = count + 1;
    else
      countLang = 0;

  } 
  lastStateLang = ButtonStateLang;

  if    (countLang == 0){
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, HIGH);}
   //UK
   

  
  else if(countLang == 1){ 
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, LOW);}
   //USA
   
  else if(countLang == 2){
   digitalWrite(JP1, HIGH);
   digitalWrite(JP3, LOW);}
   //JAP
ButtonStateClock = digitalRead(ButtonClock);
  
  if(ButtonStateClock && ButtonStateClock != lastStateClock)  // button latch, no debounce needed!!!!!
  {
    if(countClock < 1) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      countClock += 1; // same as count = count + 1;
    else
      countClock = 0;

  } 
  lastStateClock = ButtonStateClock;

  if    (countClock == 0){
   digitalWrite(JPHalt, HIGH); 
   delay(1000);
   digitalWrite(Mhz7, HIGH);
   digitalWrite(Mhz10, LOW);
   delay(1000);
   digitalWrite(JPHalt, LOW);}
   //Standard
   

  
  else if(countClock == 1){ 
   digitalWrite(JPHalt, HIGH);
   delay(1000);
   digitalWrite(Mhz7, LOW);
   digitalWrite(Mhz10, HIGH);
   delay(1000);
   digitalWrite(JPHalt, LOW); }
   //Overclocked
}
