#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include "cat.h"

using namespace std;

//do battle with another cat; returns true if player won the battle
bool doBattle(Cat *player, Cat *opponent);

//returns a random number within the given range
int randRange(int min, int max);
