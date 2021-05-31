#pragma once
struct coord;
int TransX(char x);
int TransY(int y);
void row();
void out_board(char board[9][9]);
void Motion(char board[9][9], coord str);
int CheckRangeX(coord first, coord second);
int CheckRangeY(coord first, coord second);
int CheckType(char board[9][9], coord first, coord second);