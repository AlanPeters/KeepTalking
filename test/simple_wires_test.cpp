#include "SimpleWiresLib.h"
#include "gtest/gtest.h"

#define RED     SimpleWires::RED
#define WHITE   SimpleWires::WHITE
#define BLUE    SimpleWires::BLUE
#define YELLOW  SimpleWires::YELLOW
#define BLACK   SimpleWires::BLACK
#define OFF     SimpleWires::OFF


TEST(BasicWiresTest, CountWires)
{
    uint16_t testInput[6] = { RED, RED, RED, RED, RED, RED };
    SimpleWires testWires (testInput, 0);

    EXPECT_EQ(6, testWires.countColor(RED));
}

TEST(ThreeWireTest, CountWires)
{
    uint16_t testInput[6] = {OFF,RED,WHITE,OFF,OFF,RED};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(2,testWires.countColor(RED));
}

TEST(BasicWiresTest, GetColorPos){
    uint16_t testInput[6] = {RED,OFF,RED,OFF,RED,WHITE};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(0,testWires.getColorPos(1,RED));
    EXPECT_EQ(2,testWires.getColorPos(2,RED));
    EXPECT_EQ(4,testWires.getColorPos(3,RED));
    EXPECT_EQ(6,testWires.getColorPos(4,RED));
}

TEST(BasicWiresTest, GetLastColorPos){
    uint16_t testInput[6] = {RED,OFF,RED,OFF,RED,WHITE};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.getLastColorPos(RED));
    EXPECT_EQ(5,testWires.getLastColorPos(WHITE));
    EXPECT_EQ(6,testWires.getLastColorPos(BLACK));
}

TEST(SolutionTest, ThreeWireTestLastWireWhite){
    //red, blue, white
    uint16_t testInput[6] = {RED,OFF,BLUE,OFF,WHITE,OFF};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestNoMatch){
    //red, red, red
    uint16_t testInput[6] = {RED,OFF,RED,OFF,RED,OFF};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, ThreeWireTestTwoBlue){
    //blue, blue, red
    uint16_t testInput[6] = {BLUE,OFF,BLUE,OFF,RED,OFF};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestTwoRedOdd){
    //blue, blue, red, red
    uint16_t testInput[6] = {BLUE,OFF,BLUE,RED,RED,OFF};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestNoRedLastYellow){
    //blue, blue, black,yellow
    uint16_t testInput[6] = {BLUE,OFF,BLUE,BLACK,OFF,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestExactlyOneBlue){
    //white, red, blue,yellow
    uint16_t testInput[6] = {OFF,WHITE,RED,BLUE,OFF,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(1,testWires.calculateSolution());
}

TEST(SolutionTest, FourWiresTestMoreThanOneYellow){
    //white, red, yellow,yellow
    uint16_t testInput[6] = {OFF,WHITE,RED,YELLOW,OFF,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(5,testWires.calculateSolution());

}

TEST(SolutionTest, FourWiresTestNoMatch){
    //white, white, white, white
    uint16_t testInput[6] = {OFF,WHITE,WHITE,WHITE,WHITE,OFF};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestLastBlackOdd){
    //Blue, Red, Black, White, Black
    uint16_t testInput[6] = {BLUE,OFF,RED,BLACK,WHITE,BLACK};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(4,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestLastBlackEven){
    //Blue, Red, Black, White, Black
    uint16_t testInput[6] = {BLUE,OFF,RED,BLACK,WHITE,BLACK};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestOneRedTwoYellow){
    //Blue, Red, Black, Yellow, Yellow
    uint16_t testInput[6] = {BLUE,RED,OFF,BLACK,YELLOW,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(0,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestNoBlack){
    //Blue, Blue, Blue, Yellow, Yellow
    uint16_t testInput[6] = {BLUE,OFF,BLUE,BLUE,YELLOW,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, FiveWiresTestNoMatch){
    //Black, Blue, Blue, Yellow, Yellow
    uint16_t testInput[6] = {OFF,BLACK,BLUE,BLUE,YELLOW,YELLOW};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(1,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestNoYellowOdd){
    //Black, Blue, Blue, Red, Black, Red
    uint16_t testInput[6] = {BLACK,BLUE,BLUE,RED,BLACK,RED};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(2,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestNoYellowEven){
    //Black, Blue, Blue, Red, Black, Red
    uint16_t testInput[6] = {BLACK,BLUE,BLUE,RED,BLACK,RED};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(3,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestOneYellowNoWhite){
    //Black, Yellow, Blue, Red, Black, Red
    uint16_t testInput[6] = {BLACK,YELLOW,BLUE,RED,BLACK,RED};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(3,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestOneYellowManyWhite){
    //White, Yellow, Blue, Red, Black, White
    uint16_t testInput[6] = {WHITE,YELLOW,BLUE,RED,BLACK,WHITE};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(3,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestNoRed){
    //White, Yellow, Yellow, Blue, White, White
    uint16_t testInput[6] = {WHITE,YELLOW,YELLOW,BLUE,WHITE,WHITE};
    SimpleWires testWires(testInput, 1);

    EXPECT_EQ(5,testWires.calculateSolution());
}

TEST(SolutionTest, SixWiresTestNoMatch){
    //Black, Blue, Blue, Red, Black, Red
    uint16_t testInput[6] = {BLACK,BLUE,BLUE,RED,BLACK,RED};
    SimpleWires testWires(testInput, 0);

    EXPECT_EQ(3,testWires.calculateSolution());
}
