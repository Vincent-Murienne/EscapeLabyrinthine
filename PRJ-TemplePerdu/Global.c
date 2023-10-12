#include <stdlib.h>

struct Character{
	char pseudo[50];
	char arme[50];
	int health;
	signed int damage;
};

typedef struct {
	int damage;
	int health;
} Trap;

void cleanConsole() {
	system("cls");
}
