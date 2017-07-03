// Sega Megadrive switch Mod using Arduino nano to control switching and OLED display to show region select
// plans to include a playtime counter to follow
// LED1 will switch region
// LED2 will switch 50/60 HZ display


//setup pin 2 and 3 as outputs, labled LED as was tested with LEDS before using transducers
//setup A0 as button in, 5v to switch resistor to ground and lead to A0 between switch and resistor
const byte Button = A0;
byte ButtonState;
byte lastState = LOW;
byte count = 0;
byte last = 0;
int Andy = 0;
const int LED1 = 2;
const int LED2 = 3;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(Button, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  int stateLED1 = LOW;
  int stateLED2 = LOW;
}

void loop() {
  ButtonState = digitalRead(Button);
  
  //Serial.print("The Score is: ");
  //Serial.println(count);
  //left in for button testing
  
  if(ButtonState && ButtonState != lastState)  // button latch, no debounce needed!!!!!
  {
    if(count < 2) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      count += 1; // same as count = count + 1;
    else
      count = 0;
   // Serial.print("The Score is: ");
   // Serial.println(count);
   // again for testing
   
  } 
  {
    if(last < 2) // This will check to see if the count is within a range of 0 - 2, over that, it will reset count back to 0.
      last += 1; // same as count = count + 1;
    else
      count = 0;
   // Serial.print("The Score is: ");
   // Serial.println(count);
   // again for testing
   
  } 
  lastState = ButtonState;

  if    (count == 0)
{ 
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);
  
   
}
else if(count == 1)
{ 
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, LOW);
   if (Andy == 1 && last == 0)
   {
   Serial.println("USA NTSC");}
}
else if(count == 2)
{
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, HIGH);
   Serial.println("JAP NTSC ");

}
if  
// 
}
