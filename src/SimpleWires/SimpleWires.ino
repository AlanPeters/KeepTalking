#include "SimpleWiresLib.h"


int armedRedLed = 12;
int armedGreenLed = 11;

int serialNumberOddSwitch = 8;

static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};

uint16_t wireValues[6];

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



boolean serialNumberOdd;

SimpleWires game;

void setup() {
  pinMode(armedRedLed, OUTPUT);
  pinMode(armedGreenLed, OUTPUT);
  digitalWrite(armedRedLed, HIGH);
  digitalWrite(armedGreenLed, LOW);

  pinMode(serialNumberOddSwitch, INPUT);
  serialNumberOdd = digitalRead(serialNumberOddSwitch);

  
  
  Serial.begin(9600);
  getWires(wireValues);
  game = new SimpleWires(wireValues, serialNumberOdd);
  
  
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


