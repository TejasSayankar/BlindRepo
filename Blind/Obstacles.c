#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"

time_t t;

void initObstacles(char obstacleBoard[22][22]) {
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			obstacleBoard[i][j] = ' ';
		}
	}
	for (int i = 0; i < 22; i++) {
		obstacleBoard[i][0] = '*';
		obstacleBoard[0][i] = '*';
		obstacleBoard[21][i] = '*';
		obstacleBoard[i][21] = '*';
	}

	srand((unsigned)time(&t));
	int x, y;
	int c=0;
	for (int i = 0; i < 70; i++) {
		x = rand() % 19;
		y = rand() % 19;
		if (c < 25) {
			obstacleBoard[y + 1][x + 1] = 'C';
			c++;
		}
		else {
			obstacleBoard[y + 1][x + 1] = 'X';
		}
	}
}