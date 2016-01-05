#include "MinMax.h"
#include "Game.h"

MinMax::MinMax()
{
}

MinMax::MinMax(Player player, Player opponent)
{
	mPlayer = player;
	mOpponent = opponent;
}

MinMax::~MinMax()
{
}

Point MinMax::getBestMove()
{
	return mBestMove;
}

void MinMax::setBestMove(Point bestMove)
{
	mBestMove = bestMove;
}

int MinMax::calculateScore(const int winnerId, const int &depth)
{
	if (winnerId == mPlayer.getId())
	{
		return 10 - depth;
	}
	if (winnerId == mOpponent.getId())
	{
		return depth - 10;
	}
	else
	{
		return 0;
	}
}

int MinMax::minMax(GameField gameField, Player player, Player opponent, int depth)
{
	vector<int> scores(0);
	vector<Point> moves(0);

	if (handleFirstTwoMoves(gameField, opponent))
	{
		return 0;
	}

	int winnerId = Game::CheckGameOver(gameField, player, opponent);
	if (winnerId > -1)
	{
		return calculateScore(winnerId, depth);
	}

	for (int row = 0; row < gameField.getSize(); row++)
	{
		for (int column = 0; column < gameField.getSize(); column++)
		{
			if (gameField.isEmpty(row, column))
			{
				gameField.setField(row, column, player.getSign());
				player.setLastMove(Point(row, column));
				scores.push_back(minMax(gameField, opponent, player, depth + 1));
				gameField.setField(row, column, GameField::M_EMPTY_CHAR);
				moves.push_back(Point(row, column));
			}
		}
	}

	int bestMoveIndex = 0;

	//the player's turn
	if (depth % 2 == 0)
	{
		bestMoveIndex = distance(scores.begin(), max_element(scores.begin(), scores.end()));
	}
	//other player's turn
	else
	{
		bestMoveIndex = distance(scores.begin(), min_element(scores.begin(), scores.end()));
	}
	
	mBestMove = moves[bestMoveIndex];
	return scores[bestMoveIndex];
}

bool MinMax::handleFirstTwoMoves(const GameField &gameField, const Player &opponent)
{
	//if it is the first move play center		
	if (gameField.getNumOfFilled() == 0)
	{
		mBestMove = Point((int) ceil(gameField.getSize() / 2), (int) ceil(gameField.getSize() / 2));
		return true;
	}
	//if it is the second move play diagonally to the opponent
	else if (gameField.getNumOfFilled() == 1)
	{
		if (opponent.getLastMove().getX() <= gameField.getSize() / 2)
		{
			if (opponent.getLastMove().getY() <= gameField.getSize() / 2)
			{
				mBestMove = Point(opponent.getLastMove().getX() + 1, opponent.getLastMove().getY() + 1);
			}
			else
			{
				mBestMove = Point(opponent.getLastMove().getX() + 1, opponent.getLastMove().getY() - 1);
			}
		}
		else
		{
			if (opponent.getLastMove().getY() <= gameField.getSize() / 2)
			{
				mBestMove = Point(opponent.getLastMove().getX() - 1, opponent.getLastMove().getY() + 1);
			}
			else
			{
				mBestMove = Point(opponent.getLastMove().getX() - 1, opponent.getLastMove().getY() - 1);
			}
		}

		return true;
	}

	return false;
}
