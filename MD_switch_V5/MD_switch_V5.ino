// Sega Megadrive switch Mod using Arduino nano to control switching and OLED display to show region select
// plans to control overclock soon
// JP1 will switch region
// JP3 will switch 50/60 HZ display
//

//setup pin 2 and 3 as outputs, labled LED as was tested with LEDS before using transducers
//setup A0 as button in, 5v to switch resistor to ground and lead to A0 between switch and resistor

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
byte ButtonState;
byte lastState = LOW;
byte count = 0;
const byte Button = A0;
const byte ButtonHZ = A1;
const byte ButtonClock = A2;
const int JP1 = 2;
const int JP3 = 3;
const int JPReset = 4;
// Depending if i use relay or transitsor
const int Mhz7 = 5;
const int Mhz10 = 6;

void setup() {
  
  
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
  pinMode(Button, INPUT);
  pinMode(JP1, OUTPUT);
  pinMode(JP3, OUTPUT);
  int stateJP1 = LOW;
  int stateJP3 = LOW;
}

void loop() {
  //delay(3000);
  ButtonState = digitalRead(Button);
  
  if(ButtonState && ButtonState != lastState)  // button latch, no debounce needed!!!!!
  {
    if(count < 2) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      count += 1; // same as count = count + 1;
    else
      count = 0;

  } 
  lastState = ButtonState;

  if    (count == 0)
{ 
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, HIGH);
   //display.fillScreen(BLACK);
   display.setTextColor(BLACK);
   display.setCursor(0,10);
   display.print("USA NTSC ");
   display.setCursor(0,20);
   display.print("JAP NTSC ");
   display.setTextColor(WHITE);
   display.setCursor(0,0);
   display.print("U.K PAL ");
   

}
else if(count == 1)
{ 
   digitalWrite(JP1, LOW);
   digitalWrite(JP3, LOW);
   //display.fillScreen(BLACK);
   //display.fillRect(0,0,5,200,BLACK);
   display.setTextColor(BLACK);
   display.setCursor(0,0);
   display.print("U.K PAL ");
   display.setCursor(0,20);
   display.print("JAP NTSC ");
   display.setTextColor(WHITE);
   display.setCursor(0,10);
   display.print("USA NTSC ");
   
}
else if(count == 2)
{
   digitalWrite(JP1, HIGH);
   digitalWrite(JP3, LOW);
   //display.fillScreen(BLACK);
   //display.fillRect(0,10,5,200,BLACK);
   display.setTextColor(BLACK);
   display.setCursor(0,0);
   display.print("U.K PAL ");
   display.setCursor(0,10);
   display.print("USA NTSC ");
   display.setTextColor(WHITE);
   display.setCursor(0,20);
   display.print("JAP NTSC ");

}

}
