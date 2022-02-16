#include <Arduino.h>
#include "PMS.h"
#include <Wire.h>

PMS pms(Wire);
PMS::DATA data;

void setup()
{
  Wire.begin();   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
  pms.wakeUp();
}

void loop()
{
  Serial.println(pms.read(data));
  delay(1000);

  if (pms.read(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }

  // Do other stuff...
}