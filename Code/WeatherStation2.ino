#include <ESP8266WiFi.h>
#include <BME280.h>

const char* ssid = "barneyzoo";
const char* password = "14a28b14a2";

/* ==== Defines ==== */
#define SERIAL_BAUD 115200

/* ==== Global Variables ==== */
/* BME280 Variables */
BME280 bme;                   // Default : forced mode, standby time = 1000 ms
                              // Oversampling = pressure ×1, temperature ×1, humidity ×1, filter off,
bool metric = false;
float temp(NAN), hum(NAN), pres(NAN);
float altitude(NAN);
float dewPoint(NAN);
  
WiFiServer server(80);


void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());

  while(!bme.begin()){
  Serial.println("Could not find BME280 sensor!");
  delay(1000);
  }
}


// prepare a web page to be send to a client (web browser)
String prepareHtmlPage()
{
  String htmlPage = 
     String("HTTP/1.1 200 OK\r\n") +
            "Content-Type: text/html\r\n" +
            "Connection: close\r\n" +  // the connection will be closed after completion of the response
            "Refresh: 5\r\n" +  // refresh the page automatically every 5 sec
            "\r\n" +
            "<!DOCTYPE HTML>" +
            "<html>" +
            "Temperature:  " + String(temp) +
            "   Humidity:  " + String(hum) +
            "   Pressure:  " + String(pres) +
            "   Altitude:  " + String(altitude) +
            "   Dew point:  " + String(dewPoint) +
            "</html>" +
            "\r\n";
  return htmlPage;
}


void loop()
{
  /* From example BME280_Test */
   printBME280Data(&Serial);
   printBME280CalculatedData(&Serial);
   delay(500);
   
  WiFiClient client = server.available(); 
  // wait for a client (web browser) to connect
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      // read line by line what the client (web browser) is requesting
      if (client.available())
      {
        String line = client.readStringUntil('\r');
        Serial.print(line);
        // wait for end of client's request, that is marked with an empty line
        if (line.length() == 1 && line[0] == '\n')
        {
          client.println(prepareHtmlPage());
          break;
        }
      }
    }
    delay(1); // give the web browser time to receive the data

    // close the connection:
    client.stop();
    Serial.println("[Client disonnected]");
  }
}

/* From example BME280_Test */
void printBME280Data(Stream* client){
   uint8_t pressureUnit(2);   // unit: B000 = Pa, B001 = hPa, B010 = Hg, B011 = atm, B100 = bar, B101 = torr, B110 = N/m^2, B111 = psi
  bme.ReadData(pres, temp, hum, metric, pressureUnit);                // Parameters: (float& pressure, float& temp, float& humidity, bool hPa = true, bool celsius = false)
  /* Alternatives to ReadData():
    float ReadTemperature(bool celsius = false);
    float ReadPressure(uint8_t unit = 0);
    float ReadHumidity();

    Keep in mind the temperature is used for humidity and
    pressure calculations. So it is more effcient to read
    temperature, humidity and pressure all together.
   */
  client->print("Temp: ");
  client->print(temp);
  client->print("°"+ String(metric ? 'C' :'F'));
  client->print("\t\tHumidity: ");
  client->print(hum);
  client->print("% RH");
  client->print("\t\tPressure: ");
  client->print(pres);
  client->print(" inHg");
}

/* From example BME280_Test */
void printBME280CalculatedData(Stream* client){
  altitude = bme.CalculateAltitude(metric);
  dewPoint = bme.CalculateDewPoint(metric);
  client->print("\t\tAltitude: ");
  client->print(altitude);
  client->print((metric ? "m" : "ft"));
  client->print("\t\tDew point: ");
  client->print(dewPoint);
  client->println("°"+ String(metric ? 'C' :'F'));
}
