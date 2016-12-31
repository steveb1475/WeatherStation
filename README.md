# Backyard 3d printed ESP8266 Weather Station


The goal of this project is to create a backyard weather station. The brains of the weather station will be an ESP8266 programmed with the Arduino IDE that will collect and periodically send weather data to a MySQL database on a local LAMP server. Data will be accessible from a webpage.

Weather data to be collected by the weather station:

  Temperature
  Humidity
  Barometric pressure
  Wind speed
  Wind direction
  
I used a ESP8266 WEMOS D1 mini which is available for about $4 on Banggood, Ebay, Etc. An I2c connected BME280 sensor housed in a 3d printed Stevenson screen provides temperature, humidity and barometric pressure.  Wind speed is aquired from a 3d printed anemometer with plastic Christmas ornament half cups.  Wind direction is provided by a 3d printed weather vane with a I2c connected HMC5883L magnetometer mounted in the vane. 

Since the weather station is mounted away from my house in the backyard it is solar powered with a 18650 lithium-ion battery, power management module and 5v boost converter. All of the parts are designed to be clamped onto a single 1 1/2 inch diameter closet rod that I had leftover from another project and mounted to my chicken coop.
