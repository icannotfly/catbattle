#pragma once

#include <iostream>
#include <string>
#include <time.h> //for seeding rand()

using namespace std;

class AttackType
{
private:
	string name;
	string presentTense;
	int minDamage = 0;
	int maxDamage = 0;

public:
	AttackType();
	AttackType(string iname, string presentTense, int imin, int imax);

	//returns a damage amount for this attack
	int calcDamage() const;

	//returns the name of this attack
	string getName() const;

	//returns the present tense verb form of this attack
	string getPresentTense() const;
};
