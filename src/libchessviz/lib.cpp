#include "C:\Users\petru\source\repos\chessviz-Viktor-Dudka\src\libchessviz\lib.h"
#include <iostream>
using namespace std;
int transy(int y)
{
    switch (y) {
    case 1:
        return 7;
    case 2:
        return 6;
    case 3:
        return 5;
    case 4:
        return 4;
    case 5:
        return 3;
    case 6:
        return 2;
    case 7:
        return 1;
    case 8:
        return 0;
    default:
        return 0;
    }
}
int transx(char x)
{
    switch (x) {
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 4;
    case 'e':
        return 5;
    case 'f':
        return 6;
    case 'g':
        return 7;
    case 'h':
        return 8;
    default:
        return 0;
    }
}
void chert()
{
    for (int i = 0; i < 10; i++)
        cout << "--";
    cout << endl;
}
int check_type(char board1, char board2, char figure, char figure2)
{
    if (board1 != figure || board2 != figure2)
        return 1;
    return 0;
}
void drowboard(char board[9][9])
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int check(char y, char y1, char y2, char y3, char x, char x1, char x2, char x3)
{
    if (y > 0 && y < 9 && x >= 'A' && x <= 'h' && y1 > 0 && y1 < 9 && x1 >= 'A'
        && x1 <= 'h' && y2 > 0 && y2 < 9 && x2 >= 'A' && x2 <= 'h' && y3 > 0
        && y3 < 9 && x3 >= 'A' && x3 <= 'h')
        return 1;
    return 0;
}

int check_move_type(char sign, char sign2, char board1, char board2)
{
    if ((sign == 'x' && board1 == ' ')
        || (sign2 == 'x' && board2 == ' '))
    return 1;
    return 0;
}
