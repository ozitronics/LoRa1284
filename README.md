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

There are two options for powering the LoRa1284 board - via VIN or via the 3V3 pins.

**Powering via VIN**

- Input voltage range = 5V - 16V. **Note:** VIN is protected against reverse polarity
- VIN is converted to 3.3v by an onboard MCP1703 voltage regulator with a maximum output current of 250mA
- The 3.3v output powers both the ATmegta1284 and the LoRa module and is also available on the 3V3 pins for powering external devices. However the maximum current available on these pins depends on whether a LoRa module is installed or not.
- The active operating current of the ATmega1284 chip itself is approx 5mA
- The operating current of the LoRa module can be as high as 120mA when transmitting
- Therefore the current available from the 3V3 pins will be either 245mA or 125mA respectively

**Powering via 3V3 pins**

**Why would you want to?** For running on batteries such as LI-ION or LI-PO. However there are limitations
as described below.

* Input voltage range = 1.8V - 5.5V

The 3V3 pins are direct connected to the ATmega1284 Vcc pins and that is the operating voltage range of the ATmega1284 chip itself

- **Do not exceed 3.7V** if a LoRa module is installed (maximum operating voltage)

**Low power operation**

For low power operation the onboard power and blink LEDs can be disabled by removing solder jumpers SJ1 and SJ2
