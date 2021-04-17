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
int O1, O2, O3, O4, O5, O6, nivel = 0;// variables donde reflegare las entradas en forma de salidas, y "nivel" donde guardare el nivel

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
  // "strstr" ver que hace
}
void loop() {
  L1 = digitalRead(l1);
  L2 = digitalRead(l2);
  L3 = digitalRead(l3);
  L4 = digitalRead(l4);
  L5 = digitalRead(l5);

  digitalWrite(o1, L1); // nivel en forma visual, hardware
  digitalWrite(o2, L2);
  digitalWrite(o3, L3);
  digitalWrite(o4, L4);
  digitalWrite(o5, L5);

  if (!L1 and !L2 and !L3 and !L4 and !L5) //inicia el algebra boleana
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

  if (   !((L1 and L2 and L3 and L4 and L5) or
           (L1 and L2 and L3 and L4 and !L5) or
           (L1 and L2 and L3 and !L4 and !L5) or
           (L1 and L2 and !L3 and !L4 and !L5) or
           (L1 and !L2 and !L3 and !L4 and !L5) or
           (!L1 and !L2 and !L3 and !L4 and !L5)  ) )

  {
    Serial.println ("Error, revise el sistema comenzando por el sensor indicador"); // modificar secuencuia de error
    digitalWrite(o6, HIGH);
    delay(250);
    digitalWrite(o6, LOW);
    delay(250);
    digitalWrite(o6, HIGH);
    delay(250);
    digitalWrite(o6, LOW);
    delay(250);
    digitalWrite(o6, HIGH);
    delay(250);
    digitalWrite(o6, LOW);
    delay(250);
  }
  //if (nivel  nivel ){
  Serial.print (" Nivel "); // "strstr" ver que hace
  Serial.print (nivel);
  Serial.print (" %");
  Serial.println ("  ");
  //}

  //fflush(stdin);
  delay (1000);
}
