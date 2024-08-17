#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define DHTPIN 2      // Digital pin connected to the DHT21 sensor's DATA pin
#define DHTTYPE DHT21 // Define the type of DHT sensor (DHT21 in this case)

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8

DHT dht(DHTPIN, DHTTYPE);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud
  dht.begin();

  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.println("Test Message");
}

void loop() {
  float humidity = 10.0; //dht.readHumidity();
  float temperatureC = 25.0; //dht.readTemperature(); // Read temperature in Celsius
  float temperatureF = 75.0; //dht.readTemperature(true); // Read temperature in Fahrenheit

  // If read fails
  // if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   return;
  // }

  // Print the results to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  delay(2000);
}