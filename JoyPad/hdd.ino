//following code originally written by Cristian Maglie aka megabug
//for Oscurato project: https://code.google.com/p/oscurato/

int readEncoder(int index) {
  int p1 = analogRead(3*index + 0);
  int p2 = analogRead(3*index + 1);
  int p3 = analogRead(3*index + 2);

  if (p1+p2+p3==0)
    return -1;

  int l = p1+p2+p3;    
  int x = (p2-p3)*86;
  int y = p1*100 - (p2+p3)*50;
  int p=-1;
  if (y>0) {
    if (abs(x) < y*57/100) 
      p=0;
    else 
      p=(x<0) ? 5 : 1;
  }
  else {
    if (abs(x) < -y*57/100) 
      p=3;
    else 
      p=(x<0) ? 4 : 2;
  }
  return p;
}

boolean interpolateX() {
  int delta[] = {
    -1, -2, 0, +2, +1, 0, -1, -2, 0, +2, +1
  };
  int v = readEncoder(MOTOR_X);
  if (v==-1)
    return false;
  if (actualX==-1) {
    actualX = 0;
    encActualX = v;
    return true;
  }

  int d = delta[v-encActualX+5];
  actualX += d;
  encActualX = v;
  return true;
}

boolean interpolateY() {
  int delta[] = {
    -1, -2, 0, +2, +1, 0, -1, -2, 0, +2, +1
  };
  int v = readEncoder(MOTOR_Y);
  if (v==-1)
    return false;
  if (actualY==-1) {
    actualY = 0;
    encActualY = v;
    return true;
  }

  int d = delta[v-encActualY+5];
  actualY += d;
  encActualY = v;
  return true;
}
