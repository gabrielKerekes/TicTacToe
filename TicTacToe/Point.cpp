#include "Point.h"

Point::Point() : Point(-1, -1)
{
}

Point::Point(int row, int column)
{
	mX = column;
	mY = row;
}

Point::~Point()
{
}

int Point::getX() const
{
	return mX;
}

int Point::getY() const
{
	return mY;
}