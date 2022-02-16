#include <Arduino.h>
#include <MKRNB.h>

NBModem modem;

// IMEI variable
String IMEI = "";

// baud rate used for both Serial ports
unsigned long baud = 115200;

void modem_test();

void setup() {
  // reset the ublox module
  pinMode(SARA_RESETN, OUTPUT);
  digitalWrite(SARA_RESETN, HIGH);
  delay(100);
  digitalWrite(SARA_RESETN, LOW);

  Serial.begin(baud);
  SerialSARA.begin(baud);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("Starting modem test...");
  if (modem.begin()) {
    Serial.println("modem.begin() succeeded");
  } else {
    Serial.println("ERROR, no modem answer.");
  }

  modem_test();
}

void loop() {
  if (Serial.available()) {
    SerialSARA.write(Serial.read());
  }

  if (SerialSARA.available()) {
    Serial.write(SerialSARA.read());
  }
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
      Serial.println("Modem is functioning properly\n");
    } else {
      Serial.println("Error: getIMEI() failed after modem.begin()");
    }
    } else {
      Serial.println("Error: Could not get IMEI");
    }
}