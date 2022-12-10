#pragma once
#include "Characteristics.h"

class Armor
{
protected:
	float protection;

public:
	Armor(float protection) { this->protection = protection; }

	//float getProtection() { return protection; }
	virtual float takeDamage(float damage) { return damage / protection; }
};

class SteelArmor : public Armor, public Agility
{
public:
	SteelArmor() : Armor(1.7), Agility(5) {}
	virtual float takeDamage(float damage) {
		printf("Armor %.2f: ", protection);
		return isMissed() ? 0 : damage / protection;
	}
};

class ChainMail : public Armor, public Agility
{
public:
	ChainMail() : Armor(1.45), Agility(15) {}
	virtual float takeDamage(float damage) {
		printf("Armor %.2f: ", protection);
		return isMissed() ? 0 : damage / protection;
	}
};

