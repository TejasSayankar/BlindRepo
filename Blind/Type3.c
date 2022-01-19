#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"



struct endpoint {
	int xl;
	int yl;
};

time_t t;
struct endpoint end[5];

void initEnd(char obstacleBoard[22][22]) {
	srand((unsigned)time(&t));
	int i = 0;
	while (i < 5) {
		end[i].xl = (rand() % 19 + 1);
		end[i].yl = (rand() % 19 + 1);
		if (obstacleBoard[end[i].yl][end[i].xl] != 'X') {
			i++;
		}
	}
}

int type3(char board[22][22], char obstacleBoard[22][22], int xloc, int yloc) {
	initboard(board, xloc, yloc);
	initObstacles(obstacleBoard);
	initEnd(obstacleBoard);
	char ch;
	int c = 0;
	system("cls");
	printBoard(board);
	ch = _getch();
	while (ch != 'q') {
		system("cls");
		board[yloc][xloc] = '=';
		if (ch == 'a') {
			if (xloc > 1) {
				xloc--;
			}
		}
		else if (ch == 'd') {
			if (xloc < 20) {
				xloc++;
			}
		}
		else if (ch == 'w') {
			if (yloc > 1) {
				yloc--;
			}
		}
		else if (ch == 's') {
			if (yloc < 20) {
				yloc++;
			}
		}
		updateboard(board, xloc, yloc, end[c].xl, end[c].yl);
		printBoard(board);
		if (obstacleBoard[yloc][xloc - 1] == 'X' || obstacleBoard[yloc][xloc + 1] == 'X' || obstacleBoard[yloc + 1][xloc] == 'X' || obstacleBoard[yloc - 1][xloc] == 'X') {
			int o = 0;
			if (obstacleBoard[yloc][xloc - 1] == 'X') {
				o++;
			}
			if (obstacleBoard[yloc][xloc + 1] == 'X') {
				o++;
			}
			if (obstacleBoard[yloc + 1][xloc] == 'X') {
				o++;
			}
			if (obstacleBoard[yloc - 1][xloc] == 'X') {
				o++;
			}
			printf("%d Obstacle Nearby..", o);
		}
		else {
			printf("\nYou can move..");
		}
		if (obstacleBoard[yloc][xloc] == 'X') {
			printf("\nGame Over");
			printf("\nPress Any Key to Go To Main Menu");
			_getch();
			return 1;
		}
		if (xloc == end[c].xl && yloc == end[c].yl) {
			c++;
			updateboard(board, xloc, yloc, end[c].xl, end[c].yl);
		}
		if (c == 5) {
			printf("\nYou Win.");
			printf("\nPress Any Key to Go To Main Menu");
			_getch();
			return 1;
		}
		ch = _getch();
	}
}