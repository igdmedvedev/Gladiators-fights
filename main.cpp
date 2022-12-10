#include "Gladiator.h"
#include <iostream>

int main() {
	srand(time(0));
	Gladiator* protagonist = new Knight();
	Gladiator* antoganist = new Pirate();

	while (true) {
		if (protagonist->getHp() <= 0) {
			printf("Knight lose");
			break;
		}
		printf("Knight: ");
		float damage = protagonist->makeDamage();

		printf("Pirate: ");
		antoganist->takeDamage(damage);

		printf("Damage: %f\nHp: %f\n", damage, antoganist->getHp());
		printf("______________________________________________\n");

		if (antoganist->getHp() <= 0) {
			printf("Pirate lose");
			break;
		}
		printf("Pirate: ");
		damage = antoganist->makeDamage();

		printf("Knight: ");
		protagonist->takeDamage(damage);

		printf("Damage: %f\nHp: %f\n", damage, protagonist->getHp());
		printf("______________________________________________\n");
	}
	delete protagonist;
	delete antoganist;

	//getchar();
}