#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"

void initboard(char board[22][22],int x,int y) {

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			board[i][j] = ' ';
		}
	}

	for (int i = 0; i < 22; i++) {
		board[0][i] = '*';
		board[i][0] = '*';
		board[21][i] = '*';
		board[i][21] = '*';
	}
	board[y][x] = 'O';
}

void updateboard(char board[22][22],int x,int y,int xl,int yl) {
	board[y][x] = 'O';
	board[yl][xl] = '#';
}

void printBoard(char board[22][22]) {
	printf("Board: \n");
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			printf("  %c", board[i][j]);
		}
		printf("\n");
	}
}