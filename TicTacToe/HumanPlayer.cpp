#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
}

HumanPlayer::HumanPlayer(string name, char sign)
{
	mName = name;
	mType = Player::M_HUMAN;
	mSign = sign;
	mId = rand() % 10000;
	mLastMove = Point(-1, -1);
}

HumanPlayer::~HumanPlayer()
{
}

/*string HumanPlayer::getName()
{
	return m_name;
}

void HumanPlayer::setName(string name)
{
	m_name = name;
}*/

Point HumanPlayer::move(const GameField &gameField, const Player &opponent)
{
	int row = -1;
	int column = -1;
	int fieldSize = gameField.getSize();

	do
	{
		cout << mName << " please insert the row you want to play: ";

		while (!(cin >> row) || row < 1 || row > fieldSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please type a number from 1 - " << fieldSize << ": ";
		}

		cout << mName << " please insert the column you want to play: ";

		while (!(cin >> column) || column < 1 || column > fieldSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please type a number from 1 - " << fieldSize << ": ";
		}

		row--;
		column--;
	} while (gameField.getField(row, column) != GameField::M_EMPTY_CHAR);

	Point point(row, column);
	mLastMove = point;
	return point;
}
