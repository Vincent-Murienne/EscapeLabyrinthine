#include "Launcher.h"
#include <stdio.h>

struct PlayerCharacter
{
	char name[50];
	int health;
	int damage;
	char weapon[50];
} Character;

typedef struct {
	int damage;
	int health;
} Trap;




void Launch()
{
	/*Character player;*/
	int game = 0;
	//scanf_s("%c", &player.name);
}

void ExitApp()
{
	printf("Exiting...\n");
	/*exit(0);*/
}



void MainMenu()
{

	enum MenuButtons {
		Load_Game = 1,
		Exit
	};

	int MenuChoice = 2;

	enum MenuButtons MyMenu = MenuChoice;


	switch (MenuChoice)
	{
	case Load_Game:
		Launch();
		break;
	case Exit:
		ExitApp();
		break;
	default:
		printf("Invalid choice\n");
		break;
	};


	printf("Welcome to the Launcher!\n");
	printf("1. Launch a game\n");
	printf("2. Exit\n");
}
