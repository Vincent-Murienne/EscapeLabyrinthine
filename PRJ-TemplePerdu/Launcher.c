#define _CRT_SECURE_NO_WARNINGS
#include "Launcher.h"
#include <stdio.h>
#include <stdlib.h>


int menu()
{
	int rep;
	char pseudo[50], arme[50];
	printf("Bienvenue dans Le Defi Du Labyrinthe.\n\ Dans ce jeu vous alllez choisir a parcourir des chemins qui pourront vous emmeneze vers un tresor");
	printf("\n\Voulez vous..\n\ 1 Commencer \n\ 2 Rester sur cette page\n\ ");
	scanf("%d", &rep);
	printf("Vous avez choisie l'option %d", rep);

	if (rep == 1)
	{
		printf("\n\Entrez votre pseudo : ");
		scanf("%s", pseudo);
		printf("\n\Bienvenue, %s !maintenant vous devriez choisir une arme.\n", pseudo);
		printf(" Arc\n\ hjjjk\n\ hkjh\n");
		scanf("%s", arme);
		printf("la partie sera lancee dans quelques secondes");


	}
	else if (rep == 2)
	{


		printf("\n\Vous restez sur cette page.\n");
		exit(0);

	}
	else {
		printf("\n\Cette option n'existe pas veuillez choisir 1 ou 2");
	}
	return 0;
}