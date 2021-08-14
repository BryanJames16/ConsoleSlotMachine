/*
	Name: Slot Machine v1.0
	Copyright: All Rights Reserved...
	Author: Bryan James T. Ilaga
	Date: 27/11/14 18:43
	Description: A slot machine game.
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>

#define MAX_LINE 9999
#define MAX_SIZE 1000
#define MAX_LOOP 450

void inSystem (void);
void fnSlotMachine (void);
void scrMachine (int intCount1, int intCount2, int arrNum[]);
void docWriter (FILE *SM_Logs, int intCount1, int arrNum[]);

int main (int argc, char *argv[]) 
	{
		
		fnSlotMachine ();
		
		return (EXIT_SUCCESS);
	}
	
void fnSlotMachine (void) {
	FILE *SM_Logs;
	FILE *SM_Cfg;
	int arrNum[4], intCount1 = 0, intCount2 = 0, intLuck = 0, intSpeed = 0, intLights = 0; 
	char again; 
		     	
	system("cls");
	begin:;
		     	
	srand(time(NULL));
		     	
	inSystem ();
	scrMachine (intCount1, intCount2, arrNum);
	docWriter (SM_Logs, intCount1, arrNum);
		     	
	getch();
		
	fnSlotMachine ();
	
	return;
}

void inSystem (void) {
	system("color 0E");
	system("mode 25, 15");
	system("title Slot Machine");
	
	return;
}

void scrMachine (int intCount1, int  intCount2, int arrNum[]) {
	
	for (intCount1 = 0; intCount1 < MAX_LOOP; intCount1++) {
		
		system("cls");	
				     	
		if (intCount1 < 100) {
			arrNum[0] = 1 + rand() % 9;
		}
		else if (intCount1 > 100 && intCount1 < 150) {
			if (intCount1 % 2 == 0) {
				arrNum[0] = 1+ rand() % 9;
			}
		}
			
		if (intCount1 < 200) {
			arrNum[1] = 1 + rand() % 9;
		}
		else if (intCount1 > 200 && intCount1 < 250) {
			if (intCount1 % 2 == 0) {
				arrNum[1] = 1+ rand() % 9;
			}
		}
				     	
		if (intCount1 < 300) {
			arrNum[2] = 1 + rand() % 9;
		}
		else if (intCount1 > 300 && intCount1 < 350) {
			if (intCount1 % 2 == 0) {
				arrNum[2] = 1+ rand() % 9;
			}
		}
			
		if (intCount1 < 400) {
			arrNum[3] = 1 + rand() % 9;
		}
		else if (intCount1 > 400 && intCount1 < 450) {
			if (intCount1 % 2 == 0) {
				arrNum[3] = 1+ rand() % 9;
			}
		}
			
		if (intCount1 % 2 == 0) {
				printf("  *_*_*_*_*_*_*_*_*\n");
				printf(" /_________________\\\n");	     	
				printf(" %c ._. ._. ._. ._. %c\n", 179, 179);
				printf(" %c %c%d%c %c%d%c %c%d%c %c%d%c %c __\n", 179, 179, arrNum[0], 179, 179, arrNum[1], 179, 179, arrNum[2], 179, 179, arrNum[3], 179, 179);
				printf(" %c %c_%c %c_%c %c_%c %c_%c %c%c__%c\n", 179, 179, 179, 179, 179, 179, 179,179, 179, 179, 192, 217);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c\n", 179, 218,  196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 179, 179, 179);
				printf(" %c%c  Slot Machine %c%c%c%c%c\n", 179, 179, 179, 179, 196, 217, 179);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 179, 196, 196, 217);				
				printf("  \\\\             //\n");
				printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'z'+64, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 186);
				printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'z'+64, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 186);
				printf("  //             \\\\\n");
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 179, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177,177,179, 179);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
		}
		else {
				printf("  0_0_0_0_0_0_0_0_0\n");
				printf(" /_________________\\\n");	     	
				printf(" %c ._. ._. ._. ._. %c\n", 179, 179);
				printf(" %c %c%d%c %c%d%c %c%d%c %c%d%c %c __\n", 179, 179, arrNum[0], 179, 179, arrNum[1], 179, 179, arrNum[2], 179, 179, arrNum[3], 179, 179);
				printf(" %c %c_%c %c_%c %c_%c %c_%c %c%c__%c\n", 179, 179, 179, 179, 179, 179, 179,179, 179, 179, 192, 217);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c\n", 179, 218,  196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 179, 179, 179);
				printf(" %c%c  Slot Machine %c%c%c%c%c\n", 179, 179, 179, 179, 196, 217, 179);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217, 179, 196, 196, 217);				
				printf("  \\\\             //\n");
				printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'z'+64, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 186);
				printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'z'+64, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 186);
				printf("  //             \\\\\n");
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 179, 179, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177,177,179, 179);
				printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
		}
	}
	
	return;
}

void docWriter (FILE *SM_Logs, int intCount1, int arrNum[]) {
		SM_Logs = fopen("SM_Logs.TXT","a+");
		fprintf(SM_Logs, "Combination: ");
		for (intCount1 = 0; intCount1 < 4; intCount1++) {
			fprintf(SM_Logs, "%d ", arrNum[intCount1]);
		}
		fprintf(SM_Logs, "\n");
		fclose (SM_Logs);
		
	return;
}
