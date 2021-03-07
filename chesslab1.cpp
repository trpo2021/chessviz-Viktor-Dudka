// chesslab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int transy(int y)
{
    switch (y)
    {
    case 1: y = 7; break;
    case 2: y = 6; break;
    case 3: y = 5; break;
    case 4: y = 4; break;
    case 5: y = 3; break;
    case 6: y = 2; break;
    case 7: y = 1; break;
    case 8: y = 0; break;
    }
    return y;
}
int transx(char x)
{
    switch (x)
    {
    case 'a': x = 1; break;
    case 'b': x = 2; break;
    case 'c': x = 3; break;
    case 'd': x = 4; break;
    case 'e': x = 5; break;
    case 'f': x = 6; break;
    case 'g': x = 7; break;
    case 'h': x = 8; break;
    }
    return x;
}
void chert()
{
    for (int i = 0; i < 10; i++)
        cout << "--";
    cout << endl;
}
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

    char x, x1;
    int y, y1;
    char figure,sign,sign1;
    int k = 0;
    while (sign!='#')
    {
   
        link:
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
        chert();
        cout << "Move number:sosati" << k<<endl;       
        cin>>figure>>x >>y>>sign>>x1>>y1;
        if (y > 0 && y < 9 && x>='A' && x <= 'h' && y1>0 && y1 < 9 && x1>='A' && x1 <= 'h')
        {
            y = transy(y);
            y1 = transy(y1);
            x = transx(x);
            x1 = transx(x1);
            if (board[y][x] != figure)
            {
                cout << "Error.Type figure\n";
                goto link;
            }
            if (sign == 'x' && board[y1][x1] == ' ')
            {
                cout << "Error\n";
                goto link;
            }
            else if (sign!='x')
            {
                board[y1][x1] = board[y][x];
                board[y][x] = ' ';
                k++;
                chert();
            }
        }
        else
        {
            cout << "Error. Enter normal coordinates\n";
            goto link;
        }
            
    }
}
/*Тип фигуры, выполняющей ход(король, конь и т.д.).
Поле, с которого сделан ход.
Для тихого хода — дефис(-).Для взятия — буква x.
Поле, на которое сделан ход.
Если пешка совершила превращение, после целевого поля указывается фигура, которой она стала.
Для взятия на проходе — знак e.p. (фр.en passant).
Для шаха — знак плюс(+).Для мата — решётка(#).*/

/*СписокХодов = { ЗаписьХода ПереводСтроки }
ЗаписьХода = НомерХода.Ход Ход
Ход = [ТипФигуры] Поле ТипХода Поле[ТипФигуры | 'e.p.' | '+' | '#']
| Рокировка
ТипФигуры = 'K' | 'Q' | 'R' | 'B' | 'N'
Поле = / [a - h][1 - 8] /
ТипХода = '-' | 'x'
Рокировка = '0-0-0' | '0-0'*/
