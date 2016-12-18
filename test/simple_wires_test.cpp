#include "SimpleWiresLib.h"
#include "gtest/gtest.h"

TEST(basic_wires_test, count_wires)
{
    uint16_t testInt[6] = { 100, 100, 100, 100, 100, 100 };

    SimpleWires testWires (testInt);



    EXPECT_EQ(6, testWires.countColor(1));
}

TEST(three_wire_test, count_wires)
{
    uint16_t testInput[6] = {1000,100,300,1000,1000,101};
    SimpleWires testWires(testInput);

    EXPECT_EQ(2,testWires.countColor(SimpleWires::RED));
}

TEST(basic_wires_test, getColorPos){
    uint16_t testInput[6] = {100,1000,100,1000,100,300};
    SimpleWires testWires(testInput);

    EXPECT_EQ(0,testWires.getColorPos(1,SimpleWires::RED));
    EXPECT_EQ(2,testWires.getColorPos(2,SimpleWires::RED));
    EXPECT_EQ(4,testWires.getColorPos(3,SimpleWires::RED));
    EXPECT_EQ(6,testWires.getColorPos(4,SimpleWires::RED));

}
