#include <Arduino.h>
#include "PMS.h"
#include <Wire.h>

PMS pms(Wire);
PMS::DATA data;

void setup()
{
    Wire.begin();       // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
    Serial.begin(9600); // GPIO2 (D4 pin on ESP-12E Development Board)
    String res = "Information:\n";
    res += "Baud rate: " + pms.BAUD_RATE + "\n";
    Serial.println(res);
    pms.wakeUp();
    pms.activeMode();
}

void loop()
{
    pms.wakeUp();
    if (pms.read(data))
    {
<<<<<<< HEAD:test/sensor.cpp
        delay(1000);
        Serial1.print("PM 2.5 (ug/m3): ");
        Serial1.println(data.PM_AE_UG_2_5);

        Serial1.println();
=======
        Serial.print("PM 2.5 (ug/m3): ");
        Serial.println(data.PM_AE_UG_2_5);
>>>>>>> 2513c2d... Sensor test Martin:sensor.cpp
    }
}