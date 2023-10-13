#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
//#include "Global.h"
#include "Launcher.h"
#include "Global.c"
#define ROWS 5
#define COLS 5

//int Parcours() {
//
//    char chemin[50];
//
//    printf("Après avoir ouvert les portes de ce temple, 3 chemins vous sont accessibles :\n");
//    printf("Le premier est sombre et lugubre, le second en face de vous semble assez lumineux et enfin celui à votre droite rencontre un étrange brouillard.\n");
//    printf("Quel chemin souhaitez-vous emprunter ? (Sombre | Lumineux | Brumeux): ");
//
//    fgets(chemin, sizeof(chemin), stdin);
//    chemin[strcspn(chemin, "\n")] = '\0'; // Supprime le caractère de nouvelle ligne ajouté par fgets
//
//
//    // strcmp() permet de comparer deux chaînes de caractères
//
//    if (strcmp(chemin, "Sombre") == 0) {
//        printf("Vous avez donc emprunté le chemin : %s\n", chemin);
//    }
//    else if (strcmp(chemin, "Lumineux") == 0) {
//        printf("Vous avez donc emprunté le chemin : %s\n", chemin);
//    }
//    else if (strcmp(chemin, "Brumeux") == 0) {
//        printf("Vous avez donc emprunté le chemin : %s\n", chemin);
//    }
//    else {
//        printf("Le chemin indiqué semble inaccessible, veuillez choisir l'un de ces 3 chemins.\n");
//    }
//
//    return 0;
//}

