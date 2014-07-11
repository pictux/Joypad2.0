/*
06/2014
Mirco Piccin aka Pictux Pitusso
Use JoyPad connected via bluetooth to drive a continuos line, 
as happens in a real Etch&Sketch 
*/

import processing.serial.*;

boolean canDraw = false;
int controllerX, controllerXprev, controllerY, controllerYprev = 0;
Serial myPort;

void setup() {
  size(640, 360);
  background(102);
  
  String portName = "/dev/rfcomm0"; //"/dev/ttyUSB0"; //"/dev/ttyACM0"; 
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  stroke(255);
  if (canDraw) {
    strokeWeight(2);
    line(controllerX, controllerY, controllerXprev, controllerYprev);
    controllerXprev = controllerX;
    controllerYprev = controllerY;
  }
}

void serialEvent(Serial myPort)
{
  String tempValue =  myPort.readString();
  controllerX = int(tempValue.split(";")[0]);
  controllerY = int(tempValue.split(";")[1]);
  println(controllerX + " " + controllerY); 
}

void keyPressed() {
   if (keyCode == ENTER) {
      canDraw = true;
      controllerXprev = controllerX;
      controllerYprev = controllerY;
      background(102);
   } 
}
