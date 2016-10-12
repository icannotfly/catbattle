#pragma once

#include <iostream>
#include <string>
#include "attackType.h"

#define NUM_MAX_ATTACKS 4

using namespace std;

class Cat
{
private:
	string name = "unnamed";
	int healthCurrent = 10;
	int healthMax = 10;
	int exp = 0;
	AttackType attacks[NUM_MAX_ATTACKS];

	//stats
	int wins = 0;
	int losses = 0;
	float winLossRatio = 0.0;

public:
	Cat();

	//returns the name of this cat
	string getName() const;

	//sets the name of this cat
	void setName(string newName);

	//returns the current health of this cat
	int getHealthCurrent() const;

	//sets the current health of this cat
	void setHealthCurrent(int newHealth);

	//returns true only if we're currently alive
	bool isAlive() const;

	//returns our maximum health
	int getHealthMax() const;

	//prints health, optional bool shows name before hp display
	string getHealth(bool bShowName = true) const;

	//performs an attack against the given cat
	void attack(Cat * victim, AttackType * attackToUse);

	//returns the attack at the given index; will return nullptr if passed out-of-bounds index
	AttackType* getAttack(int index);

	//takes damage, returns true if still alive, false if dead
	bool takeDamage(int damage, Cat * instigator);

	//
	void handleDeath();

	//give experience to this cat, returns true if level up
	bool giveExp(int expAmount);

	//
	int getWins() const;

	//
	void addWin();

	//
	int getLosses() const;

	//
	void addLoss();

	//
	float getWinLossRatio() const;

	//decides on an attack to use, either at random if bIsHumanControlled == false or via player input if its true; returns index of chosen attack
	int chooseAttack(bool bIsHumanControlled = false);
};
