import processing.serial.*;

Serial PuertoMio;  
char val;      // 

void setup() 
{
  size(200, 200);

  String NombrePuerto = Serial.list()[0];
  PuertoMio = new Serial(this, NombrePuerto, 9600);
}

void draw()
{
  if ( PuertoMio.available() > 0) {  // 
    val = PuertoMio.readChar();         //
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
