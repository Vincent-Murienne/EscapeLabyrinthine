#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Global.c"


//void Launch()
//{
//	Character player;
//	int game = 0;
//	//scanf_s("%c", &player.name);
//}
//
//void ExitApp()
//{
//	printf("Exiting...\n");
//	/*exit(0);*/
//}
//
//
//
//void MainMenu()
//{
//
//	enum MenuButtons {
//		Load_Game = 1,
//		Exit
//	};
//
//	int MenuChoice = 2;
//
//	enum MenuButtons MyMenu = MenuChoice;
//
//
//	switch (MenuChoice)
//	{
//	case Load_Game:
//		Launch();
//		break;
//	case Exit:
//		ExitApp();
//		break;
//	default:
//		printf("Invalid choice\n");
//		break;
//	};
//
//
//	printf("Welcome to the Launcher!\n");
//	printf("1. Launch a game\n");
//	printf("2. Exit\n");
//
//}

int menu()
{
	int rep;
	//Character pseudo;
	Character Joueur;
	//Character arme;

	printf("Bienvenue dans Le Defi Du Labyrinthe.\n\ Dans ce jeu vous alllez choisir a parcourir des chemins qui pourront vous emmeneze vers un tresor");
	printf("\n\Voulez vous..\n\ 1 Commencer \n\ 2 Rester sur cette page\n\ ");
	scanf_s("%d", &rep);
	printf("Vous avez choisie l'option %d", rep);

	if (rep == 1)
	{
		printf("\nEntrez votre pseudo : ");
		scanf("%s", Joueur.pseudo);
		printf("\nBienvenue, %s !maintenant vous devriez choisir une arme.\n", Joueur.pseudo);
		printf(" Arc\n hjjjk\n hkjh \n");
		scanf("%s", Joueur.arme);
		printf("la partie sera lancee dans quelques secondes");
	}
	else if (rep == 2)
	{


		printf("\nVous restez sur cette page.\n");
		exit(0);

	}
	else {
		printf("\nCette option n'existe pas veuillez choisir 1 ou 2");
	}
	return 0;
}
