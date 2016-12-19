#include "SimpleWiresLib.h"
#include "gtest/gtest.h"

TEST(BasicWiresTest, CountWires)
{
    uint16_t testInput[6] = { 100, 100, 100, 100, 100, 100 };
    SimpleWires testWires (testInput);

    EXPECT_EQ(6, testWires.countColor(1));
}

TEST(ThreeWireTest, CountWires)
{
    uint16_t testInput[6] = {1000,100,300,1000,1000,101};
    SimpleWires testWires(testInput);

    EXPECT_EQ(2,testWires.countColor(SimpleWires::RED));
}

TEST(BasicWiresTest, GetColorPos){
    uint16_t testInput[6] = {100,1000,100,1000,100,300};
    SimpleWires testWires(testInput);

    EXPECT_EQ(0,testWires.getColorPos(1,SimpleWires::RED));
    EXPECT_EQ(2,testWires.getColorPos(2,SimpleWires::RED));
    EXPECT_EQ(4,testWires.getColorPos(3,SimpleWires::RED));
    EXPECT_EQ(6,testWires.getColorPos(4,SimpleWires::RED));

}

TEST(BasicWiresTest, GetLastColorPos){
    uint16_t testInput[6] = {100,1000,100,1000,100,300};
    SimpleWires testWires(testInput);

    EXPECT_EQ(4,testWires.getLastColorPos(SimpleWires::RED));
    EXPECT_EQ(5,testWires.getLastColorPos(SimpleWires::WHITE));
    EXPECT_EQ(6,testWires.getLastColorPos(SimpleWires::BLACK));
}

TEST(SolutionTest, ThreeWireTestLastWireWhite){
    //red, blue, white
    uint16_t testInput[6] = {100,1000,500,1000,300,1000};
    SimpleWires testWires(testInput);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestNoMatch){
    //red, red, red
    uint16_t testInput[6] = {100,1000,100,1000,100,1000};
    SimpleWires testWires(testInput);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestTwoBlue){
    //blue, blue, red
    uint16_t testInput[6] = {700,1000,700,1000,100,1000};
    SimpleWires testWires(testInput);

    EXPECT_EQ(2,testWires.calculateSolution());
}



