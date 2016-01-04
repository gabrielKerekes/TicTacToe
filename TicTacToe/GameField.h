#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

using namespace std;

#pragma once
class GameField
{
public:
	GameField();
	GameField(int fieldSize);
	GameField(int fieldSize, int neededToWin);
	~GameField();

	int getSize() const;
	void setSize(int fieldSize);

	int getSizeWithPadding() const;
	void setSizeWithPadding(int fieldSizeWithPadding);

	char getField(int row, int column) const;
	void setField(int row, int column, char c);
	void setField(Point point, char c);

	int getNeededToWin() const;
	void setNeededToWin(int neededToWin);

	int getPadding() const;
	void setPadding(int padding);

	int getNumOfFilled() const;
	void setNumOfFilled(int numOfFilled);
	int incNumOfFilled();
	int decNumOfFilled();

	void print() const;
	void printLeftMargin(int size) const;
	bool isEmpty(int row, int column) const;

	bool isFull() const;

	vector<Point> getPossibleMoves() const;

	static const char M_CROSS_CHAR = 'X';
	static const char M_CIRCLE_CHAR = 'O';
	static const char M_EMPTY_CHAR = ' ';
	static const int M_LEFT_MARGIN_SIZE = 24;
private:
	int mFieldSize;
	int mFieldSizeWithPadding;
	vector<vector<char>> mFields;
	int mNeededToWin;
	int mPadding;
	int mNumOfFilled;
};

