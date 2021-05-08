/******************************************************************************
 LoRa1284 demo code - OLED display
 Requires an OLED module plugged into OLED/I2C socket
 OLED module size = 128 x 64 pixels
 Note: Check that VCC and GND pins match!

 Displays running "millis" count on OLED display
 Blinks onboard LED as well

 Arduino IDE setup
 -----------------
 Board    : ATmega1284
 Clock    : External 8MHz (change if different for your board)
 Variant  : 1284P
 Pinout   : Standard pinout

 NOTE:
 There are many OLED Arduino libraries available.

 The library used in this sketch is a character only library ie. no graphics.

 It's main advantage is that it uses just a few bytes of RAM and program
 storage space, although this is not really a problem with an ATmega1284 MCU.
 *****************************************************************************/

/*****************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

/*****************************************************************************/
// OLED library by Bill Greiman
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C        // OLED address
SSD1306AsciiWire oled;          // create OLED object

/*****************************************************************************/
// I/O pin definitions
#define LED_BUILTIN 7           // LoRa1284 onboard LED

/*****************************************************************************/

/******************************************************************************/
void setup()
{
  /** configure I/O pins */
  pinMode(LED_BUILTIN, OUTPUT);

  /*************************
  setup and start the OLED
  **************************/
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(fixed_bold10x15);        // select font
  oled.setScrollMode(SCROLL_MODE_AUTO);
  //oled.displayRemap(true);            // rotate display 180 degrees

  oled.clear();
  oled.println("LoRa1284");
  oled.println("OLED demo");
  oled.println();
}
/*****************************************************************************/

/*****************************************************************************/
void loop()
{
  oled.setCursor(0, 6);               // cursor position = last line of display
  oled.print(millis());               // print current "millis" count
  oled.clearToEOL();                  // clear rest of line
                                      // required if using proportional fonts
  digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on
  delay(500);                         // wait a bit...
  digitalWrite(LED_BUILTIN, LOW);     // turn the LED off
  delay(500);
}
/******************************************************************************/
