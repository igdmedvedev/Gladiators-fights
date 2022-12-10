#pragma once
#include <iostream>

class Accuracy {
protected:
	int accuracy;
public:
	Accuracy(int accuracy) { this->accuracy = accuracy; }
	virtual bool isHit() { 
		int tmp = rand() % 101;
		printf("Accuracy: %d; Chance: %d\n", accuracy, tmp);
		return tmp < accuracy ? true : false;
	}
};

class Agility {
protected:
	int agility;
public:
	Agility(int agility) { this->agility = agility; }
	virtual bool isMissed() { 
		int tmp = rand() % 101;
		printf("Agility: %d; Chance: %d\n", agility, tmp);
		return tmp < agility ? true : false; 
	}
};

class Crit {
protected:
	int critChance;
	float critDamage;
public:
	Crit(int critChance, float critDamage) {
		this->critChance = critChance;
		this->critDamage = critDamage;
	}
	virtual float getCritFactor() { 
		int tmp = rand() % 101;
		printf("Crit: %d; Chance: %d\n", critChance, tmp);
		return tmp < critChance ? critDamage : 1;
	}
};