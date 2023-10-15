#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Global.h"
#include "windows.h"
#include "Launcher.h"
//#include "Global.c"
#define ROWS 7
#define COLS 7

//int Parcours() {
//
//    char chemin[50];
//
//    printf("Apr�s avoir ouvert les portes de ce temple, 3 chemins vous sont accessibles :\n");
//    printf("Le premier est sombre et lugubre, le second en face de vous semble assez lumineux et enfin celui � votre droite rencontre un �trange brouillard.\n");
//    printf("Quel chemin souhaitez-vous emprunter ? (Sombre | Lumineux | Brumeux): ");
//
//    fgets(chemin, sizeof(chemin), stdin);
//    chemin[strcspn(chemin, "\n")] = '\0'; // Supprime le caract�re de nouvelle ligne ajout� par fgets
//
//
//    // strcmp() permet de comparer deux cha�nes de caract�res
//
//    if (strcmp(chemin, "Sombre") == 0) {
//        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
//    }
//    else if (strcmp(chemin, "Lumineux") == 0) {
//        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
//    }
//    else if (strcmp(chemin, "Brumeux") == 0) {
//        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
//    }
//    else {
//        printf("Le chemin indiqu� semble inaccessible, veuillez choisir l'un de ces 3 chemins.\n");
//    }
//
//    return 0;
//}

int Games() {

    //struct Character Joueur = { "%s", "%s", 100, 20 };
    //printJoueur(Joueur);

    Character Joueur = { "%s", "%s", 100, 20 };
    Character Zombie = { "%s", "%s", 20, 20 };
    Trap Pic = { 10 };
    Trap Falaise = { 100 };



    // D�finition du labyrinthe : 0 = chemin, 1 = mur

    int labyrinthe[ROWS][COLS] = {
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
    };

    int visite[ROWS][COLS] = { 0 }; // Tableau pour garder trace des cases visit�es
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
                    printf(" %d ", labyrinthe[i][j]); // Afficher la valeur de la case visit�e
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

            if (Zombie.health <= 0)
            {
                printf("\nVous reussissez a infliger une attaque ! : %d points de degats\n", Joueur.damage);
				printf("\nFelicitations ! Vous avez vaincu le zombie !\n");
				printf("Points de vie actuel : %d\n", Joueur.health);
			}
			else if (Joueur.health <= 0) 
            {
                printf("\nOh non ! Son attaque etait mortelle, vous venez de perdre le combat ...\n");
                printf("\nVous avez perdu la partie\n");
                exit(0); // Terminer le jeu si le joueur est mort
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
                exit(0);
            }

        }

        else if ((position_joueur[0] == 2 && position_joueur[1] == 4) ||
            (position_joueur[0] == 4 && position_joueur[1] == 1))
        {
            unsigned int reponse = 0;
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

        }

        visite[position_joueur[0]][position_joueur[1]] = 1; // Marque la case comme visit�e

        if (position_joueur[0] == carte[0] && position_joueur[1] == carte[1]) {
            printf("\n");
            printf("Bravo, vous avez trouve une carte! !\n");
            printf("Il semblerait qu'elle est capable d'indiquer ou se trouve le tresor.\n");
            printf("\n");
        }

        printf("\nEntrez votre prochaine direction (haut : h, bas : b, gauche : g, droite : d) : ");
        char direction;
        scanf(" %c", &direction);

        cleanConsole(); // Nettoie la console

        switch (direction) {
            case 'h':
                if (position_joueur[0] > 0 && labyrinthe[position_joueur[0] - 1][position_joueur[1]] != 1) {
                    position_joueur[0]--;
                }
                break;
            case 'b':
                if (position_joueur[0] < ROWS - 1 && labyrinthe[position_joueur[0] + 1][position_joueur[1]] != 1) {
                    position_joueur[0]++;
                }
                break;
            case 'g':
                if (position_joueur[1] > 0 && labyrinthe[position_joueur[0]][position_joueur[1] - 1] != 1) {
                    position_joueur[1]--;
                }
                break;
            case 'd':
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


// Probl�me � r�soudre : Quand j'�cris une chaine de caract�re dans la console qui commence par 'd, g, h, b', le programme se d�place dans la direction correspondante
// Exemple : Je veux �crire "Bonjour", mais le programme se d�place vers la droite car le premier caract�re est 'b'
// Quand j'ai 0 point de vie il y a 0 reset, je peux continuer � jouer
// Quand j'affronte un zombie, je meurs directement
// G�rer le probl�me du Global.h qui ne fonctionne pas avec les structures
// A l'accueil il est possible de skip le choix de l'arme et du pseudo et direct rentrer dans le jeu si on fait d,h,g,b
// Bug des pi�ges qui doit nous tuer mais ne le fait pas + bug message quand on retombe sur le m�me pi�ge d'affil�


// Evolution possible de jeu : Vrai interface graphique (SDL, SFML, etc.), sauvegarde de la partie, syst�me de combat plus pouss�, etc.
// Vrai impact choix des armes sur les combats
// Ajouter des objets � ramasser (potion de vie, potion de force, etc.)
// Ajouter des ennemis plus puissants (boss, etc.)
// Ajouter des �nigmes
// Ajouter des pi�ges
// Ajouter des coffres
// Ajouter des portes � ouvrir avec des cl�s
// Ajouter des niveaux
// Ajouter des qu�tes
// Ajouter des PNJ
// Ajouter des dialogues
// Ajouter des choix
// Ajouter des fins diff�rentes
// Ajouter des statistiques
// Ajouter des sorts
// Ajouter des comp�tences