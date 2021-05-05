int multiplox = 230;
int multiploy = 410;
import processing.serial.*;
Serial PuertoMio;  
char val;  
PImage img ;

int Posicionx, Posiciony;

void setup()
{
  size (225, 400);
  img = loadImage ("dibujo-1.png");
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
    Posicionx = multiplox *3;
    Posiciony =multiploy *2;
    break;
  case 'B': 
    Posicionx = multiplox *2;
    Posiciony =multiploy *2;
    break;
  case 'C': 
    Posicionx = multiplox *1;
    Posiciony =multiploy *2;
    break;
  case 'D': 
    //fill(#05FAEC); // 60%
    Posicionx = multiplox *3;
    Posiciony =multiploy *1;
    break;
  case 'E': 
    Posicionx = multiplox *2 ;// 80%
    Posiciony = multiploy * 1;
    break;
  case 'F': 
    Posicionx = multiplox *1;// 100% . 
    Posiciony =multiploy * 1;
    break;
  case 'G': 
    Posicionx =1000;
    Posiciony =1000;
    break;
  }
  image (img, width-(Posicionx), height-(Posiciony));
}
