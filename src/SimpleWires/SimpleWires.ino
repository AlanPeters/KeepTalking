#include "SimpleWiresLib.h"


int armedRedLed = 12;
int armedGreenLed = 11;

int strike1Led = 2;
int strike2Led = 3;
int strike3Led = 4;

int serialNumberOddLed = 10;

int serialNumberOddSwitch = 8;

static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};

uint8_t wireValues[6];

struct WIRE {
  String color;
  uint16_t lower;
  uint16_t upper;
  uint8_t id;
};

//static const uint8_t RED = SimpleWires::RED, 
 //                WHITE = SimpleWires::WHITE, BLUE = 2, YELLOW = 3, BLACK = 4, OFF =5;

static const WIRE wires[6] = {
    {"RED", 0,255, SimpleWires::RED},
    {"WHITE", 256, 419, SimpleWires::WHITE},
    {"BLUE", 420, 608, SimpleWires::BLUE},
    {"YELLOW", 609, 776, SimpleWires::YELLOW},
    {"BLACK", 777,935, SimpleWires::BLACK},
    {"OFF", 936, 1023, SimpleWires::OFF}
    };

int strikeCounter=0;

boolean serialNumberOdd;

SimpleWires game;

void setup() {
  pinMode(serialNumberOddLed, OUTPUT);
  
  pinMode(armedRedLed, OUTPUT);
  pinMode(armedGreenLed, OUTPUT);

  pinMode(strike1Led, OUTPUT);
  pinMode(strike2Led, OUTPUT);
  pinMode(strike3Led, OUTPUT);
  
  
  digitalWrite(armedRedLed, HIGH);
  digitalWrite(armedGreenLed, LOW);

  digitalWrite(strike1Led, LOW);
  digitalWrite(strike2Led, LOW);
  digitalWrite(strike3Led, LOW);

  pinMode(serialNumberOddSwitch, INPUT);
  serialNumberOdd = digitalRead(serialNumberOddSwitch);
  digitalWrite(serialNumberOddLed, 1 - serialNumberOdd);
  
  
  
  Serial.begin(9600);
  getWires(wireValues);
  game.setup(wireValues, serialNumberOdd);
  
  
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
    delay(500);
    getWires(wireValues);
    SimpleWires::CHECK_RETURN result = game.check(wireValues);
    Serial.println("Solved:");
    Serial.println(result.solved);
    Serial.println("Strikes:");
    Serial.println(result.strikes);
    
    if(result.solved == 1){
      digitalWrite(armedRedLed, LOW);
      digitalWrite(armedGreenLed, HIGH);
    }
    if(result.strikes > 0){
      strikeCounter += result.strikes;
      digitalWrite(strike1Led, HIGH);
      if(strikeCounter >= 2) digitalWrite(strike2Led, HIGH);
      if(strikeCounter >= 3) digitalWrite(strike3Led, HIGH); 
    }
    
    
}


void getWires(uint8_t returnArray[]){
  for(int i = 0; i<6; i++){
    int curValue = analogRead(analog_pins[i]);
    for(int j = 0; j<6; j++){
      if(curValue <= wires[j].upper) {
        returnArray[i] = wires[j].id;
        break;
      }
    }
  }
}


