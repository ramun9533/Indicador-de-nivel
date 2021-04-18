static unsigned int l1 = 2;
static unsigned int l2 = 3; //
static unsigned int l3 = 4; //
static unsigned int l4 = 5;
static unsigned int l5 = 6 ; //
static unsigned int o1 = 7; //
static unsigned int o2 = 8; //
static unsigned int o3 = 9; //
static unsigned int o4 = 10; //
static unsigned int o5 = 11 ; //
static unsigned int o6 = 12 ;
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
  Serial.println (nivel);
}

void func1 (void)
{
  Serial.println (nivel3);
  return;
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

  if (L1 and !L2 and !L3 and !L4 and !L5)
  {
    nivel = 1;
    nivel3 = 'B';
  }
  if (L1 and L2 and !L3 and !L4 and !L5)
  {
    nivel = 2;
    nivel3 = 'C'; 
  }
  if (L1 and L2 and L3 and !L4 and !L5)
  { nivel = 3;
    nivel3 = 'D';
  }

  if (L1 and L2 and L3 and L4 and !L5)
  { nivel = 4;
    nivel3 = 'E';
  }
  if (L1 and L2 and L3 and L4 and L5)
  { nivel = 5;
    nivel3 = 'F';
  }
  if (   !((L1 and L2 and L3 and L4 and L5) or
           (L1 and L2 and L3 and L4 and !L5) or
           (L1 and L2 and L3 and !L4 and !L5) or
           (L1 and L2 and !L3 and !L4 and !L5) or
           (L1 and !L2 and !L3 and !L4 and !L5) or
           (!L1 and !L2 and !L3 and !L4 and !L5)  ) )
  { nivel = 6;
    //nivel3 = 'G';
    Serial.println ('G');
    //   Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // modificar secuencuia de error
    digitalWrite(o6, HIGH);
    delay(250);
    digitalWrite(o6, LOW);
    delay(250);
  }
  if (nivel1 != nivel)                                   // hace algo diferente
  { // hace algo diferente
    func1();                                          // hace algo diferente
    //delay (2000);                                             // hace algo diferente
  }

  nivel1 = nivel;
}
