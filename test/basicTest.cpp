#include <Arduino.h>
#include "PMS.h"
#include <Wire.h>

PMS pms(Wire);
PMS::DATA data;

void setup()
{
    // Wire.begin();       // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
    Serial.begin(9600); // GPIO2 (D4 pin on ESP-12E Development Board)
    pms.wakeUp();
    pms.activeMode();
}

void loop()
{
    delay(10000);
    bool noe = pms.read(data);
    Serial.println(noe);
    if (noe)
    {
        Serial.print("PM 2.5 (ug/m3): ");
        Serial.println(data.PM_AE_UG_2_5);
    }
}