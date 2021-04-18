import processing.serial.*;
Serial MiPuerto;
//int Variable;



color color0 = color (#4FEA21);//#4FEA21

color color1 = color (#1CF50A);








void setup() {
  MiPuerto = new  Serial(this, "/dev/ttyACM0", 9600);
  size(700, 700); 
  ellipseMode(CENTER);  


  //stroke(255);
  //noFill();
}





void draw() {
  while ( MiPuerto.available() > 0) {
    int inByte =  MiPuerto.read();
    println(inByte);
  }

  background(0);//fondo
  fill (#1CF50A);


  circle (200, 300, 300);
  //stroke(25); //al rededor/
  //rect(160, 160, 350, 450);


  //line(250, 250, 250, 450); //x1 , y1 , x2, y2 izquierda*+*++
  //stroke(255);
  //line(400, 250, 400, 450);// derecha
  //stroke(255);
  //line(250, 250, 400, 250);// arriba
  //stroke(255);
  //line(250, 450, 400, 450); //abajo
  //strokeWeight (2); // grosor de la linea global

  //strokeWeight(1);  // Default
  //line(20, 20, 80, 20);
  //strokeWeight(4);  // Thicker
  //line(20, 40, 80, 40);
  //strokeWeight(10);  // Beastly
  //line(20, 70, 80, 70);

  //stroke(#03fa0e); // va arriba para dar color abajo

  //fill (#4FEA21); //relleno

  //line(250, 300, 400, 300);// linea movil de nivel solo variar Y1 y Y2; donde 250 es maximo y 450 minimo; cada bit son 40 pix
  //fill (color20); 
  //stroke(color20);
}

void serialEvent() {
  while  (MiPuerto.available() == 1) {
    char V = MiPuerto.readChar();
    print (V);
    if (V == 'A')
    {
      color0 = color (#4FEA21);
    } else
      color1 = color (#1CF50A);
  }
}
