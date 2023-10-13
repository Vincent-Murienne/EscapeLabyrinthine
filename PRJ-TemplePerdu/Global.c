#include <stdlib.h>

typedef	struct{
	char pseudo[50];
	char arme[50];
	int health;
	signed int damage;
} Character;

typedef struct {
	int damage;
} Trap;

//void cleanConsole() {
//	system("cls");
//}
