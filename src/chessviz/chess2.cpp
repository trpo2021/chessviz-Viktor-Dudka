
#include <iostream>
#include "C:\Users\petru\source\repos\chessviz-Viktor-Dudka\src\libchessviz\lib.h"
using namespace std;

int main()
{

    char board[9][9] = { {'8','r','n','b','q','k','b','n','r'},
                      {'7','p','p','p','p','p','p','p','p'},
                      {'6',' ',' ',' ',' ',' ',' ',' ',' '},
                      {'5',' ',' ',' ',' ',' ',' ',' ',' '},
                      {'4',' ',' ',' ',' ',' ',' ',' ',' '},
                      {'3',' ',' ',' ',' ',' ',' ',' ',' '},
                      {'2','P','P','P','P','P','P','P','P'},
                      {'1','R','N','B','Q','K','B','N','R'},
                      {' ','a','b','c','d','e','f','g','h'},
    };

    char x, x1,x2,x3;
    int y, y1,y2,y3;
    char figure,figure2, sign,sign2;
    int k = 0;
    sign = 0;
    while (1)
    {
        drowboard(board);
        chert();
        cout << "Move number:" << k << endl;
        cin >> figure >> x >> y >> sign >> x1 >> y1;
        cin >> figure2 >> x2 >> y2 >> sign2 >> x3 >> y3;
        if (check(y,y1,y2,y3,x,x1,x2,x3))
        {
            if (check_type(board[transy(y)][transx(x)], board[transy(y2)][transx(x2)],figure,figure2))
            {
                cout << "\nError.Type figure\n";
                break;
            }
            if (check_move_type(sign,sign2,board[transy(y1)][transx(x1)],board[transy(y3)][transx(x3)]))
            {
                cout << "\nError move type\n";
                break;
            }
            if (sign == 'x')
            {
                board[transy(y1)][transx(x1)] = ' ';
                board[transy(y1)][transx(x1)] = board[transy(y)][transx(x)];
                board[transy(y)][transx(x)] = ' ';
                chert();
            }
            if (sign2 == 'x')
            {
                board[transy(y3)][transx(x3)] = ' ';
                board[transy(y3)][transx(x3)] = board[transy(y2)][transx(x2)];
                board[transy(y2)][transx(x2)] = ' ';
                chert();
            }
            if (sign != 'x')
            {
                board[transy(y1)][transx(x1)] = board[transy(y)][transx(x)];
                board[transy(y)][transx(x)] = ' ';
                k++;
                chert();
            }
            if (sign2 != 'x')
            {
                board[transy(y3)][transx(x3)] = board[transy(y2)][transx(x2)];
                board[transy(y2)][transx(x2)] = ' ';
                chert();
            }
        }
        else
        {
            cout << "\nError. Enter normal coordinates\n";
            break;
        }
        k++;
    }
}
