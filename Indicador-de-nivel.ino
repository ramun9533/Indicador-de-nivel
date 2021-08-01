// Input and Output pins
#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define in5 6
#define out1 7
#define out2 8
#define out3 9
#define out4 10
#define out5 11
#define out6 12

uint8_t nivel[5]; // Array of sensor inputs 
uint8_t nivel_out = 0; // Numeric value of level 

uint8_t current_state = 0; // Current max level
uint8_t last_state = 10; // Previous level

char nivel_state [6] = {'A','B', 'C', 'D', 'E', 'F'}; // Level labels
char nivel_print = 'A'; // Level label for processing

bool error = false;
  

void setup() {

  // Initialize serial communication
  Serial.begin(9600);

  /*
   * Inputs configuration
   */
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(in5, INPUT);

  /*
   * Outputs configuration
   */
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);
}

void loop() {

  /****************** sensors lecture loop ***********************************/
  while(current_state == last_state){
    
    nivel[0] = digitalRead(in1);
    nivel[1] = digitalRead(in2);
    nivel[2] = digitalRead(in3);
    nivel[3] = digitalRead(in4);
    nivel[4] = digitalRead(in5);
    
    current_state = ( nivel[0] + nivel[1] + nivel[2] + nivel[3] + nivel[4] );  
    delay(250);
  }

  /****************** Looking for errors on sensor inputs   */
  for (int i = 1; i <= current_state; i++){
    
    if( nivel[i] == 0){    
      handle_error(); // Error with sensors lecture
      break;
    }
        
  }

  if(!error){
    level_display(); // Pins and processing outputs
  }
  else{
    error == !error; // Error state reset
  }
}

void handle_error(){

  Serial.println("Error with sensors lecture");

  digitalWrite(out6, HIGH);
  delay(250);
  digitalWrite(out6, LOW);
  delay(250);
  
  nivel_print = nivel_state[5]; 
  error = !error;
  
}

void level_display(){
  
  if (current_state != last_state){

    last_state = current_state;
    nivel_out = current_state * 20;
    nivel_print = nivel_state[current_state];

    digitalWrite(out1, nivel[0]);
    digitalWrite(out2, nivel[1]);
    digitalWrite(out3, nivel[2]);
    digitalWrite(out4, nivel[3]);
    digitalWrite(out5, nivel[4]);
    
  }

}
