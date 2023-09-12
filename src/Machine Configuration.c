/*
	Name: Slot Machine Configuration v1.0
	Copyright: All Rights Reserved...
	Author: Bryan James T. Ilaga
	Date: 13/12/14 23:41
	Description: A slot machine game.
*/

/*
	Error Code List:
	0x000064 --> Menu
	0x0000C8 --> Luck Andjustment Input
	0x00012C --> Restart Program Algorithm
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <dos.h>

#define MAX_SIZE 1000

int cfgMenu (int clrbuffer);
int fnMore (void);
void cfgSplasher (void);
void adjLuck (FILE *SM_Cfg);
void adjSpeed (FILE *SM_Cfg);
void adjLights (FILE *SM_Cfg);
void mach_reset (FILE *SM_Cfg);
void clearlog (void);

int main (int argc, char *argv[])
	{
		FILE *SM_Cfg;
		char charFileCheck [MAX_SIZE];
		char strSeek [MAX_SIZE];
		int menu;
		int clrbuffer = 0;
		int intLuck = 0;
		int intCounter = 0;
		int intMore = 0;
		
		startmenu:;
		system ("cls");
		cfgSplasher ();
		menu = cfgMenu (clrbuffer);
		
		SM_Cfg = fopen ("SMConfig.ini", "a+");
		if (fgets (charFileCheck, MAX_SIZE, SM_Cfg) == "\0" || "") {
			mach_reset (SM_Cfg);
		}
		fclose (SM_Cfg);
		
		if (menu != 0) {
			
			if (menu == 1) {
				adjLuck (SM_Cfg);
			}
			else if (menu == 2) {
				//adjSpeed (SM_Cfg);
			}
			else if (menu == 3) {
				//adjLights (SM_Cfg);
			}
			else if (menu == 4) {
				mach_reset (SM_Cfg);
			}
			else if (menu == 5) {
				
			}
			else if (menu == 6) {
				
			}
			else if (menu == 7) {
				
			}
			/* else if (menu == 8) {
				
			} */
			else {
				printf ("\t\t\tAn BUG has been Found!\n\t\t\tError Code: 0x000064\n\t\t\tPlease contact the author.\n\t\t\tThank You!");
				exit (EXIT_FAILURE);
			}
		}
		else {
			clrbuffer++;
			goto startmenu;
		}
		
		intMore = fnMore ();
		
		switch (intMore) {
			
			case 0: goto startmenu; break;
			case 1: break;
			default: printf ("\t\t\tAn BUG has been Found!\n\t\t\tError Code: 0x00012C\n\t\t\tPlease contact the author.\n\t\t\tThank You!");
		}
		
		/*
		SM_Cfg = fopen ("SMConfig.ini", "r+");
			for (intCounter = 0; intCounter < MAX_SIZE; intCounter++) {
				fgets (strSeek, MAX_SIZE, SM_Cfg);
				if (strncmp (strSeek, "Luck=", 5) == 0) {
					printf("return value: %d", strncmp (strSeek, "Luck=", 5));
				}
				else {
					
				}
			}
		fclose (SM_Cfg); */
		
		return (EXIT_SUCCESS);
	}
	
void cfgSplasher (void) {
	
	system ("title Slot Machine Configuration");
	system ("mode 84, 25");
	system ("color 01");
	printf("    ___  __    _____  ____    __  __    __    ___  _   _  ____  _  _  ____  \n");    
    printf("   / __)(  )  (  _  )(_  _)  (  \\/  )  /__\\  / __)( )_( )(_  _)( \\( )( ___)  \n");   
    printf("   \\__ \\ )(__  )(_)(   )(     )    (  /(__)\\( (__  ) _ (  _)(_  )  (  )__)  \n");     
    printf("   (___/(____)(_____) (__)   (_/\\/\\_)(__)(__)\\___)(_) (_)(____)(_)\\_)(____)  \n");   
  	printf("  ___  _____  _  _  ____  ____  ___  __  __  ____    __   ____  ____  _____  _  _ \n");
	printf(" / __)(  _  )( \\( )( ___)(_  _)/ __)(  )(  )(  _ \\  /__\\ (_  _)(_  _)(  _  )( \\( ) \n");
	printf("( (__  )(_)(  )  (  )__)  _)(_( (_-. )(__)(  )   / /(__)\\  )(   _)(_  )(_)(  )  ( \n");
 	printf(" \\___)(_____)(_)\\_)(__)  (____)\\___/(______)(_)\\_)(__)(__)(__) (____)(_____)(_)\\_) \n\n");
 	
}

