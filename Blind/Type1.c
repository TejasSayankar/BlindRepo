#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"

/*struct endpoint {
	int xl;
	int yl;
};

struct endpoint end;


void initEnd(char obstacleBoard[22][22]) {
	end.xl = 20;
	end.yl = 1;
}*/

int type1(char board[22][22], char obstacleBoard[22][22], int xloc, int yloc) {
	initboard(board, xloc, yloc);
	initObstacles(obstacleBoard);
	//initEnd(obstacleBoard);
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
		updateboard(board, xloc, yloc, 20, 1);
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
			printf("You can move..");
		}
		if (obstacleBoard[yloc][xloc] == 'X') {
			printf("\nGame Over");
			printf("\nPress Any Key to Go To Main Menu");
			_getch();
			return 1;
		}
		if (xloc == 20 && yloc == 1) {
			printf("\nYou Win.");
			printf("\nPress Any Key to Go To Main Menu");
			_getch();
			return 1;
		}
		ch = _getch();
	}
}