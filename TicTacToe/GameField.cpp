#include "GameField.h"

GameField::GameField() : GameField(3, 3)
{
}

GameField::GameField(int fieldSize) : GameField(fieldSize, 3)
{
}

GameField::GameField(int fieldSize, int neededToWin)
{
	mFieldSize = fieldSize;
	mNeededToWin = neededToWin;
	mPadding = neededToWin - 1;
	mFieldSizeWithPadding = mFieldSize + 2 * mPadding;
	mNumOfFilled = 0;

	mFields = vector<vector<char>>(mFieldSizeWithPadding, std::vector<char>(mFieldSizeWithPadding, M_EMPTY_CHAR));
}

GameField::~GameField()
{
}

int GameField::getSize() const
{
	return mFieldSize;
}

void GameField::setSize(int fieldSize)
{
	mFieldSize = fieldSize;
}

int GameField::getSizeWithPadding() const
{
	return mFieldSizeWithPadding;
}

void GameField::setSizeWithPadding(int fieldSizeWithPadding)
{
	mFieldSizeWithPadding = fieldSizeWithPadding;
}

char GameField::getField(int row, int column) const
{
	row += mPadding;
	column += mPadding;

	return mFields[row][column];
}

void GameField::setField(int row, int column, char c)
{
	row += mPadding;
	column += mPadding;

	if (c == M_EMPTY_CHAR)
	{
		decNumOfFilled();
	}
	else
	{
		incNumOfFilled();
	}

	mFields[row][column] = c;
}

void GameField::setField(Point point, char c)
{	
	setField(point.getY(), point.getX(), c);
}

int GameField::getNeededToWin() const
{
	return mNeededToWin;
}

void GameField::setNeededToWin(int neededToWin)
{
	mNeededToWin = neededToWin;
}

int GameField::getPadding() const
{
	return mPadding;
}

void GameField::setPadding(int padding)
{
	mPadding = padding;
}

int GameField::getNumOfFilled() const
{
	return mNumOfFilled;
}

void GameField::setNumOfFilled(int numOfFilled)
{
	mNumOfFilled = numOfFilled;
}

int GameField::incNumOfFilled()
{
	mNumOfFilled++;
	return mNumOfFilled;
}

int GameField::decNumOfFilled()
{
	mNumOfFilled--;
	return mNumOfFilled;
}

void GameField::print() const
{
	cout << endl << endl;
	//print the column numbers
	printLeftMargin(24);
	for (int i = 0 + mPadding; i < mFieldSize + mPadding; i++)
	{
		cout << " " << i + 1 - mPadding;
	}
	cout << endl;
	//print the game field
	for (int i = 0 + mPadding; i < mFieldSize + mPadding; i++)
	{
		printLeftMargin(M_LEFT_MARGIN_SIZE);
		for (int j = 0; j < mFieldSize; j++)
		{
			cout << "__";
		}
		cout << "_" << endl;

		//-2 because numbers get printed here too
		printLeftMargin(M_LEFT_MARGIN_SIZE - 2);
		cout <<  i + 1 - mPadding << " |";
		for (int j = 0 + mPadding; j < mFieldSize + mPadding; j++)
		{
			cout << mFields[i][j] << "|";
		}
		cout << endl;
	}

	printLeftMargin(M_LEFT_MARGIN_SIZE);
	for (int j = 0; j < mFieldSize; j++)
	{
		cout << "__";
	}

	cout << "_" << endl << endl;
}

void GameField::printLeftMargin(int size) const
{
	for (int i = 0; i < size; i++)
	{
		cout << " ";
	}
}

bool GameField::isEmpty(int row, int column) const
{
	row += mPadding;
	column += mPadding;

	if (mFields[row][column] == M_EMPTY_CHAR)
	{
		return true;
	}

	return false;
}

bool GameField::isFull() const
{
	for (int row = 0; row < mFieldSize; row++)
	{
		for (int column = 0; column < mFieldSize; column++)
		{
			if (isEmpty(row, column))
			{
				return false;
			}
		}
	}

	return true;
}

vector<Point> GameField::getPossibleMoves() const
{
	vector<Point> possibleMoves;

	for (int row = 0; row < mFieldSize; row++)
	{
		for (int column = 0; column < mFieldSize; column++)
		{
			if (isEmpty(row, column))
			{
				possibleMoves.push_back(Point(row, column));
			}
		}
	}

	return possibleMoves;
}