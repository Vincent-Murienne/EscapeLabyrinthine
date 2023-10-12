#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Global.h"


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

//void cleanConsole() {
//	system("cls");
//}

int menu()
{
	int rep;
	Character Joueur;

	//Character Zombie("Zombie","Point",50, 50);

	// SI point de vie < 0 alors game over
	// Voulez-vous retourner à l'accueil ?
	// Si oui, alors menu() + sleep(2000)
	// Si non, alors printf("Merci d'avoir joué) + sleep(2000) + exit(0)

	printf("Bienvenue dans Le Defi Du Labyrinthe.\n\ Dans ce jeu vous alllez choisir a parcourir des chemins qui pourront vous emmeneze vers un tresor");
	printf("\n\Voulez vous..\n\ 1 Commencer \n\ 2 Rester sur cette page\n\ ");
	scanf("%d", &rep);

	if (rep == 1)
	{
		printf("Avant de commencer, veuillez choisir un pseudo : \n");
		scanf("%s", Joueur.pseudo);
		printf("\nBienvenue, %s ! Maintenant vous devriez choisir une arme.\n", Joueur.pseudo);
		printf(" Arc\n\ Epee\n\ Hache \n");
		scanf("%s", Joueur.arme); 


		// Tant que l'utilisateur n'a pas choisi une arme valide, il doit rechoisir une arme

		while (strcmp(Joueur.arme, "Arc") != 0 && strcmp(Joueur.arme, "Epee") != 0 && strcmp(Joueur.arme, "Hache") != 0)
		{
			printf("Votre arme n'existe pas \n");
			printf(" Arc\n\ Epee\n\ Hache \n");
			scanf("%s", Joueur.arme);
		}
		
		printf("Vous avez choisie l'arme : %s", Joueur.arme);
		printf("\n Tout est bon, la partie peut commencer !");
		Sleep(2000);
		cleanConsole();
	}
	else if (rep == 2)
	{
		printf("\nProgramme termine.\n");
		exit(0);
	}
	else {
		printf("\nCette option n'existe pas veuillez choisir 1 ou 2");
	}
	return 0;
}
