#include "AIPlayer.h"

AIPlayer::AIPlayer()
{
}

AIPlayer::AIPlayer(string name, char sign)
{
	mName = name;
	mType = Player::M_AI;
	mSign = sign;
	mId = rand() % 10000;
	mLastMove = Point(-1, -1);
}

AIPlayer::~AIPlayer()
{
}

Point AIPlayer::move(const GameField &gameField, const Player &opponent)
{
	int row = -1;
	int column = -1;
	int fieldSize = gameField.getSize();
	Point point(-1, -1);

	if (gameField.getSize() > 3)
	{
		do
		{
			row = -1;
			column = -1;

			while (row < 0 || row > fieldSize - 1)
			{
				row = rand() % fieldSize;
			}

			while (column < 0 || row > fieldSize - 1)
			{
				column = rand() % fieldSize;
			}
		} while (gameField.getField(row, column) != GameField::M_EMPTY_CHAR);

		point = Point(row, column);
	}
	else
	{
		MinMax minMax(*this, opponent);
		minMax.minMax(gameField, *this, opponent, 0);
		point = minMax.getBestMove();
		mLastMove = point;
	}
	return point;
}

vector<Point> AIPlayer::getAllPossibleMoves(GameField gameField)
{
	int i, j;
	vector<Point> possibleMoves(0);

	for (i = 0; i < gameField.getSize(); i++)
	{
		for (j = 0; j < gameField.getSize(); j++)
		{
			if (gameField.isEmpty(i, j))
			{
				possibleMoves.push_back(Point(i, j));
				cout << i << " " << j << endl;
			}
		}
	}

	return possibleMoves;
}
