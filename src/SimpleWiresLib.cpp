#include "SimpleWiresLib.h"


const int SimpleWires::OFF = 0,
      SimpleWires::RED = 1,
      SimpleWires::WHITE = 2,
      SimpleWires::BLUE = 3,
      SimpleWires::YELLOW = 4,
      SimpleWires::BLACK = 5;

const WIRE SimpleWires::WIRES[6] = {
    {"OFF", 936, 1023},
    {"RED", 0,255},
    {"WHITE", 256, 419},
    {"BLUE", 420, 608},
    {"YELLOW", 609, 776},
    {"BLACK", 777,935} };


SimpleWires::SimpleWires(uint16_t values[], uint8_t serialNumberOdd){
    SerialNumberOdd = serialNumberOdd;
    for(int i = 0; i<6; i++){
        for(int j = 0; j<6; j++){
            if(values[i] >= WIRES[j].lower && values[i] <= WIRES[j].upper) {
                wires[i] = j;
                break;
            }
        }
    }
}


uint8_t SimpleWires::calculateSolution(){
    uint8_t numWires = 6 - countColor(OFF);
    if(numWires == 3){
        if(countColor(RED) == 0){
            return getWireAtPosition(1);
        }
        if(wires[getLastWirePosition()] == WHITE){
            return getLastWirePosition();
        }
        if(countColor(BLUE) > 1){
            return getLastColorPos(BLUE);
        }
        return getLastWirePosition();
    }
    if(numWires == 4){
        if(countColor(RED)>1 && SerialNumberOdd != 0){
            return getLastColorPos(RED);
        }
        if(wires[getLastWirePosition()]==YELLOW && countColor(RED)==0){
            return getWireAtPosition(0);
        }
        if(countColor(BLUE)==1){
            return getWireAtPosition(0);
        }
        if(countColor(YELLOW)>1){
            return getLastWirePosition();
        }
        return getWireAtPosition(1);
    }
    if(numWires == 5){
        if(wires[getLastWirePosition()]==BLACK && SerialNumberOdd !=0){
            return getWireAtPosition(3);
        }
        if(countColor(RED)==1 && countColor(YELLOW)>1){
            return getWireAtPosition(0);
        }
        if(countColor(BLACK)==0){
            return getWireAtPosition(1);
        }
        return getWireAtPosition(0);
    }
    if(numWires == 6){
        if(countColor(YELLOW)==0 && SerialNumberOdd){
            return getWireAtPosition(2);
        }
        if(countColor(YELLOW)==1 && countColor(WHITE) > 1){
            return getWireAtPosition(3);
        }
        if(countColor(RED)==0){
            return getLastWirePosition();
        }
        return getWireAtPosition(3);
    }
    return 6;
}



uint8_t SimpleWires::countColor(int color){
    uint8_t count = 0;
    for(int i = 0; i < 6; i++){
        if(wires[i] == color) count++;
    }
    return count;
}

uint8_t SimpleWires::getLastWirePosition(){
    uint8_t i = 5;
    while(wires[i] == OFF){
        i--;
    }
    return i;
}

uint8_t SimpleWires::getWireAtPosition(int pos){
    uint8_t curWire = 0;
    for(int i = 0; i < 6; i++){
        if(wires[i] != OFF) {
            if(pos == 0) break;
            pos--;
        }
        curWire++;
    }
    return curWire;
}


uint8_t SimpleWires::getColorPos(int pos, int color){
    for(int i = 0;i<6; i++){
        if(wires[i]==color) pos--;
        if(pos == 0) return i;
    }
    return 6;
}

uint8_t SimpleWires::getLastColorPos(int color){
    for(int i = 5; i>=0; i--){
        if(wires[i]==color){
            return i;
        }
    }
    return 6;
}

