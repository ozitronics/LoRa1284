/******************************************************************************
 LoRa1284 demo code - Sender
 Requires a LoRa module and antenna fitted to the LoRa1284 board

 Read potentiometer via analog input and transmit value via LoRa to receiver.

 The receiver uses the value to vary the brightness of the onboard LED

 Each transmitted value is also sent via serial port and can be viewed using
 the Arduino IDE serial monitor (9600 baud).
 *****************************************************************************/

/*****************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

/*****************************************************************************/
// LoRa library
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

const int pot = A7;

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
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255);

  if (val != oldval) {
    oldval = val;
    Serial.println(val);
    LoRa.beginPacket();
    LoRa.println(val);
    LoRa.endPacket();
  }
  delay(50);
}
/*****************************************************************************/
