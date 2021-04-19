import processing.serial.*;

Serial myPort;  
char val;      // 

void setup() 
{
  size(200, 200);

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {  // 
    val = myPort.readChar();         //
  }
  background(0);             // 

  switch(val)
  {
  case 'A': 
    fill(#FA1A05); 
    break;
  case 'B': 
    fill(#E5FA05); 
    break;
  case 'C': 
    fill(#24FA05); 
    break;
  case 'D': 
    fill(#05FAEC); 
    break;
  case 'E': 
    fill(#0513FA); 
    break;
  case 'F': 
    fill(#CC05FA); 
    break;
  case 'G': 
    fill(#FA053E); 
    break;
  }
  rect(50, 50, 100, 100);
}
