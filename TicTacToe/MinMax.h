#pragma once
#include <algorithm>
#include <vector>
#include "Player.h"
#include "Point.h"
#include "GameField.h"

using namespace std;

class Game;

class MinMax
{
public:
	MinMax();
	MinMax::MinMax(Player player, Player opponent);
	~MinMax();

	Point getBestMove();
	void setBestMove(Point bestMove);

	int calculateScore(const int winnerId, const int &depth);
	int minMax(GameField gameField, Player player, Player opponent, int depth);
	bool handleFirstTwoMoves(const GameField &gameField, const Player &opponent);

	Point mBestMove;
	
	Player mPlayer;
	Player mOpponent;
};