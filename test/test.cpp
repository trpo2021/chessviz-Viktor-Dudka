#include "ctest.h"
#include "lib.h"
#include <stdlib.h>
struct coord {
    char type, x1, x2, sign;
    int y1, y2;
};

CTEST(test_TransX, x)
{
    // Given
    int a = 'a';
    int b = '1';
    // When
    int result = TransX(a);
    // Then
    int expected = 1;
    ASSERT_EQUAL(expected, result);

    result = TransX(b);
    // Then
    expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(test_TransY, y)
{
    // Given
    int a = 'a';
    int b = '1';
    // When
    int result = TransX(b);
    // Then
    int expected = 7;
    ASSERT_EQUAL(expected, result);

    result = TransX(a);
    // Then
    expected = -1;
    ASSERT_EQUAL(expected, result);
}
CTEST(Test_Checktype, type)
{
    char board[9][9]
            = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
               {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    coord testT1, testT2;
    testT1.type = 'R';
    testT2.type = 'r';
    testT1.x1 = testT1.x2 = 'a';
    testT1.y1 = 1;
    testT1.y2 = 8;
    int result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(1, result);
    testT1.type = 'N';
    testT2.type = 'n';
    testT1.x1 = testT1.x2 = 'b';
    result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(1, result);
    testT1.type = 'B';
    testT2.type = 'b';
    testT1.x1 = testT1.x2 = 'c';
    result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(1, result);
    testT1.type = 'Q';
    testT2.type = 'q';
    testT1.x1 = testT1.x2 = 'd';
    result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(1, result);
    testT1.type = 'K';
    testT2.type = 'k';
    testT1.x1 = testT1.x2 = 'e';
    result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(1, result);
    testT1.type = 'B';
    testT2.type = 'b';
    testT1.x1 = testT1.x2 = 'a';
    result = CheckType(board, testT1, testT2);
    ASSERT_EQUAL(0, result);
}
CTEST(Test_CheckRangeX, res)
{
    coord test1, test2;
    test1.x1 = 'a';
    test1.x2 = 'b';
    test2.x1 = 'c';
    test2.x2 = 'd';
    int result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(1, result);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 'h';
    result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(1, result);
    test1.x1 = 't';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 'h';
    result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.x1 = 'e';
    test1.x2 = 't';
    test2.x1 = 'g';
    test2.x2 = 'h';
    result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 't';
    test2.x2 = 'h';
    result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.x1 = 'e';
    test1.x2 = 'f';
    test2.x1 = 'g';
    test2.x2 = 't';
    result = CheckRangeX(test1, test2);
    ASSERT_EQUAL(0, result);
}
CTEST(Test_CheckRangeY, res)
{
    coord test1, test2;
    test1.y1 = 1;
    test1.y2 = 2;
    test2.y1 = 3;
    test2.y2 = 4;
    int result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(1, result);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 8;
    result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(1, result);
    test1.y1 = 10;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 8;
    result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.y1 = 5;
    test1.y2 = 10;
    test2.y1 = 7;
    test2.y2 = 8;
    result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 10;
    test2.y2 = 8;
    result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(0, result);
    test1.y1 = 5;
    test1.y2 = 6;
    test2.y1 = 7;
    test2.y2 = 10;
    result = CheckRangeY(test1, test2);
    ASSERT_EQUAL(0, result);
}