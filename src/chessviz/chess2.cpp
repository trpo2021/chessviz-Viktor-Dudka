#include "libchessviz\lib.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

struct coord {
    char type, x1, x2, sign;
    int y1, y2;
};

int main()
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
    out_board(board);

    coord first, second;
    while (1) {
        cin >> first.type;
        if (first.type != 'R' && first.type != 'K' && first.type != 'B'
            && first.type != 'Q' && first.type != 'N') {
            first.x1 = first.type;
            first.type = 'P';
            cin >> first.y1 >> first.sign >> first.x2 >> first.y2;
        } else
            cin >> first.x1 >> first.y1 >> first.sign >> first.x2 >> first.y2;

        cin >> second.type;
        if (second.type != 'r' && second.type != 'k' && second.type != 'q'
            && second.type != 'n') {
            second.x1 = second.type;
            second.type = 'p';
            cin >> second.y1 >> second.sign >> second.x2 >> second.y2;
        } else
            cin >> second.x1 >> second.y1 >> second.sign >> second.x2
                    >> second.y2;

        if (CheckType(board, first, second)) {
            if (CheckRangeX(first, second) && CheckRangeY(first, second)) {
                Motion(board, first);
                Motion(board, second);
                out_board(board);
            } else {
                cout << "Error range" << endl;
                break;
            }
        } else {
            cout << "Error type" << endl;
            break;
        }
    }
}