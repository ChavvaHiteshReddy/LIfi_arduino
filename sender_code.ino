#include <SoftwareSerial.h>
#define keyy A4
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Start serial communications
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(keyy, OUTPUT);
  digitalWrite(keyy, HIGH);
  Serial.println("Type something to send the data in LIFI!");
}

void loop() {
  // Send data from Serial Monitor to SoftwareSerial device
  if (Serial.available()) {
    char inChar = Serial.read();
    mySerial.write(inChar);
  }

  // Send data from SoftwareSerial device to Serial Monitor
  if (mySerial.available()) {
    char inChar = mySerial.read();
    Serial.write(inChar);
  }   
}
