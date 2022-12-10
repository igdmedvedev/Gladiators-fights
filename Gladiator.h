#pragma once
#include "Characteristics.h"
#include "Weapon.h"
#include "Armor.h"

class Gladiator
{
protected:
	float hp, damage, protection;
	Weapon* weapon;
	Armor* armor;
public:
	Gladiator(float hp, float damage, float protection, Weapon* weapon, Armor* armor) {
		this->hp = hp;
		this->damage = damage;
		this->protection = protection;
		this->weapon = weapon;
		this->armor = armor;
	}
	~Gladiator() { delete weapon; delete armor; }
	
	float getHp() { return hp; }

	void setWeapon(Weapon*) { this->weapon = weapon; }
	void setArmor(Armor*) { this->armor = armor; }

	virtual float makeDamage() { return damage + weapon->makeDamage(); }
	virtual void takeDamage(float damage) { hp -= armor->takeDamage(damage) / protection; }
};

class Knight : public Gladiator, public Agility, public Accuracy
{
public:
	Knight() : Gladiator(80, 9, 1, new SteelSword(), new SteelArmor()), Agility(20), Accuracy(75) {}

	virtual float makeDamage() { 
		printf("%.2f: ", damage);
		return (isHit() ? damage : 0) + weapon->makeDamage(); 
	}
	virtual void takeDamage(float damage) { 
		printf("%.2f: ", protection);
		hp -= isMissed() ? 0 : armor->takeDamage(damage) / protection;
	}
	
};

class Pirate : public Gladiator, public Agility, public Accuracy
{
public:
	Pirate() : Gladiator(75, 8, 1, new SteelSword(), new SteelArmor()), Agility(32), Accuracy(90) {}

	virtual float makeDamage() {
		printf("%.2f: ", damage);
		return (isHit() ? damage : 0) + weapon->makeDamage();
	}
	virtual void takeDamage(float damage) {
		printf("%.2f: ", protection);
		hp -= isMissed() ? 0 : armor->takeDamage(damage) / protection;
	}
};

