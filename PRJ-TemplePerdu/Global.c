typedef struct {
	char name[50];
	int health;
	int damage;
	char weapon[50];
	char typeAttack[];
} Character;

typedef struct {
	int damage;
	int health;
} Trap;