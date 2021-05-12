uint8_t l1 = 2;
uint8_t l2 = 3; // abreviacion (uint8_t) enteros de 1 byte sin signo
uint8_t l3 = 4; //
uint8_t l4 = 5;
uint8_t l5 = 6 ; //
uint8_t o1 = 7; //
uint8_t o2 = 8; //
uint8_t o3 = 9; //
uint8_t o4 = 10; //
uint8_t o5 = 11 ; //
uint8_t o6 = 12 ; 
int L1, L2, L3, L4, L5 = 0; //variables donde guardare las entradas para hacer la logica
int O1, O2, O3, O4, O5, O6, nivel, nivel1 = 0; // variables donde reflegare las entradas en forma de salidas, y "nivel" donde guardare el nivel
char nivel3;
void setup() {
  Serial.begin (9600);
  pinMode(l1, INPUT);
  pinMode(l2, INPUT);
  pinMode(l3, INPUT);
  pinMode(l4, INPUT);
  pinMode(l5, INPUT);
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
  pinMode(o3, OUTPUT);
  pinMode(o4, OUTPUT);
  pinMode(o5, OUTPUT);
  pinMode(o6, OUTPUT);
  nivel3 = 'A';
  Serial.println (nivel3);
}

void Imprime ()
{
  Serial.println (nivel3);
}

void loop() {
  L1 = digitalRead(l1);
  L2 = digitalRead(l2);
  L3 = digitalRead(l3);
  L4 = digitalRead(l4);
  L5 = digitalRead(l5);
  digitalWrite(o2, L2);
  digitalWrite(o3, L3);
  digitalWrite(o4, L4);
  digitalWrite(o5, L5);
  if (!L1 and !L2 and !L3 and !L4 and !L5) //inicia el algebra boleana
  {
    nivel = 0;
    nivel3 = 'A';
  }

  if (L1 == 1)
  {
    nivel = 20;
    nivel3 = 'B';
  }
  if (L2 == 1)
  {
    nivel = 40;
    nivel3 = 'C';
  }
  if (L3 == 1)
  { nivel = 60;
    nivel3 = 'D';
  }

  if (L4 == 1)
  { nivel = 80;
    nivel3 = 'E';
  }
  if (L5 == 1)
  { nivel = 5;
    nivel3 = 'F';
  }
  if (!((L1 and L2 and L3 and L4 and L5) or
        (L1 and L2 and L3 and L4 and !L5) or
        (L1 and L2 and L3 and !L4 and !L5) or
        (L1 and L2 and !L3 and !L4 and !L5) or
        (L1 and !L2 and !L3 and !L4 and !L5) or
        (!L1 and !L2 and !L3 and !L4 and !L5)  ) )
  {
    nivel = 6;
    Serial.println ('G');
    //   Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // modificar secuencuia de error
    digitalWrite(o6, HIGH);
    delay(250);
    digitalWrite(o6, LOW);
    delay(250);
  }
  if (nivel1 != nivel)                                   // hace algo diferente
  {
    Imprime ();                                          // hace algo diferente
    delay (1000);                                             // hace algo diferente
  }
  nivel1 = nivel;
}
