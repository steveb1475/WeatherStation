Files for the electrical enclosure.

The enclosure houses the ESP8266, 18650 battery, power management module and the 5v boost converter. It has holes sized for PG7 cable glands for connection to the other components and access to the USB port on the ESP. __The current design has mounting standoffs for a NODE-MCU Amica ESP8266 module!__ I switched to the WEMOS D1 mini due to it's smaller footprint and the fact that I mangled my original board after soldering and desoldering the connection pins too many times. I realized that I needed some space for 5vdc, 3.3vdc and I2c buses, so I decided to mount the ESP to a prototyping PCB and use header pins for the connections. The enclosure needs to be modified for the new PCB.

__Update__
There are two different designs. I left the files for my first enclosure for the NodeMCU Amica board. The second design has standoffs for a 40mm X 60mm proto board. The 6040 has a few other modifications such as mounting tabs for the 18650 battery, an extra PG7 hole for usb port access on the side and a hole for a power switch on the bottom. I won't be using or updating the first design but left it in case anyone wants to use it. The NodeMCU Amica board should also fit on the same proto board with enough extra rows of holes for a header bus for power and I2c. I recommend printing the lid with %100 infill.

Todo:
- [x] Modify enclosure for WEMOS D1 mini
- [ ] Improve weather proofing
- [ ] Incorporate mounting clamp into design
