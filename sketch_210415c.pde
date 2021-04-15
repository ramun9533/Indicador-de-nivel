void setup() {
  size(700, 700); 
  stroke(255);
  noFill();
}
void draw() {
  background(0);
line(250, 250, 250, 450); //x1 , y1 , x2, y2 izquierda
stroke(255);
line(400, 250, 400, 450);// derecha
stroke(255);
line(250, 250, 400, 250);// arriba
stroke(255);
line(250, 450, 400, 450); //abajo
strokeWeight (2); // grosor de la linea global

//strokeWeight(1);  // Default
//line(20, 20, 80, 20);
//strokeWeight(4);  // Thicker
//line(20, 40, 80, 40);
//strokeWeight(10);  // Beastly
//line(20, 70, 80, 70);


line(250, 400, 400, 400);// linea movil de nivel solo variar Y1 y Y2; donde 250 es maximo y 450 minimo; cada bit son 40 pix



}
