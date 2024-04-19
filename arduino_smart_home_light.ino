#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX

int latchPin = 5;     // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 6;     // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 4;      // Data pin of 74HC595 is connected to Digital pin 4
int outputEnablePin = 3; // OE pin of 74HC595 is connected to Digital pin 3

byte leds = 0;         // Variable to hold the pattern of which LEDs are currently turned on or off

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT); 
  
  // Set all LEDs to off initially
  updateShiftRegister();
  
  // Set up Bluetooth serial communication
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    switch (command) {
      case 'A':
        bitSet(leds, 0); // Turn LED 1 on
        break;
      case 'B':
        bitClear(leds, 0); // Turn LED 1 off
        break;
      case 'C':
        bitSet(leds, 1); // Turn LED 2 on
        break;
      case 'D':
        bitClear(leds, 1); // Turn LED 2 off
        break;
      case 'E':
        bitSet(leds, 2); // Turn LED 3 on
        break;
      case 'F':
        bitClear(leds, 2); // Turn LED 3 off
        break;
      case 'G':
        bitSet(leds, 3); // Turn LED 4 on
        break;
      case 'H':
        bitClear(leds, 3); // Turn LED 4 off
        break;
      case 'I':
        bitSet(leds, 4); // Turn LED 5 on
        break;
      case 'J':
        bitClear(leds, 4); // Turn LED 5 off
        break;
      case 'K':
        bitSet(leds, 5); // Turn LED 6 on
        break;
      case 'L':
        bitClear(leds, 5); // Turn LED 6 off
        break;
      case 'M':
        bitSet(leds, 6); // Turn LED 7 on
        break;
      case 'N':
        bitClear(leds, 6); // Turn LED 7 off
        break;
      case 'O':
        bitSet(leds, 7); // Turn LED 8 on
        break;
      case 'P':
        bitClear(leds, 7); // Turn LED 8 off
        break;
    }
    
    updateShiftRegister();
  }
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}
