#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Global.h"

int menu()
{

	unsigned int reponse;
	Character Joueur;

	printf("Bienvenue dans Le Defi Du Labyrinthe.\n");
	printf("Dans ce jeu, vous incarnerez un aventurier intrepide qui a decouvert un ancien temple mystique perdu depuis des siecles.");
	printf("\nCe temple est repute pour ses tresors legendaires, mais aussi pour les pieges mortels qui l'y protegent.");
	printf("\nVotre but : Explorer le temple et surmonter les obstacles pour atteindre le tresor legendaire.\n");
	printf("\n\Voulez vous..\n\ 1 Commencer le jeu\n\ 2 Quitter l'application\n\ ");

	scanf("%d", &reponse);

	if (reponse == 1)
	{
		printf("\nAvant de commencer, veuillez choisir un pseudo :\n");
		printf("\nChoisissez votre pseudo :\n");
		scanf("%s", Joueur.pseudo);
		printf("\nBienvenue, %s ! Maintenant vous devriez choisir une arme.\n", Joueur.pseudo);
		printf("\nArc\n\Epee\n\Hache\n");
		printf("\nQuelle arme souhaitez-vous choisir ? \n");
		scanf("%s", Joueur.arme);


		// Tant que l'utilisateur n'a pas choisi une arme valide, il doit rechoisir une arme

		while (strcmp(Joueur.arme, "Arc") != 0 && strcmp(Joueur.arme, "Epee") != 0 && strcmp(Joueur.arme, "Hache") != 0)
		{
			cleanConsole();
			printf("Votre arme n'existe pas\n");
			printf("\nQuelle arme souhaitez-vous choisir ? \n");
			printf("\nArc\n\Epee\n\Hache\n");
			scanf("%s", Joueur.arme);
		}

		printf("\nVous avez choisie l'arme : %s", Joueur.arme);
		printf("\nTout est bon, la partie peut commencer !");
		Sleep(2000);
		cleanConsole();
	}
	else if (reponse == 2)
	{
		printf("\nJeu termine.\n");
		printf("Au plaisir de vous revoir !\n");
		exit(0);
	}
	else {
		printf("\nCette option n'existe pas veuillez choisir 1 ou 2");
	}
	return 0;
}
