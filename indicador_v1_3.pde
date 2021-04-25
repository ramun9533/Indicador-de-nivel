
import processing.serial.*;
Serial PuertoMio;  
char val;  
PImage img ;
int Posicionx, Posiciony;

void setup()
{
  size (325, 450);
  img = loadImage ("nivel_x_y.png");
  String NombrePuerto = Serial.list()[0];
  PuertoMio = new Serial(this, NombrePuerto, 9600);
}

void   draw () {
  if ( PuertoMio.available() > 0) {  // 
    val = PuertoMio.readChar();         //
  }
  background(250, 0, 0);             
  switch(val)
  {
  case 'A': 
    Posicionx =950; // 0%
    Posiciony =900;
    break;
  case 'B': 
    Posicionx =635; // 20%
    Posiciony =900;
    break;
  case 'C': 
    Posicionx =330; // 40%
    Posiciony =890;
    break;
  case 'D': 
    //fill(#05FAEC); // 60%
    Posicionx = 990;
    Posiciony =450;
    break;
  case 'E': 
    Posicionx = 660; // 80%
    Posiciony =450;
    break;
  case 'F': 
    Posicionx = 330;// 100%
    Posiciony =450;
    break;
  case 'G': 
    Posicionx =0;
    Posiciony =0;
    break;
  }
  image (img, width-(Posicionx), height-(Posiciony));
}
