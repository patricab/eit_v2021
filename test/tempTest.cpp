#include "DHT.h"
#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // DHT 11

// Then define the DHT parameter to Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);
// Note that older versions of this library took an optional third parameter to tweak the timings for faster processors. This parameter is no longer needed as the current DHT reading algorithm adjusts itself to work on faster procs.

void setup()
{
    Serial.begin(9600);
    Serial.println(F("DHT11 test!"));
    dht.begin();
}

void loop()
{
    // Reading temperature or humidity takes about 250 milliseconds! Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor).
    float h = dht.readHumidity(); // read humidity

    // Read temperature as Celsius(the default)
    float t = dht.readTemperature(); // read temperature

    // Read temperature as Fahrenheit(isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early(to try again).
    if (isnan(h) || isnan(t) || isnan(f))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // Compute heat index in Fahrenheit(the default)
    float hif = dht.computeHeatIndex(f, h);

    // Compute heat index in Celsius(isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    // Print the measured readings on the Serial Monitor.
    Serial.print(F(" Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
}