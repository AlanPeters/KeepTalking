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


SimpleWires::SimpleWires(uint16_t values[]){
    for(int i = 0; i<6; i++){
        for(int j = 0; j<6; j++){
            if(values[i] >= WIRES[j].lower && values[i] <= WIRES[j].upper) {
                wires[i] = j;
                break;
            }
        }
    }



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


