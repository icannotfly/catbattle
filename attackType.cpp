#include "attackType.h"
#include "catbattle.h" // for randRange

using namespace std;

AttackType::AttackType()
{
	name = "";
	presentTense = "attacks";
	minDamage = 1;
	maxDamage = 2;
}

AttackType::AttackType(string iname, string ipresentTense, int imin, int imax)
{
	name = iname;
	presentTense = ipresentTense;
	minDamage = imin;
	maxDamage = imax;
}

int AttackType::calcDamage() const
{
	return randRange(minDamage, maxDamage);
}

string AttackType::getName() const
{
	return name;
}

string AttackType::getPresentTense() const
{
	return presentTense;
}
