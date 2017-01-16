#include "SimpleWiresLib.h"
#include "stdint.h"

const uint8_t SimpleWires::OFF = 0,
      SimpleWires::RED = 1,
      SimpleWires::WHITE = 2,
      SimpleWires::BLUE = 3,
      SimpleWires::YELLOW = 4,
      SimpleWires::BLACK = 5;

const uint8_t SimpleWires::SOLVED = 1,
        SimpleWires::STRIKE = 2;



SimpleWires::SimpleWires(){

}

void SimpleWires::setup(uint8_t (&wires)[6], uint8_t serialNumberOdd){
    this->serialNumberOdd = serialNumberOdd;
    for(int i = 0; i < 6; i++){
        this->wires[i] = wires[i];
    }
    solution = calculateSolution();
}


SimpleWires::CHECK_RETURN SimpleWires::check(uint8_t (&wires)[6]){
    int solved = 0;
    int strikes = 0;
    CHECK_RETURN return_val = {0,0};

    for(int i = 0; i < 6; i++){
        if(wires[i] != this->wires[i]){
            this->wires[i] = wires[i];
            if(i == solution){
                return_val.solved = 1;
            } else {
                return_val.strikes++;
            }
        }
    }
    return return_val;
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
        if(countColor(RED)>1 && serialNumberOdd != 0){
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
        if(wires[getLastWirePosition()]==BLACK && serialNumberOdd !=0){
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
        if(countColor(YELLOW)==0 && serialNumberOdd){
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

