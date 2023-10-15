#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "Global.h"

//void choisirArme() {
//	printf("Choisissez votre arme : ");
//	scanf("%s", Joueur.arme); // Demande au joueur de saisir le nom de l'arme
//}
//
//void choisirPseudo() {
//	printf("Choisissez votre pseudo : ");
//	scanf("%s", Joueur.pseudo); // Demande au joueur de saisir un pseudo
//}
////
//Character Joueur = {
//	.pseudo = "Joueur",
//	.arme = "Epée",
//	.health = 100,
//	.damage = 10
//};

struct Character{
	char pseudo[50];
	char arme[50];
	unsigned int health;
	unsigned int damage;
};

struct Trap{
	unsigned int damage;
};

void cleanConsole()
{
	system("cls");
}
