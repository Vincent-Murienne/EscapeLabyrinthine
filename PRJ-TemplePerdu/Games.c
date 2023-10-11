#include <stdio.h>
#include <../EscapeLabyrinthine/PRJ-TemplePerdu/Global.h>

int Parcours() {

    char chemin[50];

    printf("Apr�s avoir ouvert les portes de ce temple, 3 chemins vous sont accessibles :\n");
    printf("Le premier est sombre et lugubre, le second en face de vous semble assez lumineux et enfin celui � votre droite rencontre un �trange brouillard.\n");
    printf("Quel chemin souhaitez-vous emprunter ? (Sombre | Lumineux | Brumeux): ");

    fgets(chemin, sizeof(chemin), stdin);
    chemin[strcspn(chemin, "\n")] = '\0'; // Supprime le caract�re de nouvelle ligne ajout� par fgets


    // strcmp() permet de comparer deux cha�nes de caract�res

    if (strcmp(chemin, "Sombre") == 0) {
        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
    }
    else if (strcmp(chemin, "Lumineux") == 0) {
        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
    }
    else if (strcmp(chemin, "Brumeux") == 0) {
        printf("Vous avez donc emprunt� le chemin : %s\n", chemin);
    }
    else {
        printf("Le chemin indiqu� semble inaccessible, veuillez choisir l'un de ces 3 chemins.\n");
    }

    return 0;
}

//int Games() {
//    // D�finition de la taille du labyrinthe
//#define ROWS 5
//#define COLS 5
//
//// D�finition du labyrinthe
//    int labyrinthe[ROWS][COLS] = {
//        {1, 1, 1, 1, 1},
//        {1, 0, 0, 0, 1},
//        {1, 1, 1, 0, 1},
//        {1, 0, 0, 0, 1},
//        {1, 1, 1, 1, 1}
//    };
//
//    // Position de d�part du joueur
//    int position_joueur[2] = { 1, 1 };
//
//    // Position de l'objectif
//    int objectif[2] = { 3, 3 };
//
//    // Boucle principale du jeu
//    while (position_joueur[0] != objectif[0] || position_joueur[1] != objectif[1]) {
//        // Afficher le labyrinthe
//        for (int i = 0; i < ROWS; ++i) {
//            for (int j = 0; j < COLS; ++j) {
//                if (i == position_joueur[0] && j == position_joueur[1]) {
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
//        }
//
//        // Demander au joueur de fournir une direction (haut, bas, gauche, droite)
//        printf("Entrez votre prochaine direction (haut, bas, gauche, droite) : ");
//        char direction;
//        scanf_s(" %c", &direction);
//
//        // Mettre � jour la position du joueur en fonction de la direction
//        switch (direction) {
//        case 'h':
//            if (position_joueur[0] > 0 && labyrinthe[position_joueur[0] - 1][position_joueur[1]] != 1) {
//                position_joueur[0]--;
//            }
//            break;
//        case 'b':
//            if (position_joueur[0] < ROWS - 1 && labyrinthe[position_joueur[0] + 1][position_joueur[1]] != 1) {
//                position_joueur[0]++;
//            }
//            break;
//        case 'g':
//            if (position_joueur[1] > 0 && labyrinthe[position_joueur[0]][position_joueur[1] - 1] != 1) {
//                position_joueur[1]--;
//            }
//            break;
//        case 'd':
//            if (position_joueur[1] < COLS - 1 && labyrinthe[position_joueur[0]][position_joueur[1] + 1] != 1) {
//                position_joueur[1]++;
//            }
//            break;
//        default:
//            printf("D�placement invalide. Essayez une autre direction.\n");
//            break;
//        }
//    }
//
//    printf("F�licitations! Vous avez atteint l'objectif!\n");
//
//    return 0;
//}