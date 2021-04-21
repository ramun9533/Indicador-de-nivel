float a;
import processing.serial.*;
int b, i = 0;
Serial PuertoMio;  
char val;      // 
void setup() {
  size(640, 360);
  String portName = Serial.list()[0];
  PuertoMio = new Serial(this, portName, 9600);
  stroke(255);
  a = 360;
}
void draw() {
  background(b);
  line(0, a, width, a); 

  if ( PuertoMio.available() > 0) {  // 
    val = PuertoMio.readChar();         //
  }
  //background(0);             // 
  switch(val)
  {
  case 'A': 
    //fill(#FA1A05); 
    a = 360;
    break;
  case 'B': 
    a = 288;
    //fill(#E5FA05); 
    break;
  case 'C': 
    a = 216;
    //fill(#24FA05); 
    break;
  case 'D': 
    a = 144;
    ////fill(#05FAEC); 
    break;
  case 'E': 
    a = 72;
    // fill(#0513FA); 
    break;
  case 'F': 
    a = 0;
    //fill(#CC05FA); 
    break;
  case 'G': 
    for (i = 0; i < 755; i++) {
      if (i <= 754) {
        b += 1;
      }
    } 
    delay (500);
    break;
  }
  line(0, a, width, a);
}
