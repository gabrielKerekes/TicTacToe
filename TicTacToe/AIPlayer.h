#pragma once
#include <vector>
#include "Player.h"
#include "Point.h"
#include "GameField.h"
#include "MinMax.h"

using namespace std;

class AIPlayer : public Player
{
public:
	AIPlayer();
	AIPlayer(std::string name, char sign);
	~AIPlayer();

	Point move(const GameField &gameField, const Player &opponent);

private:
	vector<Point> getAllPossibleMoves(GameField gameField);
};

