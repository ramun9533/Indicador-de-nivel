float Nivel;
float NivelMaximo = 5;
float NivelMinimo = 0;
boolean Error = false;
//import processing.serial.*;
int i = 0;
color ColorFondo = color(204, 255, 0);
color FondoNivel = color(0, 0, 0);
color ColorNivel = color(50, 50, 200);
color ColorError = color(255, 0, 0);
//Serial PuertoMio;  
char val;      // 
void setup() {
  size(640, 360);
  //String portName = Serial.list()[0];
  //PuertoMio = new Serial(this, portName, 9600);
  Nivel = NivelMinimo;
}

void draw() {


  //if ( PuertoMio.available() > 0) {  
  //  val = PuertoMio.readChar(); 
  //}
  //background(0);      
  //  N;1 
  // N;3
  // E;1 
  switch(val) {
  case 'A': 
    Nivel = 0;
    Error = false;
    break;
  case 'B': 
    Nivel = 1;
    Error = false;
    break;
  case 'C': 
    Nivel = 2;
    Error = false;
    break;
  case 'D': 
    Nivel = 3;
    Error = false;
    break;
  case 'E': 
    Nivel = 4;
    Error = false;
    break;
  case 'F': 
    Nivel = 5;
    Error = false;
    break;
  case 'G': 
    Error = true;
    break;
  }

  if (Error) {
    background(ColorError);
  } else {
    float NivelCuadro = map(Nivel, NivelMinimo, NivelMaximo, height, 0);
    NivelCuadro = constrain(NivelCuadro, 0, height);

    background(ColorFondo);
    fill(FondoNivel);
    rect(width/2, 0, width/2, height);
    fill(ColorNivel);
    rect(width/2, NivelCuadro, width/2, height);
  }
}
