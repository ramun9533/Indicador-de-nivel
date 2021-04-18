static unsigned int nivel1 = 2;
static unsigned int nivel2 = 3; //
static unsigned int nivel3 = 4; //
static unsigned int nivel4 = 5;
static unsigned int nivel5 = 6 ; //
static unsigned int Lednivel1 = 7; //
static unsigned int Lednivel2 = 8; //
static unsigned int Lednivel3 = 9; //
static unsigned int Lednivel4 = 10; //
static unsigned int Lednivel5 = 11 ; //
static unsigned int Lednivel6 = 12 ;
int nivel0,nivel, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5 = 0; //variables donde guardare las entradas para hacer la logica
/
char nivelchar;
void setup() {
  Serial.begin (9600);
  pinMode(nivel1, INPUT);
  pinMode(nivel2, INPUT);
  pinMode(nivel3, INPUT);
  pinMode(nivel4, INPUT);
  pinMode(nivel5, INPUT);
  pinMode(Lednivel1, OUTPUT);
  pinMode(Lednivel2, OUTPUT);
  pinMode(Lednivel3, OUTPUT);
  pinMode(Lednivel4, OUTPUT);
  pinMode(Lednivel5, OUTPUT);
  pinMode(Lednivel6, OUTPUT);
  }

void func1 ()
{
  Serial.print (nivel3);
  //return;
}

void loop() {
  Nivel1 = digitalRead(nivel1);
  Nivel2 = digitalRead(nivel2);
  Nivel3 = digitalRead(nivel3);
  Nivel4 = digitalRead(nivel4);
  Nivel5 = digitalRead(nivel5);
  digitalWrite(Lednivel1, Nivel1);
  digitalWrite(Lednivel2, Nivel2);
  digitalWrite(Lednivel3, Nivel3);
  digitalWrite(Lednivel4, Nivel4);
  digitalWrite(Lednivel5, Nivel5);
  if (!Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and !Nivel5) //inicia el algebra boleana
  {
    nivel = 0;
    nivelchar = 'A';
  }

  if (Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and !Nivel5)
  {
    nivel = 1;
    nivelchar  = 'B';
  }
  if (Nivel1 and Nivel2 and !Nivel3 and !Nivel4 and !Nivel5)
  {
    nivel = 2;
    nivelchar  = 'C';
  }
  if (Nivel1 and Nivel2 and Nivel3 and !Nivel4 and !Nivel5)
  { nivel = 3;

  nivelchar = 'D';
  }

  if (Nivel1 and Nivel2 and Nivel3 and Nivel4 and !Nivel5)
  { nivel = 4;
nivelchar = 'E';
  }
  if (Nivel1 and Nivel2 and Nivel3 and Nivel4 and Nivel5)
  { nivel = 5;
nivelchar  = 'F';
  }
  if (   !((!Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and !Nivel5) or
           (Nivel1 and !Nivel2 and !Nivel3 and !Nivel4 and !Nivel5) or
           (Nivel1 and Nivel2 and !Nivel3 and !Nivel4 and !Nivel5) or
           (Nivel1 and Nivel2 and Nivel3 and !Nivel4 and !Nivel5) or
           (Nivel1 and Nivel2 and Nivel3 and Nivel4 and !Nivel5) or
           (!Nivel1 and Nivel2 and Nivel3 and Nivel4 and Nivel5)  ) )
  { nivel = 6;
  nivelchar  = 'G';
    Serial.print ('G');
    //   Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // modificar secuencuia de error
    digitalWrite( Lednivel6, HIGH);
    delay(250);
    digitalWrite( Lednivel6, LOW);
    delay(250);
  }
  if (nivel1 != nivel)                                   // hace algo diferente
  { // hace algo diferente
    func1();                                          // hace algo diferente
    //delay (2000);                                             // hace algo diferente
  }

  nivel1 = nivel;
}
