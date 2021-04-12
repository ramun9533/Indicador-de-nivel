static unsigned int l1 = 2; //nivel 20
static unsigned int l2 = 3; //nivel 40
static unsigned int l3 = 4; //snivel 60
static unsigned int l4 = 5; // nivel 80
static unsigned int l5 = 6 ; // nivel 100

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
    nivel = 20;
  }
  if (L1 and L2 and !L3 and !L4 and !L5)
  {
    nivel = 40;
  }
  if (L1 and L2 and L3 and !L4 and !L5)
  { nivel = 60;
  }

  if (L1 and L2 and L3 and L4 and !L5)
  { nivel = 80;

  }
  if (L1 and L2 and L3 and L4 and L5)
  { nivel = 100;

  }
// Mensaje de error, cuando el sensor no indica señal lineal y se brinca bits
 if (   !((L1 and L2 and L3 and L4 and L5) or 
           (L1 and L2 and L3 and L4 and !L5) or
           (L1 and L2 and L3 and !L4 and !L5) or
           (L1 and L2 and !L3 and !L4 and !L5) or
           (L1 and !L2 and !L3 and !L4 and !L5) or
           (!L1 and !L2 and !L3 and !L4 and !L5)  ) )

  {
    Serial.println ("Error, revise el sistema comenzando por el sensor indicador");
  }
  
  Serial.println ("Nivel");
  Serial.println (nivel);
  delay (1000);
}
