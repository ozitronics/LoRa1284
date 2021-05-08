# LoRa1284
LoRa1284 - an enhanced Arduino development board with LoRa capability

LoRa1284 is an Arduino compatible board using an ATmega1284P. It has provision for an onboard LoRa wireless module making it suitable for remote sensing and control.

**Features**

- ATmega1284p MCU @ 3.3v
- ATmega1284p has 128KB Flash, 16KB SRAM and 4KB EEPROM
- All 32 I/O pins brought out to pin headers
- Breadboard compatible (pin header rows @ 0.9" spacing)
- Power and "blink" LEDs (can be disabled via solder jumpers for low power operation)
- Connector for OLED display or other I2C module
- FTDI connector for serial programming
- MCP1703 250mA 16V low dropout voltage regulator
- Input voltage reverse polarity protection
- Small footprint: 51 x 25.5 mm (2" x 1")

**Why LoRa1284?**

For a while now I have been making projects using wireless comms for remote
sensing and control. In particular I have been using LoRa modules for their
reliability and long operating distance.

For many projects an ATmega328 is more than adequate but once you start adding
libraries for LoRa, OLEDs, etc memory and I/O pins start to run out. This is
where the ATmega1284 comes in. Not only does it have extra flash, SRAM, EEPROM
and I/O pins but it is Arduino compatible. Existing libraries just work!!!

**Package Contents**

Each LoRa1284 comes in an anti-static bag that includes:

- 1 x LoRa1284 module
- 2 x 20-pin male headers
- 1 x 6-pin female socket
- 1 x 4-pin female socket
- 1 x pinout card

**How to program?**

You need to add board support in the Arduino IDE.

Go to [https://github.com/mcudude/MightyCore](https://github.com/mcudude/MightyCore) and
follow the "Boards Manager Installion" link.

For convenience the following is copied from the MightyCore link:

**Boards Manager Installation**

This installation method requires Arduino IDE version 1.6.4 or greater.

- Open the Arduino IDE.
- Open the File > Preferences menu item.
- Enter the following URL in Additional Boards Manager URLs:

  https://mcudude.github.io/MightyCore/package_MCUdude_MightyCore_index.json

- Separate the URLs using a comma ( , ) if you have more than one URL
- Open the Tools > Board > Boards Manager... menu item.
- Wait for the platform indexes to finish downloading.
- Scroll down until you see the MightyCore entry and click on it.
- Click Install.
- After installation is complete close the Boards Manager window.

**Powering the LoRa1284 module**

* Input voltage range (VIN) = 5 - 16.7 volts
  Note: VIN protected against reverse polarity
* VIN is converted to 3.3v by an onboard MCP1703 voltage regulator with a
  maximum output current of 250mA
* The 3.3v output powers both the MCU and the LoRa module and is also available
  on two (2) module pins for powering external circuits
