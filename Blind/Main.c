#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Header.h"

char board[22][22], obstacleBoard[22][22];
int xloc=1, yloc=20;
int x, y;
int e = 0;
int c = 0;
int i = 0;

#include <time.h> 

void delay(int t)
{
	// Converting time into milli_seconds 
	int milli_seconds = 100 * t;

	// Storing start time 
	clock_t start_time = clock();

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds)
		;
}

void main() {
	char ch;
	char welcome[]="Hello,\nWelcome to Blind....\nPress Any Key To Play";
	char loading[] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tLoading";
	char dot[] = "..............................";
	i = 0;
	while (welcome[i] != '\0') {
		delay(1);
		printf("%c", welcome[i]);
		i++;
	}
	ch=_getch();
	system("cls");
	i = 0;
	printf("%s", loading);
	while (dot[i] != '\0') {
		delay(2);
		printf("%c", dot[i]);
		i++;
	}
	
	do {
		system("cls");
		printf("\n\nSelect the game type: ");
		printf("\n\na. Reach the Destination");
		printf("\nb. Complete Milestones");
		printf("\nc. Travel");
		printf("\n\n\n\n\n\nPress Q to Quit.");
		ch = _getch();
		switch (ch) {
		case 'a':
			type1(board, obstacleBoard, xloc, yloc);
			break;
		case 'b':
			type2(board, obstacleBoard, xloc, yloc);
			break;
		case 'c':
			type3(board, obstacleBoard, xloc, yloc);
			break;
		case 'q':
			exit(0);
		default:
			printf("Wrong Choice...\nTry Again");
		}
	} while (1);
	
}