//int Games(){  
//       // Character Joueur;
//   // Character Zombie;
//   // Joueur.health = 100;
//   // Zombie.health = 50;
//    Character Joueur = { "%s", "%s", 100, 10 };
//    Character Zombie = { "%s", "%s", 50, 5 };
//
//
//
//
//
//    // Définition du labyrinthe
//    int labyrinthe[ROWS][COLS] = {
//        {0, 0, 0, 0, 1},
//        {0, 0, 1, 0, 1},
//        {1, 0, 0, 0, 0},
//        {0, 1, 0, 1, 1},
//        {0, 0, 0, 0, 1}
//    };
//
//    // 0 = chemin
//    // 1 = mur
//    
//    
//    // Position de départ du joueur
//    int position_joueur[2] = {0,0};
//
//    // Position de l'objectif
//    int objectif[2] = {3,0};
//
//    // Boucle principale du jeu   
//
//    // /* Problème à régler --> L'affichage du labyrinthe se fait en boucle
//    // + message d'erreur qui s'affiche alors qu'il devrait pas mais si on arrive au bout message de victoire qui
//    // s'affiche */
//
//    while (position_joueur[0] != objectif[0] || position_joueur[1] != objectif[1]) {
//        // Afficher le labyrinthe
//        for (int i = 0; i < ROWS; ++i) {
//            for (int j = 0; j < COLS; ++j) {
//                if (i == position_joueur[0] && j == position_joueur[1]) {  // position_joueur[0] = ligne et position_joueur[1] = colonnes
//                    printf("P "); // Position du joueur
//                }
//                else if (i == objectif[0] && j == objectif[1]) {
//                    printf("O "); // Position de l'objectif
//                }
//                else {
//                    printf("%d ", labyrinthe[i][j]); // Afficher le labyrinthe
//                }
//            }
//            printf("\n");
//
//        }
int Games() {
    // Character Joueur;
 // Character Zombie;
 // Joueur.health = 100;
 // Zombie.health = 50;
    Character Joueur = { "%s", "%s", 100, 20 };
    Character Zombie = { "%s", "%s", 10, 10 };
    Trap Pic = { 10 };



    // Définition du labyrinthe
    int labyrinthe[ROWS][COLS] = {
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1}
    };

    // 0 = chemin
    // 1 = mur


    // Position de départ du joueur
    int position_joueur[2] = { 0,0 };

    // Position de l'objectif
    int objectif[2] = { 3,0 };

    // Boucle principale du jeu   

    // /* Problème à régler --> L'affichage du labyrinthe se fait en boucle
    // + message d'erreur qui s'affiche alors qu'il devrait pas mais si on arrive au bout message de victoire qui
    // s'affiche */

    while (position_joueur[0] != objectif[0] || position_joueur[1] != objectif[1]) {
        // Afficher le labyrinthe
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (i == position_joueur[0] && j == position_joueur[1]) {  // position_joueur[0] = ligne et position_joueur[1] = colonnes
                    printf("P "); // Position du joueur
                }
                else if (i == objectif[0] && j == objectif[1]) {
                    printf("O "); // Position de l'objectif
                }
                else {
                    printf("%d ", labyrinthe[i][j]); // Afficher le labyrinthe
                }
            }
            printf("\n");
        }
        // if ((position_joueur[0] == 1 && position_joueur[1] == 0) ||
    // (position_joueur[0] == 4 && position_joueur[1] == 3) ||
    // (position_joueur[0] == 0 && position_joueur[1] == 3)) {
    // printf("%s ,tu es sur le point d'affronter le zombie .\n",Joueur.pseudo);
    // printf("Vous venez de perdre 20 points de vie.\n");
    // if (Joueur.health < 100) {
         //Joueur.health -= 20;
        // if (Joueur.health > 100) {
            // Joueur.health = 100;

        if ((position_joueur[0] == 1 && position_joueur[1] == 0) ||
            (position_joueur[0] == 4 && position_joueur[1] == 3) ||
            (position_joueur[0] == 0 && position_joueur[1] == 3))
        {
            printf(" Tu es sur le point d'affronter un zombie.\n");

            int nb_coups = 0;

            while (Zombie.health > 0)
            {
                nb_coups++;
                Joueur.health -= Zombie.damage;
                Zombie.health -= Joueur.damage;
            }

            printf("Tu viens de perdre 20 points de vie.\n");
            printf("PV actuel : %d\n", Joueur.health);
            printf("\n Zombie tue en %d coups", nb_coups);

            if (Joueur.health > 0)
            {
                Joueur.health -= Zombie.damage;
                printf("%d", Joueur.health);

                if (Joueur.health < 0)
                {
                    Joueur.health = 0;
                    printf("Vous avez perdu la partie");
                }
                else if (Joueur.health > 100)
                {
                    Joueur.health = 100;
                }
            }

        }

        if ((position_joueur[0] == 2 && position_joueur[1] == 2) ||
            (position_joueur[0] == 4 && position_joueur[1] == 0))
        {
            printf("Attention il y a un pic sur ce chemin");

            Joueur.health -= Pic.damage;
            //printf("Vous avez perdu %d point\n", Pic.damage);
            printf("\nVous avez actuellement %d pv", Joueur.health);
            printf("\nVous avez perdu %d point\n", Pic.damage);
            if (Joueur.health < 0)
            {
                printf("\nVous avez perdu la partie\n");
            }

        }
        if ((position_joueur[0] == 2 && position_joueur[1] == 4))
        {
            int rep2 = 0;
            printf("Il y a une falaise devant vous\n");
            Joueur.health -= 100;
            printf("\nvous avez perdu la partie");
            printf("\nvoulez vous retourner a l'acceuil?\n\ 1-Oui \n\ 2-Non\n");

            scanf("%d", rep2);
            if (rep2 == 1)
            {

            }
            else if (rep2 == 2)
            {
                printf("Merci d'avoir jouer a bientot");
                Sleep(2000);
            }
        }


            // Demander au joueur de fournir une direction (haut, bas, gauche, droite)
            printf("\nEntrez votre prochaine direction (haut : h, bas : b, gauche : g, droite : d) : ");
            char direction;
            scanf(" %c", &direction);

            // Mettre à jour la position du joueur en fonction de la direction
            switch (direction) {
            case 'h':
                if (position_joueur[0] > 0 && labyrinthe[position_joueur[0] - 1][position_joueur[1]] != 1) {
                    position_joueur[0]--;
                    cleanConsole();
                }
                break;
            case 'b':
                if (position_joueur[0] < ROWS - 1 && labyrinthe[position_joueur[0] + 1][position_joueur[1]] != 1) {
                    position_joueur[0]++;
                    cleanConsole();
                }
                break;
            case 'g':
                if (position_joueur[1] > 0 && labyrinthe[position_joueur[0]][position_joueur[1] - 1] != 1) {
                    position_joueur[1]--;
                    cleanConsole();
                }
                break;
            case 'd':
                if (position_joueur[1] < COLS - 1 && labyrinthe[position_joueur[0]][position_joueur[1] + 1] != 1) {
                    position_joueur[1]++;
                    cleanConsole();
                }
                break;
            default:
                printf("Déplacement invalide. Essayez une autre direction.\n");
                break;
            }
        }

        //printf("Felicitations! Vous avez atteint l'objectif!\n");


        return 0;

    }

    //    // Demander au joueur de fournir une direction (haut, bas, gauche, droite)
    //    printf("Entrez votre prochaine direction (haut : h, bas : b, gauche : g, droite : d ) ");
    //    char direction;
    //    scanf(" %c", &direction);

    //    // Mettre à jour la position du joueur en fonction de la direction
    //    switch (direction) {
    //    case 'h':
    //        if (position_joueur[0] > 0 && labyrinthe[position_joueur[0] - 1][position_joueur[1]] != 1) {
    //            position_joueur[0]--;
    //            cleanConsole();
    //        }
    //        break;
    //    case 'b':
    //        if (position_joueur[0] < ROWS - 1 && labyrinthe[position_joueur[0] + 1][position_joueur[1]] != 1) {
    //            position_joueur[0]++;
    //            cleanConsole();
    //        }
    //        break;
    //    case 'g':
    //        if (position_joueur[1] > 0 && labyrinthe[position_joueur[0]][position_joueur[1] - 1] != 1) {
    //            position_joueur[1]--;
    //            cleanConsole();
    //        }
    //        break;
    //    case 'd':
    //        if (position_joueur[1] < COLS - 1 && labyrinthe[position_joueur[0]][position_joueur[1] + 1] != 1) {
    //            position_joueur[1]++;
    //            cleanConsole();
    //        }
    //        break;
    //    default:
    //        printf("Déplacement invalide. Essayez une autre direction.\n");
    //        break;
    //    }
    //}

    //printf("Félicitations! Vous avez atteint l'objectif!\n");

    //return 0;
//}


// Fonction Pointeur
//void test() {
//    int Player = 4;
//    int PlayerAdress = &Player;
//    int* p = &Player;
//
//
//    printf("Player = %d\n", Player);
//    printf("PlayerAdress = %d\n", PlayerAdress);
//    printf("&Player = %d\n", &Player);
//    printf("p = %d\n", *p);
//    printf("p = %p\n", p);
//
//    int Monster = 5;
//    printf(EnnemyAttack(Monster));
//
//	//int a = 5;
//	//int* p = &a;
//	//printf("a = %d\n", a);
//	//printf("p = %d\n", *p);
//	//printf("p = %p\n", p);
//	//printf("&a = %p\n", &a);
//	//printf("&p = %p\n", &p);
//}
//
//int EnnemyAttack(int EnemyHealth)
//{
//    EnemyHealth = EnemyHealth - 1;
//	return EnemyHealth;
//
//}