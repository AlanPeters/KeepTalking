#include "SimpleWiresLib.h"
#include "gtest/gtest.h"

TEST(BasicWiresTest, CountWires)
{
    uint16_t testInput[6] = { 100, 100, 100, 100, 100, 100 };
    SimpleWires testWires (testInput, 0);

    EXPECT_EQ(6, testWires.countColor(1));
}

TEST(ThreeWireTest, CountWires)
{
    uint16_t testInput[6] = {1000,100,300,1000,1000,101};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(2,testWires.countColor(SimpleWires::RED));
}

TEST(BasicWiresTest, GetColorPos){
    uint16_t testInput[6] = {100,1000,100,1000,100,300};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(0,testWires.getColorPos(1,SimpleWires::RED));
    EXPECT_EQ(2,testWires.getColorPos(2,SimpleWires::RED));
    EXPECT_EQ(4,testWires.getColorPos(3,SimpleWires::RED));
    EXPECT_EQ(6,testWires.getColorPos(4,SimpleWires::RED));

}

TEST(BasicWiresTest, GetLastColorPos){
    uint16_t testInput[6] = {100,1000,100,1000,100,300};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.getLastColorPos(SimpleWires::RED));
    EXPECT_EQ(5,testWires.getLastColorPos(SimpleWires::WHITE));
    EXPECT_EQ(6,testWires.getLastColorPos(SimpleWires::BLACK));
}

TEST(SolutionTest, ThreeWireTestLastWireWhite){
    //red, blue, white
    uint16_t testInput[6] = {100,1000,500,1000,300,1000};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestNoMatch){
    //red, red, red
    uint16_t testInput[6] = {100,1000,100,1000,100,1000};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestTwoBlue){
    //blue, blue, red
    uint16_t testInput[6] = {500,1000,500,1000,100,1000};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestTwoRedOdd){
    //blue, blue, red, red
    uint16_t testInput[6] = {500,1000,500,100,100,1000};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestNoRedLastYellow){
    //blue, blue, black,yellow
    uint16_t testInput[6] = {500,1000,500,900,1000,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestExactlyOneBlue){
    //white, red, blue,yellow
    uint16_t testInput[6] = {1000,300,100,500,1000,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(1,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestMoreThanOneYellow){
    //white, red, yellow,yellow
    uint16_t testInput[6] = {1000,300,100,705,1000,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(5,testWires.calculateSolution());

}

TEST(SolutionTest, FourWiresTestNoMatch){
    //white, white, white, white
    uint16_t testInput[6] = {1000,300,300,305,300,1000};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestLastBlackOdd){
    //Blue, Red, Black, White, Black
    uint16_t testInput[6] = {500,1000,100,800,300,800};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestLastBlackEven){
    //Blue, Red, Black, White, Black
    uint16_t testInput[6] = {500,1000,100,800,300,800};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestOneRedTwoYellow){
    //Blue, Red, Black, Yellow, Yellow
    uint16_t testInput[6] = {500,100,1000,800,700,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestNoBlack){
    //Blue, Blue, Blue, Yellow, Yellow
    uint16_t testInput[6] = {500,1000,500,500,700,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestNoMatch){
    //Black, Blue, Blue, Yellow, Yellow
    uint16_t testInput[6] = {1000,800,500,500,700,700};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(1,testWires.calculateSolution());
}

