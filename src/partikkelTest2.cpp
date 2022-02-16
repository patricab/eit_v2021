#include "PMS.h"
#include "SoftwareSerial.h"
SoftwareSerial Serial1(2, 3); // RX, TX
PMS pms(Serial1);
PMS::DATA data;

void setup()
{
    Serial1.begin(9600);
    delay(4000);
}

void loop()
{
    if (pms.read(data))
    {
        Serial1.println("Dust Concentration");
        Serial1.println("PM1.0 :" + String(data.PM_AE_UG_1_0) + "(ug/m3)");
        Serial1.println("PM2.5 :" + String(data.PM_AE_UG_2_5) + "(ug/m3)");
        Serial1.println("PM10  :" + String(data.PM_AE_UG_10_0) + "(ug/m3)");
        delay(1000);
    }
}