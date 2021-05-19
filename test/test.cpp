
#define CATCH_CONFIG_MAIN 
#include "C:\Users\petru\source\repos\chessviz-Viktor-Dudka\thirdparty\catch.hpp"
#include "C:\Users\petru\source\repos\chessviz-Viktor-Dudka\src\libchessviz\lib.h"
TEST_CASE("test transx")
{
    REQUIRE(TransX('b') == 2);
    REQUIRE(TransX('h') == 8);
    REQUIRE(TransX(1) == 0);
    REQUIRE(TransX('1') == 0);
}
TEST_CASE("test TransY")
{
    REQUIRE(TransY(1) == 7);
    REQUIRE(TransY('b') == -1);
}
struct coord {
    char type, x1, x2, sign;
    int y1, y2;
};
TEST_CASE("test CheckType")
{
    char board[9][9]
        = { {'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
           {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'} };
    coord testT1, testT2;
    testT1.type = 'R';
    testT2.type = 'r';
    testT1.x1 = testT2.x2 = 'a';
    testT1.y1 = 1;
    testT2.y2 = 8;
    REQUIRE(CheckType(board, testT1, testT2) == 1);
    testT1.type = 'N';
    testT2.type = 'n';
    testT1.x1 = testT2.x2 = 'b';
    REQUIRE(CheckType(board, testT1, testT2) == 1);
    testT1.type = 'B';
    testT2.type = 'b';
    testT1.x1 = testT2.x2 = 'c';
    REQUIRE(CheckType(board, testT1, testT2) == 1);
    testT1.type = 'Q';
    testT2.type = 'q';
    testT1.x1 = testT2.x2 = 'd';
    REQUIRE(CheckType(board, testT1, testT2) == 1);
    testT1.type = 'K';
    testT2.type = 'k';
    testT1.x1 = testT2.x2 = 'e';
    REQUIRE(CheckType(board, testT1, testT2) == 1);
    testT1.type = 'B';
    testT2.type = 'b';
    testT1.x1 = testT2.x2 = 'a';
    REQUIRE(CheckType(board, testT1, testT2) == 0);
}

TEST_CASE("Test CheckRangeX")
{
    coord test1, test2;
    test1.x1 = 'a';
    test1.x2 = 'b';
    test2.x1 = 'c';
    test2.x2 = 'd';
    REQUIRE(CheckRangeX(test1, test2)==1);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 'h';
    REQUIRE(CheckRangeX(test1, test2) == 1);
    test1.x1 = 't';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 'h';
    REQUIRE(CheckRangeX(test1, test2) == 0);
    test1.x1 = 'e';
    test1.x2 = 't';
    test2.x1 = 'g';
    test2.x2 = 'h';
    REQUIRE(CheckRangeX(test1, test2) == 0);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 't';
    test2.x2 = 'h';
    REQUIRE(CheckRangeX(test1, test2) == 0);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 't';
    REQUIRE(CheckRangeX(test1, test2) == 0);
}
TEST_CASE("test CheckRangeY")
{
    coord test1, test2;
    test1.y1 = 1;
    test1.y2 = 2;
    test2.y1 = 3;
    test2.y2 = 4;
    REQUIRE(CheckRangeY(test1, test2) == 1);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 8;
    REQUIRE(CheckRangeY(test1, test2) == 1);
    test1.y1 = 10;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 8;
    REQUIRE(CheckRangeY(test1, test2) == 0);
    test1.y1 = 5;
    test1.y2 = 10;
    test2.y1 = 7;
    test2.y2 = 8;
    REQUIRE(CheckRangeY(test1, test2) == 0);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 10;
    test2.y2 = 8;
    REQUIRE(CheckRangeY(test1, test2) == 0);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 10;
    REQUIRE(CheckRangeY(test1, test2) == 0);
}
