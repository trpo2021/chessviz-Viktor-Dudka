#include "lib.h"
#include <iostream>
using namespace std;

struct coord {
    char type, x1, x2, sign;
    int y1, y2;
};
int TransX(char x)
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
int TransY(int y)
{
    switch (y) {
    case 1:
        return y = 7;
    case 2:
        return y = 6;
    case 3:
        return y = 5;
    case 4:
        return y = 4;
    case 5:
        return y = 3;
    case 6:
        return y = 2;
    case 7:
        return y = 1;
    case 8:
        return y = 0;
    default:
        return y = -1;
    }
}

void row()
{
    for (int i = 0; i < 17; ++i)
        cout << "-";
    cout << endl;
}
void out_board(char board[9][9])
{
    row();
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    row();
}

void Motion(char board[9][9], coord str)
{
    board[TransY(str.y2)][TransX(str.x2)]
            = board[TransY(str.y1)][TransX(str.x1)];
    board[TransY(str.y1)][TransX(str.x1)] = ' ';
}

int CheckRangeX(coord first, coord second)
{
    if (TransX(first.x1) != 0 && TransX(first.x2) != 0 && TransX(second.x1) != 0
        && TransX(second.x2) != 0)
        return 1;
    return 0;
}
int CheckRangeY(coord first, coord second)
{
    if (TransY(first.y1) != -1 && TransY(first.y2) != -1
        && TransY(second.y1) != -1 && TransY(second.y2) != -1)
        return 1;
    return 0;
}
int CheckType(char board[9][9], coord first, coord second)
{
    if (first.type == board[TransY(first.y1)][TransX(first.x1)]
        && second.type == board[TransY(second.y1)][TransX(second.x1)])
        return 1;
    return 0;
}