int cfgMenu (int clrbuffer) {
	
	int letonum;
	char letmenu = '\0';
	
	printf("\t\t\t    +-----------------+\n");
	printf("\t\t\t    |a. Adjust Luck   |\n");
	printf("\t\t\t    |b. Adjust Speed  |\n");
	printf("\t\t\t    |c. Adjust Lights |\n");
	printf("\t\t\t    |d. Reset Machine |\n");
	printf("\t\t\t    |e. Clear Logs    |\n");
	printf("\t\t\t    |f. About         |\n");
	printf("\t\t\t    |g. Exit          |\n");
	printf("\t\t\t    +-----------------+\n");
	printf("\t\t\t    %c%c ", 196, 16);
	if (clrbuffer % 2 != 0) {
		while (getchar () != '\n');
		scanf ("%c", &letmenu);
	}
	scanf ("%c", &letmenu);
	
	switch (letmenu) {
		
		case 'a': letonum = 1; break;
		case 'A': letonum = 1; break;
		case 'b': letonum = 2; break;
		case 'B': letonum = 2; break;
		case 'c': letonum = 3; break;
		case 'C': letonum = 3; break;
		case 'd': letonum = 4; break;
		case 'D': letonum = 4; break;
		case 'e': letonum = 5; break;
		case 'E': letonum = 5; break;
		case 'f': letonum = 6; break;
		case 'F': letonum = 6; break;
		case 'g': letonum = 7; break;
		case 'G': letonum = 7; break;
		// case 'h': letonum = 8; break;
		// case 'H': letonum = 8; break;
		default: printf("\t\t\t Invalid Input! Please try again!\n"); system("timeout>null /t 3 /NOBREAK"); letonum = 0; break;
	}
	
	return (letonum);
}

int fnMore (void) {
	char charRestart;
	
	qa:;
	cfgSplasher ();
	fflush(stdin);
	printf("\t\t\t\tEnd Configuration? (y/n)\n\t\t\t\t%c%c  ", 196, 16);
	scanf("%c", &charRestart);
	
	if (charRestart == 'y' || charRestart == 'Y' || charRestart == 'n' || charRestart == 'N') {
		if (charRestart == 'y' || charRestart == 'Y') {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		printf("\t\t\t\tInvalid Input! Please try again!\n");
		getch();
		goto qa;
	}
}

void adjLuck (FILE *SM_Cfg) {
	
	adjluckstart:;
	int intLuck = 0;
	system("cls");
	cfgSplasher ();
	printf("\n\n\t\t\t\t%c Adjust LUCK %c\n\n", 5, 5);
	printf("\t\t   [First Number] Enter a number from 0 - 100\n\t\t\t\t%c%c ", 196, 16);
	scanf("%d", &intLuck);
	
	if (intLuck < 0 && intLuck > 100) {
		if (intLuck > 0 && intLuck < 100) {
			printf ("\t\t\tAn BUG has been Found!\n\t\t\t\tError Code: 0x0000C8\n\t\t\t\tPlease contact the author.\n\t\t\t\tThank You!");
		}
		printf("\t\t\t\tWarning! Number must be 0 to 100 only!");
		system("timeout>null /t 2 /NOBREAK");
		goto adjluckstart;
	}
	else {
		
	}
	
}

void mach_reset (FILE *SM_Cfg) {
	SM_Cfg = fopen ("SMConfig.ini", "w+");
		fprintf(SM_Cfg, "[Slot Machine Configuration]\n");
		fprintf(SM_Cfg, "Luck1=30\n");
		fprintf(SM_Cfg, "Luck2=40\n");
		fprintf(SM_Cfg, "Luck3=10\n");
		fprintf(SM_Cfg, "Speed=100\n");
		fprintf(SM_Cfg, "Lights=1\n");
	fclose (SM_Cfg);
	
	printf("\t\t\tReset Succeeded!");
	getch();
}
