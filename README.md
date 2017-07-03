Sega Megadrive switch Mod with OLED display

My little project using an Arduino nano to control switching and an OLED display to show information.

The selections will be push switch controlled and loop around for each mode. The following selections are currently being utilised:-

Select region language
Select Display Frequency (PAL/NTSC) 50HZ or 60 HZ respectivley
Selcet clock speed of 7Mhz (standard) and 10Mhz (Overclock)


/// below information as a reminder for me!

JP1 will switch region
JP3 will switch 50/60 HZ display


setup pin 2 and 3 as outputs, labled LED as was tested with LEDS before using transducers
setup A0 as button in, 5v to switch resistor to ground and lead to A0 between switch and resistor
