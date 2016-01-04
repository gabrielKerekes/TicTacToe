#include "Player.h"

const std::string Player::M_HUMAN("HUMAN");
const std::string Player::M_AI("AI");

Player::Player()
{
}

Player::Player(string name, string type, char sign)
{
	mName = name;
	mType = type;
	mSign = sign;
	mId = rand() % 10000;
	mLastMove = Point(-1, -1);
}

int Player::getId() const
{
	return mId;
}

char Player::getSign() const
{
	return mSign;
}

void Player::setSign(char c)
{
	mSign = c;
}

std::string Player::getName()
{
	return mName;
}

void Player::setName(std::string name)
{
	mName = name;
}

string Player::getType() const
{
	return mType;
}

void Player::setType(string type)
{
	mType = type;
}

Point Player::getLastMove() const
{
	return mLastMove;
}

void Player::setLastMove(Point lastMove)
{
	mLastMove = lastMove;
}

Point Player::move(const GameField & gameField, const Player & opponent)
{
	return Point(-1, -1);
}

Player::~Player()
{
}