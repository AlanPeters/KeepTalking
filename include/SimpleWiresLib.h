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
    int wires[6];

public:
    SimpleWires(uint16_t wires[]);
    uint8_t countColor(int color);
    static const WIRE WIRES[6];
};

#endif
