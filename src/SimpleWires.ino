
int armedRedLed = 12;
int armedGreenLed = 11;

int serialNumberOddSwitch = 8;

static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};

int wireValues[6];

struct WIRE {
  String color;
  uint16_t lower;
  uint16_t upper;
};

static const int RED = 0, WHITE = 1, BLUE = 2, YELLOW = 3, BLACK = 4, OFF =5;

static const WIRE wires[6] = {
    {"RED", 0,255},
    {"WHITE", 256, 419},
    {"BLUE", 420, 608},
    {"YELLOW", 609, 776},
    {"BLACK", 777,935},
    {"OFF", 936, 1023}
    };

int solution;


boolean serialNumberOdd;

void setup() {
  pinMode(armedRedLed, OUTPUT);
  pinMode(armedGreenLed, OUTPUT);
  digitalWrite(armedRedLed, HIGH);
  digitalWrite(armedGreenLed, LOW);

  pinMode(serialNumberOddSwitch, INPUT);
  serialNumberOdd = digitalRead(serialNumberOddSwitch);

  
  
  Serial.begin(9600);
  getWires(wireValues);
  
  for(int i = 0; i<6; i++){
    Serial.println(wires[wireValues[i]].color);
  }

  if(serialNumberOdd){
    Serial.println("Serial Number is Odd");
  }else{
    Serial.println("Serial Number is Even");
  }
  

}

void loop() {
    // put your main code here, to run repeatedly:
  
}


void getWires(int returnArray[]){
  for(int i = 0; i<6; i++){
    int curValue = analogRead(analog_pins[i]);
    for(int j = 0; j<6; j++){
      if(curValue <= wires[j].upper) {
        returnArray[i] = j;
        break;
      }
    }
  }
}

int calculateSolution(int wires[]){
  int wirecount = 6 - countColor(wires, OFF);
  //3wires
  if(wirecount == 3){
    
    if(countColor(wires, RED) == 0){
      return 2; 
    }
    
    int lastWire = getLastWirePosition(wires);
    if(wires[lastWire] == WHITE) return lastWire; 

    if(countColor(wires, BLUE) > 1) {
      return getLastColorPos(wires, BLUE);
    }

    return lastWire;
  
  }
  
  

  
}

int countColor(int wires[], int color){
  int count = 0;
  for(int i = 0; i < 6; i++){
    if(wires[i] = color) count++;
  }
  return count;
}

int getLastWirePosition(int wires[]){
  int i = 5;
  while(wires[i] == OFF){
    i--;
  }
  return i;
}

int getWireAtPosition(int wires[], int pos){
  int curWire = 0;
  for(int i = 0; i < 6; i++){
    if(wires[i] != OFF) {
      if(pos == 0) break;
      pos--;
    }
    curWire++;
  }
  return curWire;
}

int getColorPos(int wires[], int pos, int color){
  int curWire = 0;
  while(pos > 0 || wires[curWire] != color){
    if(wires[curWire] == color) pos--;
    curWire++;
  }
}

int getLastColorPos(int wires[], int color){
  int curWire = 5;
  while(wires[curWire] != color){
    curWire--;
  }
}



