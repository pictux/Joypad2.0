/*
  JOYPAD
  In this controller you have 2 rotative encoder (the 2 old harddisk brushelss motors), an Arduino, and a Bluetooth module.
  Using bluetooth it's possible to interface this controller to any Android device (phone, phablet, tables) and to any pc (win/linux, don't know if mac is ok).

  It's easy to use, and the idea of this project was born thinking to the **Etch & Sketch** interface.
  
  Mirco Piccin aka Pitusso
  CC BY-SA
  
  BOM, Electronic schemas (as for code), other info can be found here:
  https://github.com/pictux/Joypad2.0
  
  3D printed parts can be founded:
  http://www.thingiverse.com/thing:364735
  
  --------------------
 
  The BLCD interpolation / encoding is based on th code originally 
  written by Cristian Maglie aka megabug for Oscurato project: 
  https://code.google.com/p/oscurato/

  --------------------
*/


#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;

const int MOTOR_X = 0;
const int MOTOR_Y = 1;

const int MOTOR_X_PLUS = 12;
const int MOTOR_X_MINUS = 11;
const int MOTOR_Y_PLUS = 10;
const int MOTOR_Y_MINUS = 9;

int actualX = -1;
int encActualX = -1;

int actualY = -1;
int encActualY = -1;

unsigned long previousSerialMillis = 0;
const int serialInterval = 100; // interval at which to send data via Serial

unsigned long previousSamplingMillis = 0;
const int samplingInterval = 20; // interval at which to sample

SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  digitalWrite(MOTOR_X_PLUS, OUTPUT);
  digitalWrite(MOTOR_X_MINUS, OUTPUT);

  digitalWrite(MOTOR_Y_PLUS, OUTPUT);
  digitalWrite(MOTOR_Y_MINUS, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousSamplingMillis >= samplingInterval) {
    previousSamplingMillis = currentMillis;

/*
    DEBUG
    Serial.print(analogRead(A0));
    Serial.print(" ");
    Serial.print(analogRead(A1));
    Serial.print(" ");
    Serial.print(analogRead(A2));
    Serial.print(" - ");
    Serial.print(analogRead(A3));
    Serial.print(" ");
    Serial.print(analogRead(A4));
    Serial.print(" ");
    Serial.print(analogRead(A5));
    Serial.println();
*/

    if (interpolateX()) {
    }

    if (interpolateY()) {
    }
  }

  if (currentMillis - previousSerialMillis >= serialInterval) {
    previousSerialMillis = currentMillis;
    
    actualXusable = actualX > 0 ? actualX : 0;
    actualYusable = actualY > 0 ? actualY : 0;
    
    Serial.print(actualXusable);
    Serial.print(";");
    bluetooth.print(actualXusable);
    bluetooth.print(";");

    Serial.print(actualYusable);
    Serial.println(";");
    bluetooth.print(actualYusable);
    bluetooth.println(";");
  }
}


