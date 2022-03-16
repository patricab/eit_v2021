#include <Arduino.h>
#include <MKRNB.h>

// modem verification object
NBModem modem;

// IMEI variable
String IMEI = "";

void setup() {

  // initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  // start modem test (reset and check response)
}

void modem_test() {
  // get modem IMEI
  Serial.print("Checking IMEI...");
  IMEI = modem.getIMEI();

  // check IMEI response
  if (IMEI != NULL) {
    // show IMEI in serial monitor
    Serial.println("Modem's IMEI: " + IMEI);

    // reset modem to check booting:
    Serial.print("Resetting modem...");

    modem.begin();

    // get and check IMEI one more time
    if (modem.getIMEI() != NULL) {
      Serial.println("Modem is functioning properly");
    } else {
      Serial.println("Error: getIMEI() failed after modem.begin()");
    }
    } else {
      Serial.println("Error: Could not get IMEI");
    }
}