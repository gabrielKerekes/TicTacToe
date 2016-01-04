#pragma once
#include <string>
#include <iostream>

#include "Point.h"
#include "GameField.h"

using namespace std;

class Player
{
public:
	Player();
	Player(string name, string type, char sign);
	~Player();

	//int checkWin();
	//int checkWin(Point lastMove);
	int getId() const;
	char getSign() const;
	void setSign(char c);
	std::string getName();
	void setName(std::string name);
	string getType() const;
	void setType(string type);
	Point getLastMove() const;
	void setLastMove(Point lastMove);

	//Point move();
	virtual Point move(const GameField &gameField, const Player &opponent);

	static const string M_HUMAN;
	static const string M_AI;
protected:
	int mId;
	std::string mName;
	std::string mType;
	char mSign;
	Point mLastMove;
};

