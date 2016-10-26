#include "cat.h"
#include "attackType.h"

using namespace std;

Cat::Cat()
{
	attacks[0] = AttackType("scratch", "scratches", 1, 2);
	attacks[1] = AttackType("maul", "mauls", 2, 3);
}

string Cat::getName() const
{
	return name;
}

void Cat::setName(string newName)
{
	name = newName;
}

int Cat::getHealthCurrent() const
{
	return healthCurrent;
}

void Cat::setHealthCurrent(int newHealth)
{
	healthCurrent = newHealth;
}

bool Cat::isAlive() const
{
	return healthCurrent > 0;
}

int Cat::getHealthMax() const
{
	return healthMax;
}

string Cat::getHealth(bool bShowName) const
{
	string r = "";

	if (bShowName)
	{
		r = name;
		r += ": ";
	}
	r += to_string(healthCurrent);
	r += " / ";
	r += to_string(healthMax);

	return r;
}

void Cat::attack(Cat * victim, AttackType * attackToUse)
{
	//TODO perform chance to hit calculations here

	//base damage from attack
	int attackDamage = attackToUse->calcDamage();

	//TODO damage modifiers

	cout << getName() << " " << attackToUse->getPresentTense() << " " << victim->getName() << " for " << attackDamage << " damage!" << endl;

	victim->takeDamage(attackDamage, this);
}

AttackType* Cat::getAttack(int index)
{
	if (index < NUM_MAX_ATTACKS)
	{
		return &(attacks[index]);
	}
	
	return nullptr;
}

bool Cat::takeDamage(int damage, Cat * instigator)
{
	healthCurrent -= damage;
	bool bSurvived = true;

	if (healthCurrent < 0)
	{
		healthCurrent = 0;
		bSurvived = false;
	}

	string msg = "";
	msg += name;
	msg += " took ";
	msg += to_string(damage);
	msg += " damage from ";
	msg += instigator->getName();

	if (bSurvived)
	{
		msg += ".";
	}
	else
	{
		msg += " and died!";
	}

	//cout << msg << endl;

	return bSurvived;
}

void Cat::handleDeath()
{
	cout << "DEBUG-- i died!";
}

bool Cat::giveExp(int expAmount)
{
	exp += expAmount;
	cout << getName() << " got " << expAmount << " exp!" << endl;
	cout << getName() << " has " << exp << " exp." << endl;

	if (false)
	{
		cout << name << " leveled up!" << endl;
	}

	return false;
}

int Cat::getWins() const
{
	return wins;
}

void Cat::addWin()
{
	wins++;
}

int Cat::getLosses() const
{
	return losses;
}

void Cat::addLoss()
{
	losses++;
}

float Cat::getWinLossRatio() const
{
	return winLossRatio;
}

int Cat::chooseAttack(bool bIsHumanControlled)
{
	if (bIsHumanControlled)
	{
		//if human, prompt player for attack

		cout << "Available attacks:" << endl;
		for (int i = 0; i < NUM_MAX_ATTACKS; i++)
		{
			if (getAttack(i) != nullptr && getAttack(i)->getName() != "")
			{
				cout << i+1 << ") " << getAttack(i)->getName() << endl;
			}
		}

		//get input
		int playerInput = -1;
		bool bInputValid = false;

		cout << "Choose an attack: ";
		cin >> playerInput;
		bInputValid = cin.good();

		while (!bInputValid || playerInput >= NUM_MAX_ATTACKS || playerInput <= 0)
		{
			cout << "Invalid input; please choose a valid attack: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // http://stackoverflow.com/a/12722150
			
			//try again
			cin >> playerInput;
			bInputValid = cin.good();
		}

		return playerInput - 1; //return INDEX of chosen attack, not the human readable id
	}
	else
	{
		//if cpu, decide at random

		return 2;
	}

	return -1;
}
