#include "SimpleWiresLib.h"


const int OFF = 0, RED = 1, WHITE = 2, BLUE = 3, YELLOW = 4, BLACK = 5;

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
