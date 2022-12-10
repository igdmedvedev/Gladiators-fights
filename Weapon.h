#pragma once
#include "Characteristics.h"

class Weapon
{
protected:
	float damage;

public:
	Weapon(float damage) { this->damage = damage; }

	virtual float makeDamage() { return damage; }
};

class SteelSword : public Weapon, public Accuracy, public Crit
{
public:
	SteelSword() : Weapon(15), Accuracy(75), Crit(90, 1.3) {}

	virtual float makeDamage() {
		printf("Weapon damage: %.2f;", damage);
		return isHit() ? getCritFactor() * damage : 0; 
	}
};
class Saber : public Weapon
{
public:
	Saber() : Weapon(12.5) {}
};

