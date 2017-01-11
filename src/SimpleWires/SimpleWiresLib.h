#if !defined(SIMPLE_WIRES_H_)
#define SIMPLE_WIRES_H_
#include "stdint.h"

//struct WIRE {
    //char color[7];
    //uint16_t lower;
    //uint16_t upper;
//};
//


class SimpleWires
{
private:
    uint8_t wires[6];
    uint8_t serialNumberOdd;
    uint8_t solution;
public:
    struct CHECK_RETURN {
        uint8_t strikes;
        uint8_t solved;
    };

    static const int OFF;
    static const int RED;
    static const int WHITE;
    static const int BLUE;
    static const int YELLOW;
    static const int BLACK;

    static const uint8_t SOLVED;
    static const uint8_t STRIKE;

//    static const WIRE WIRES[6];

    SimpleWires();
    void setup (uint16_t (&wires)[6], uint8_t serialNumberOdd);

    uint8_t countColor(int color);
    uint8_t getLastWirePosition();
    uint8_t getWireAtPosition(int pos);
    uint8_t getColorPos(int pos, int color);
    uint8_t getLastColorPos(int color);
    uint8_t calculateSolution();

    CHECK_RETURN check(uint16_t (&wires)[6]);
};

#endif
