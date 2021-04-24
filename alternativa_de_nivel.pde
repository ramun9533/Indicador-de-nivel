import meter.*;
Meter mx;
int Nivel =0; 
char val;      // guardar dato serie
import processing.serial.*;
color ColorError = color (0, 0, 0);
Serial PuertoMio;  
//float b = 2.5;
boolean SecuenciaError = false; 
void setup() 
{
  size (600, 450);
  mx = new Meter (this, 50, 45);
  mx.setMeterWidth(500);
  mx.setTitle("Nivel");
  mx.setDisplayDigitalMeterValue(true);

  String portName = Serial.list()[0];
  PuertoMio = new Serial(this, portName, 9600);
  stroke(255);
}
void draw () 
{
  background(0);
  mx.updateMeter(Nivel);
  if ( PuertoMio.available() > 0) {  // 
    val = PuertoMio.readChar();         //
  }
  switch(val)
  {
  case 'A': 
    //fill(#FA1A05); 
    Nivel = 0;
    break;
  case 'B': 
    Nivel = 51;
    //fill(#E5FA05); 
    break;
  case 'C': 
    Nivel = 102;
    //fill(#24FA05); 
    break;
  case 'D': 
    Nivel = 153;
    ////fill(#05FAEC); 
    break;
  case 'E': 
    Nivel = 204;
    // fill(#0513FA); 
    break;
  case 'F': 
    Nivel = 255;
    //fill(#CC05FA); 
    break;
  case 'G': 
    ColorError = color (250, 0, 0); //pendiente corregir el codigo error
    break;
  }
}
