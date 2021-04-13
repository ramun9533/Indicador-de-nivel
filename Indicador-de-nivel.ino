static unsigned int l1 = 2; //nivel 20
static unsigned int l2 = 3; //nivel 40
static unsigned int l3 = 4; //snivel 60
static unsigned int l4 = 5; // nivel 80
static unsigned int l5 = 6 ; // nivel 100
static unsigned int o1 = 7; //Variables espejp para indicador visual
static unsigned int o2 = 8; //
static unsigned int o3 = 9; //
static unsigned int o4 = 10; //
static unsigned int o5 = 11 ; 
static unsigned int o6 = 12 ;// Indicador visual alarma
int L1 = 0;
int L2 = 0;
int L3 = 0;
int L4 = 0;
int L5 = 0;
int O1 = 0;
int O2 = 0;
int O3 = 0;
int O4 = 0;
int O5 = 0;
int O6 = 0;
int nivel = 0;

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
}
void loop() {
  L1 = digitalRead(l1);
  L2 = digitalRead(l2);
  L3 = digitalRead(l3);
  L4 = digitalRead(l4);
  L5 = digitalRead(l5);
  digitalWrite(o1, L1);
  digitalWrite(o2, L2);
  digitalWrite(o3, L3);
  digitalWrite(o4, L4);
  digitalWrite(o5, L5);

  if (!L1 and !L2 and !L3 and !L4 and !L5)//nivel 0%
  {
    nivel = 0;
  }
  if (L1 and !L2 and !L3 and !L4 and !L5)//nivel 20%
  {
    nivel = 20;
  }
  if (L1 and L2 and !L3 and !L4 and !L5)//nivel 40%
  {
    nivel = 40;
  }
  if (L1 and L2 and L3 and !L4 and !L5)//nivel 60%
  { nivel = 60;
  }

  if (L1 and L2 and L3 and L4 and !L5)//nivel 80%
  { nivel = 80;

  }
  if (L1 and L2 and L3 and L4 and L5) //nivel 100%
  { nivel = 100;

  }
  // Mensaje de error, cuando el sensor no indica señal lineal y se brinca bits
  if (   !((L1 and L2 and L3 and L4 and L5) or
           (L1 and L2 and L3 and L4 and !L5) or
           (L1 and L2 and L3 and !L4 and !L5) or
           (L1 and L2 and !L3 and !L4 and !L5) or
           (L1 and !L2 and !L3 and !L4 and !L5) or
           (!L1 and !L2 and !L3 and !L4 and !L5)  ) ) // Fucnion de falla en el sistema

  {
    Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // Mensaje de error
    digitalWrite(o6, HIGH);// Indicador visual con led de error
    delay(400);
    digitalWrite(o6, LOW);
    delay(250);
  }
  Serial.println ("Nivel"); // Impresion de nivel
  Serial.println (nivel);
  Serial.print ("%");
  Serial.println ("  ");
  delay (1000);
  }
