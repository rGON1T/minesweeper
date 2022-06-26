#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>
#include "../minesweeper.h"
using namespace std;

TEST(SweeperTest, Test1) {
    MineSweepeer M(2,3);
    ASSERT_EQ(8,M.GetPower(2,3));
    ASSERT_EQ(1,M.GetPower(15794,0));
    ASSERT_EQ(144,M.GetPower(12,2));
}

TEST(SweeperTest, Test2) {
    MineSweepeer M(2,3);
    ASSERT_EQ(5,M.GetNumberOfDigits(12345));
    ASSERT_EQ(1,M.GetNumberOfDigits(0));
    ASSERT_EQ(10,M.GetNumberOfDigits(1234512345));
}
TEST(SweeperTest, Test3) {
    MineSweepeer M(2,3);
    ASSERT_EQ('1',M.GetDigitFromNumber(123,0));
    ASSERT_EQ('0',M.GetDigitFromNumber(0,0));
    ASSERT_EQ('6',M.GetDigitFromNumber(126,2));

}
TEST(SweeperTest, Test4) {
    MineSweepeer M(2,3);
    vector<vector<char>> fr(3, vector<char>(3, '*'));
    vector<vector<char>> bck(3, vector<char>(3, '0'));
    vector<vector<char>> v = {{'*', '0', '*'},{'0', '*', '0'},{'*', '0', '*'}};
    ASSERT_EQ(1,M.Print(fr));
    ASSERT_EQ(1,M.Print(bck));
    ASSERT_EQ(1,M.Print(v));

}
TEST(SweeperTest, Test5) {
    MineSweepeer M(3,3);
    vector<vector<char>> fr(3, vector<char>(3, '*'));
    vector<vector<char>> bck(3, vector<char>(3, '0'));
    vector<vector<char>> v = {{'*', '0', '*'},{'0', '*', '0'},{'*', '0', '*'}};
    ASSERT_EQ(0,M.CountMinesAroundCell(0,0,fr));
    ASSERT_EQ(0,M.CountMinesAroundCell(0,0,bck));
    ASSERT_EQ(3,M.CountMinesAroundCell(0,1,v));
}
TEST(SweeperTest, Test6) {
    int h=10, w=10;
    MineSweepeer M(h,w);
    vector<vector<char>> bck(h, vector<char>(w, '0'));
    M.SetMines(bck, 21);
    ASSERT_EQ(h * w -21,M.GetFreeCells());

}