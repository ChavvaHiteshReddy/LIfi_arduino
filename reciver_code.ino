#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// LCD pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;

LiquidCrystal lcd(pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);
SoftwareSerial mySerial(11, 10);  // RX, TX

String previousData = "";  // Track last data to avoid overwriting with the same content

void setup() {
  // Start serial communications
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(A4, INPUT);

  // Setup the LCD
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("LiFi-Demo");
  lcd.setCursor(0, 1);
  lcd.print("Data:");

  Serial.println("SoftwareSerial on A4 (RX) and A5 (TX)");
}

void loop() {

  String inChar = "";

  // Check if data is available from the SoftwareSerial device
  if (mySerial.available()) {
    inChar = mySerial.readString();
    inChar.trim();  // Trim any leading/trailing whitespace
  }

  // Only update the LCD if there's new data and it's different from the last displayed data
  if (inChar != "" && inChar != previousData && digitalRead(A1)) {
    lcd.setCursor(5, 1);            // Set cursor to where the data will be displayed
    lcd.print("                ");  // Clear previous data by overwriting with spaces
    lcd.setCursor(5, 1);            // Move the cursor back for new data
    lcd.print(inChar);              // Print the new data
    previousData = inChar;          // Update the last displayed data
  }

  delay(100);  // Adjust delay for smoother performance
}
