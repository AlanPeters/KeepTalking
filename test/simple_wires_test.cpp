#include "SimpleWiresLib.h"
#include "gtest/gtest.h"

TEST(basic_wires_test, count_wires)
{
    uint16_t testInt[6] = { 100, 100, 100, 100, 100, 100 };

    SimpleWires testWires (testInt);



    EXPECT_EQ(6, testWires.countColor(1));
}

