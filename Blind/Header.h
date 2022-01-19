#pragma once

void initboard(char board[22][22], int x, int y);
void initObstacles(char obstacleBoard[22][22]);
void updateboard(char board[22][22], int x, int y, int xl, int yl);
void printBoard(char board[22][22]);
int type3(char board[22][22], char obstacleBoard[22][22], int xloc, int yloc);
int type1(char board[22][22], char obstacleBoard[22][22], int xloc, int yloc);
int type2(char board[22][22], char obstacleBoard[22][22], int xloc, int yloc);