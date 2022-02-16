#include <Arduino.h>
#include "PMS.h"
#include <Wire.h>

PMS pms(Wire);
PMS::DATA data;

void setup()
{
    Wire.begin();
    Serial.begin(9600);
    pms.wakeUp();
    Serial.println("Våkner opp :)");
    delay(30000);
}

void loop()
{
    delay(1000);
    if (pms.readUntil(data))
    {
        Serial.print("PM 1.0 (ug/m3): ");
        Serial.println(data.PM_AE_UG_1_0);

        Serial.print("PM 2.5 (ug/m3): ");
        Serial.println(data.PM_AE_UG_2_5);

        Serial.print("PM 10.0 (ug/m3): ");
        Serial.println(data.PM_AE_UG_10_0);
    }
}