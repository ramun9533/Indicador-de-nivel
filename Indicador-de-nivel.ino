static unsigned int l1 = 2; //switch límite del porton
static unsigned int l2 = 3; // boton de paro de emergencia
static unsigned int l3 = 4; //switch límite del porton
static unsigned int l4 = 5; // accionamiento externo con otra señal, que puede ser de 110 VCA
static unsigned int l5 = 6 ; // salida de giro

int L1 = 0;
int L2 = 0;
int L3 = 0;
int L4 = 0;
int L5 = 0;
int  nivel = 0;
void setup() {
  Serial.begin (9600);
  pinMode(l1, INPUT);
  pinMode(l2, INPUT);
  pinMode(l3, INPUT);
  pinMode(l4, INPUT);
  pinMode(l5, INPUT);
}
void loop() {
  L1 = digitalRead(l1);
  L2 = digitalRead(l2);
  L3 = digitalRead(l3);
  L4 = digitalRead(l4);
  L5 = digitalRead(l5);

  if (!L1 and !L2 and !L3 and !L4 and !L5)
  {
    nivel = 0;
  }
  if (L1 and !L2 and !L3 and !L4 and !L5)
  {
    nivel = 25;
  }
  if (L1 and L2 and !L3 and !L4 and !L5)
  {
    nivel = 50;
  }
  if (L1 and L2 and L3 and !L4 and !L5)
  { nivel = 75;
  }

  if (L1 and L2 and L3 and L4 and !L5)
  { nivel = 100;

  }
  Serial.println ("Nivel");
  Serial.println (nivel);
  delay (1000);
}
