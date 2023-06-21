int8_t in1 = 2;
uint8_t in2 = 3; // abreviacion (uint8_t) enteros de 1 byte sin signo
uint8_t in3 = 4; //
uint8_t in4 = 5;
uint8_t in5 = 6 ; //
uint8_t out1 = 7; //
uint8_t out2 = 8; //
uint8_t out3 = 9; //
uint8_t out4 = 10; //
uint8_t out5 = 11 ; //
uint8_t out6 = 12 ;
int Nivel1 , Nivel2, Nivel3, Nivel4, Nivel5; //variables donde guardare las entradas para hacer la logica
int O1, O2, O3, O4, O5, O6, nivel, nivel1; // variables donde reflegare las entradas en forma de salidas, y "nivel" donde guardare el nivel
char nivel3;
void setup() {
  Serial.begin (9600);
  pinMode(in1, INPUT_PULLUP);
  pinMode(in2, INPUT_PULLUP);
  pinMode(in3, INPUT_PULLUP);
  pinMode(in4, INPUT_PULLUP);
  pinMode(in5, INPUT_PULLUP);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
  pinMode(out6, OUTPUT);
  nivel3 = 'A';
  Serial.println (nivel3);
}

void imprime ()
{
  Serial.println (nivel3);
}

void loop() {
  Nivel1 = digitalRead(in1);
  Nivel2 = digitalRead(in2);
  Nivel3 = digitalRead(in3);
  Nivel4 = digitalRead(in4);
  Nivel5 = digitalRead(in5);
  digitalWrite(out2, Nivel2);
  digitalWrite(out3, Nivel3);
  digitalWrite(out4, Nivel4);
  digitalWrite(out5, Nivel5);
  if (Nivel1 and Nivel2 and Nivel3 and Nivel4 and Nivel5) //inicia el algebra boleana
  {
    nivel = 0;
    nivel3 = 'A';
  }

  if (Nivel1 == 0)
  {
    nivel = 20;
    nivel3 = 'B';
  }
  if (Nivel2 == 0)
  {
    nivel = 40;
    nivel3 = 'C';
  }
  if (Nivel3 == 0)
  { nivel = 60;
    nivel3 = 'D';
  }

  if (Nivel4 == 0)
  { nivel = 80;
    nivel3 = 'E';
  }
  if (Nivel5 == 0)
  { nivel = 5;
    nivel3 = 'F';
  }
  if (!((!Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and !Nivel5) or
        (!Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and Nivel5) or
        (!Nivel1 and !Nivel2 and !Nivel3 and Nivel4 and Nivel5) or
        (!Nivel1 and !Nivel2 and Nivel3 and Nivel4 and Nivel5) or
        (!Nivel1 and Nivel2 and Nivel3 and Nivel4 and Nivel5) or
        (Nivel1 and Nivel2 and Nivel3 and Nivel4 and Nivel5)  ) )
  {
    nivel = 6;
    Serial.println ('G');
    //   Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // modificar secuencuia de error
    digitalWrite(out6, HIGH);
    delay(250);
    digitalWrite(out6, LOW);
    delay(250);
  }
  if (nivel1 != nivel)                                   // hace algo diferente
  {
    imprime ();                                          // hace algo diferente
     //delay (1000);                                             // hace algo diferente
  }
  nivel1 = nivel;
}
