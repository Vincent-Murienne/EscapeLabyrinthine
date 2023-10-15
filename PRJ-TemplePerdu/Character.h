#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
	char pseudo[50];
	char arme[50];
	unsigned int health;
	unsigned int damage;
} Character;

extern Character Joueur; // D�claration de la variable Joueur comme externe

#endif