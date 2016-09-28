#include "catbattle.h"

using namespace std;

#define MAX_PLAYER_CATS 1

bool doBattle(Cat *player, Cat *opponent)
{
	cout << player->getName() << " and " << opponent->getName() << " are fighting!" << endl << endl;

	while (player->isAlive() && opponent->isAlive())
	{
		int damage = 0;

		//player goes first
		player->attack(opponent, player->getAttack(0));

		//then opponent
		if (opponent->isAlive())
		{
			opponent->attack(player, opponent->getAttack(0));
		}

		//list health for both
		cout << endl
			<< player->getHealth()
			<< "        "
			<< opponent->getHealth()
			<< endl << endl << endl;

		//announce a winner
		if (!opponent->isAlive() || !player->isAlive())
		{
			Cat * winner = player->isAlive() ? player : opponent;
			Cat * loser = player->isAlive() ? opponent : player;

			cout << "Victory!" << endl << winner->getName() << " won the battle!" << endl;

			if (winner == player) //we dont care about giving exp to the computer
			{
				int expReward = 1;
				winner->giveExp(expReward);
			}

			winner->addWin();
			loser->addLoss();

			cout << player->getName() << "'s win/loss ratio is now " << player->getWins() << ":" << player->getLosses() << endl;
		}
	}

	return true;
}

int randRange(int min, int max)
{
	// http://stackoverflow.com/a/5009006
	return min + (rand() % (int)(max - min + 1));
}

int main()
{
	Cat playerCat[MAX_PLAYER_CATS];

	cout << "-------------" << endl
		<< " Cat Battle! " << endl
		<< "-------------" << endl;

	cout << endl << "Name your cat: ";
	string tempName;
	getline(cin, tempName);
	playerCat[0].setName(tempName);

	bool bShouldContinueFighting = true;
	
	while (bShouldContinueFighting)
	{
		system("cls");

		//spawn a new enemy
		Cat enemy;
		enemy.setName("Bad Guy");

		//replenish health
		playerCat->setHealthCurrent(playerCat->getHealthMax());

		//do battle
		bShouldContinueFighting = doBattle(&playerCat[0], &enemy);

		char userBattleRepeatInput;
		cout << endl << endl << "Fight again? (Y/N)";
		cin >> userBattleRepeatInput;

		if (userBattleRepeatInput != 'y' && userBattleRepeatInput != 'Y')
		{
			bShouldContinueFighting = false;
		}
	}
	
}
