Files for the electrical enclosure.

The enclosure houses the ESP8266, 18650 battery, power management module and the 5v boost converter. It has holes sized for PG7 cable glands for connection to the other components and access to the USB port on the ESP. __The current design has mounting standoffs for a NODE-MCU Amica ESP8266 module!__ I switched to the WEMOS D1 mini due to it's smaller footprint and the fact that I mangled my original board after soldering and desoldering the connection pins too many times. I realized that I needed some space for 5vdc, 3.3vdc and I2c busses, so I decided to mount the ESP to a prototyping PCB and use header pins for the connections. The enclosure needs to be modified for the new PCB.

Todo:
- [ ] Modify enclosure for WEMOS D1 mini
- [ ] Improve weather proofing
