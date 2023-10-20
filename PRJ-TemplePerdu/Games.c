#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Global.h"
#include "windows.h"
#include "Launcher.h"
#define ROWS 7
#define COLS 7

int Games() {

    Character Joueur = { "%s", "%s", 100, 20 };
    Character Zombie = { "%s", "%s", 20, 20 };
    Trap Pic = { 10 };
    Trap Falaise = { 100 };

    // Définition du labyrinthe : 0 = chemin, 1 = mur

    int labyrinthe[ROWS][COLS] = {
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
    };

    int visite[ROWS][COLS] = { 0 }; // Tableau pour garder trace des cases visitées
    int carte[2] = { 5, 5 }; // Position de la carte
    int position_joueur[2] = { 0, 0 }; // Position du joueur
    int objectif[2] = { 3, 0 }; // Position de l'objectif
    while (position_joueur[0] != objectif[0] || position_joueur[1] != objectif[1]) {
        for (int i = 0; i < ROWS; ++i) { 
            for (int j = 0; j < COLS; ++j) {
                if (i == position_joueur[0] && j == position_joueur[1]) {
                    printf(" P "); // Afficher la position du joueur
                }
                else if (visite[i][j] == 1) {
                    printf(" %d ", labyrinthe[i][j]); // Afficher la valeur de la case visitée
                }
                else if (position_joueur[0] == carte[0] && position_joueur[1] == carte[1]) {
                    if (i == objectif[0] && j == objectif[1]) {
                        printf(" A "); // Afficher la position de l'objectif
                    }
                    else {
                        printf(" %d ", labyrinthe[i][j]); // Afficher la valeur de la case sur la carte
                    }
                }
                else if (labyrinthe[i][j] == 0) {
                    printf(" - "); // Afficher "-" sur les cases vides
                }
                else {
                    printf(" # "); // Afficher "1" sur les murs
                }
            }
            printf("\n");
        }

        if ((position_joueur[0] == 1 && position_joueur[1] == 0) ||
            (position_joueur[0] == 4 && position_joueur[1] == 3) ||
            (position_joueur[0] == 0 && position_joueur[1] == 3))
        {
            printf("\nUn Zombie apparait, il a l'air coriace !!\n");

            Joueur.health -= Zombie.damage;
            Zombie.health -= Joueur.damage;

            printf("\nIl a reussit a vous toucher et a vous retirer : %d points de vie ", Zombie.damage);
            printf("\nVous reussissez a infliger une attaque ! : %d points de degats\n", Joueur.damage);

            if (Joueur.health > 0)
            {
                printf("\nFelicitations ! Vous avez vaincu le zombie !\n");
                printf("Points de vie actuel : %d\n", Joueur.health);
            }

			if (Joueur.health <= 0) 
            {
                printf("\nOh non ! Son attaque etait mortelle, vous venez de perdre le combat ...\n");
                printf("\nVous avez perdu la partie\n");
                printf("\nVoulez-vous retourner a l'acceuil?\n1-Oui\n2-Non\n");

                int reponse = 0;
                scanf("%d", &reponse);

                if (reponse == 1) {

                    // Code pour revenir au menu principal
                    cleanConsole();
                    position_joueur[0] = 0;
                    position_joueur[1] = 0;
                    memset(visite, 0, sizeof(visite));
                    menu();
                }
                else if (reponse == 2) {
                    printf("Merci d'avoir joue, a bientot");
                    Sleep(2000);
                    exit(0);
                }

                Joueur.health = 100;
            }
        }

        else if ((position_joueur[0] == 2 && position_joueur[1] == 2) ||
            (position_joueur[0] == 4 && position_joueur[1] == 0) ||
            (position_joueur[0] == 3 && position_joueur[1] == 6) ||
            (position_joueur[0] == 5 && position_joueur[1] == 6) ||
            (position_joueur[0] == 6 && position_joueur[1] == 0))
        {
            Joueur.health -= Pic.damage;
            printf("Oh non, vous avez marche sur un pic !\n");
            printf("\nVous avez perdu %d points de vie ...\n", Pic.damage);
            printf("Points de vie actuel : %d\n", Joueur.health);
            if (Joueur.health <= 0)
            {
                printf("\nVous avez perdu la partie\n");
                printf("\nVoulez-vous retourner a l'acceuil?\n1-Oui\n2-Non\n");

                int reponse = 0;
                scanf("%d", &reponse);

                if (reponse == 1) {

                    // Code pour revenir au menu principal
                    cleanConsole();
                    position_joueur[0] = 0;
                    position_joueur[1] = 0;
                    memset(visite, 0, sizeof(visite));
                    menu();
                }
                else if (reponse == 2) {
                    printf("Merci d'avoir joue, a bientot");
                    Sleep(2000);
                    exit(0);
                }

                Joueur.health = 100;

            }

        }

        else if ((position_joueur[0] == 2 && position_joueur[1] == 4) ||
            (position_joueur[0] == 4 && position_joueur[1] == 1))
        {
            int reponse = 0;
            printf("Oh non !! Vous venez de tomber maladroitement du haut d'une falaise !!\n");
            Joueur.health -= Falaise.damage;
            printf("La chute etait fatal !!\n");
            printf("\nVous avez perdu la partie\n");
            printf("\nVoulez-vous retourner a l'acceuil?\n1-Oui\n2-Non\n");

            scanf("%d", &reponse);

            if (reponse == 1) {

                // Code pour revenir au menu principal
                cleanConsole();
                position_joueur[0] = 0;
                position_joueur[1] = 0;
                memset(visite, 0, sizeof(visite));
                menu();
        
            }
            else if (reponse == 2) {
                printf("Merci d'avoir joue, a bientot");
                Sleep(2000);
                exit(0);
            }

            Joueur.health = 100;

        }

        visite[position_joueur[0]][position_joueur[1]] = 1; // Marque la case comme visitée

        if (position_joueur[0] == carte[0] && position_joueur[1] == carte[1]) {
            printf("\n");
            printf("Bravo, vous avez trouve une carte! !\n");
            printf("Il semblerait qu'elle est capable d'indiquer ou se trouve le tresor.\n");
            printf("\n");
        }
        
        printf("\nEntrez votre prochaine direction (haut : 1, bas : 2, gauche : 3, droite : 4) : ");

        //int direction = 0;
        //scanf(" %d", &direction);
        char direction;
        scanf(" %c", &direction);

        cleanConsole(); // Nettoie la console

        switch (direction) {
            case '1':
                if (position_joueur[0] > 0 && labyrinthe[position_joueur[0] - 1][position_joueur[1]] != 1) {
                    position_joueur[0]--;
                }
                break;
            case '2':
                if (position_joueur[0] < ROWS - 1 && labyrinthe[position_joueur[0] + 1][position_joueur[1]] != 1) {
                    position_joueur[0]++;
                }
                break;
            case '3':
                if (position_joueur[1] > 0 && labyrinthe[position_joueur[0]][position_joueur[1] - 1] != 1) {
                    position_joueur[1]--;
                }
                break;
            case '4':
                if (position_joueur[1] < COLS - 1 && labyrinthe[position_joueur[0]][position_joueur[1] + 1] != 1) {
                    position_joueur[1]++;
                }
                break;
            default:
                printf("Deplacement invalide. Essayez une autre direction.\n");
                break;
        }
    }
    printf("Vous avez trouve le tresor !\n");
    printf("\nVous decidez de l'ouvrir et decouvrez une arme et des milliers de lingots d'or !\n");
    printf("\nFelicitations, vous avez gagne la partie !\n");
    
    return 0;

}


// Evolution possible de jeu : Vrai interface graphique (SDL, SFML, etc.), sauvegarde de la partie, système de combat plus poussé, etc.
// Vrai impact choix des armes sur les combats
// Ajouter des objets à ramasser (potion de vie, potion de force, etc.)
// Ajouter des ennemis plus puissants (boss, etc.)
// Ajouter des énigmes
// Ajouter des pièges
// Ajouter des coffres
// Ajouter des portes à ouvrir avec des clés
// Ajouter des niveaux
// Ajouter des quêtes
// Ajouter des PNJ
// Ajouter des dialogues
// Ajouter des choix
// Ajouter des fins différentes
// Ajouter des statistiques
// Ajouter des sorts
// Ajouter des compétences

