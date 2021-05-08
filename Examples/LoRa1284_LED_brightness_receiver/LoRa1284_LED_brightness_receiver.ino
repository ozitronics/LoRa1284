/******************************************************************************
 LoRa1284 demo code - Receiver
 Requires a LoRa module and matching antenna fitted to the LoRa1284 board
 
 Receive data value via LoRa and use it to vary LED brightness using PWM
 
 Each received value is also sent via serial port and can be viewed using
 the Arduino IDE serial monitor
 
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
int val = 0;                      // default = 1/2 brightness

/******************************************************************************
 I/O pin definitions and program defines                                     */
const int led = 12;               // LED connected to this pin!

/*****************************************************************************/
void setup()
{
  /** configure I/O pins */
  pinMode(led,      OUTPUT);
  pinMode(LORA_CS,  OUTPUT);
  pinMode(LORA_RST, OUTPUT);
  pinMode(LORA_IRQ, INPUT);

  Serial.begin(9600);
  while (!Serial);

  /****************************************************************************
  setup and start LoRa module
  if it doesn't start print error message
  ****************************************************************************/
  LoRa.setPins(LORA_CS, LORA_RST, LORA_IRQ);    // define LoRa1284 pin usage

  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) {                     // 433MHz
                                                // for 868MHZ use "868E6"
                                                // for 915MHz use "915E6"
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
/*****************************************************************************/

/*****************************************************************************/
void loop()
{
  if (LoRa.parsePacket()) {     // if received a packet...
    if (LoRa.available()) {     //  and if data available...
      val = LoRa.parseInt();    //  read data variable from received packet
      Serial.println(val);      //  print to serial port
      analogWrite(led, val);    //  set new LED brightness
    }
  }
}
/*****************************************************************************/
