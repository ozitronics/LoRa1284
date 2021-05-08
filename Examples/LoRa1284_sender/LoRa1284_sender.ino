/******************************************************************************
 LoRa1284 demo code - Sender
 Requires a LoRa module and matching antenna fitted to the LoRa1284 board

 Read voltage from a potentiometer and transmit the value to a receiver
 The receiver uses the value to vary the brightness of an LED

 Each transmitted value is also sent via serial port and can be viewed using
 the Arduino IDE serial monitor (9600 baud)
 
 Arduino IDE setup
 -----------------
 Board    : ATmega1284
 Clock    : External 8MHz (change if different for your board)
 Variant  : 1284P
 Pinout   : Standard pinout
 
 *****************************************************************************/

/*****************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

/*****************************************************************************/
// LoRa library by Sandeep Mistry
#include <LoRa.h>

const int LORA_CS   = 4;          // LoRa chip select (SS)
const int LORA_RST  = 0;          // LoRa reset
const int LORA_IRQ  = 10;         // LoRa interrupt input

/*****************************************************************************/
// Global variables
int val, oldval;

/******************************************************************************
 I/O pin definitions and program defines                                     */
#define LED_BUILTIN 7           // LoRa1284 onboard LED

const int pot = A7;             // potentiometer connected to this pin

/*****************************************************************************/
void setup()
{
  /** configure I/O pins */
  pinMode(LED_BUILTIN,  OUTPUT);
  pinMode(pot,          INPUT);
  pinMode(LORA_CS,      OUTPUT);
  pinMode(LORA_RST,     OUTPUT);
  pinMode(LORA_IRQ,     INPUT);

  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Sender");

  /****************************************************************************
  setup and start LoRa module
  if it doesn't start print error message
  ****************************************************************************/
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);    // define LoRa1284 pin usage

  if (!LoRa.begin(433E6)) {                     // 433MHz
                                                // for 868MHZ use "868E6"
                                                // for 915MHz use "915E6"
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  oldval = -1;                                  // force initial send
}
/*****************************************************************************/

/*****************************************************************************/
void loop()
{
  val = analogRead(pot);            // read analog voltage from potentiometer
  val = map(val, 0, 1023, 0, 255);  // map value to range 0-255

  if (val != oldval) {              // if value has changed...
    oldval = val;                   //  save new value
    Serial.println(val);            //  send to serial port
    LoRa.beginPacket();             //  send new value as LoRa packet
    LoRa.println(val);
    LoRa.endPacket();
  }
  delay(50);
}
/*****************************************************************************/
