#if !defined(SIMPLE_WIRES_H_)
#define SIMPLE_WIRES_H_
#include <cstdint>

struct WIRE {
    char color[7];
    uint16_t lower;
    uint16_t upper;
};


class SimpleWires
{
private:
    uint8_t wires[6];
    uint8_t SerialNumberOdd;
public:
    static const int OFF;
    static const int RED;
    static const int WHITE;
    static const int BLUE;
    static const int YELLOW;
    static const int BLACK;

    static const WIRE WIRES[6];

    SimpleWires(uint16_t wires[], uint8_t serialNumberOdd);

    uint8_t countColor(int color);
    uint8_t getLastWirePosition();
    uint8_t getWireAtPosition(int pos);
    uint8_t getColorPos(int pos, int color);
    uint8_t getLastColorPos(int color);
    uint8_t calculateSolution();

};

#endif
