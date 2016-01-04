#pragma once
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();

	int getX() const;
	int getY() const;
private:
	int mX;
	int mY;
};

