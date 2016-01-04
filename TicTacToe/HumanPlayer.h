#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "GameField.h"

using namespace std;

#pragma once
class HumanPlayer : public Player
{
public:
	HumanPlayer();
	HumanPlayer(std::string name, char sign);
	~HumanPlayer();

	Point move(const GameField &gameField, const Player &opponent);
};
