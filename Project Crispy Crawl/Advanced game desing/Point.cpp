#include "Point.h"


Point::Point(void)
{
	x = 0.0f;
	y = 0.0f;
}

Point::Point(float mx, float my)
{
	x = mx;
	y = my;
}

Point::~Point(void)
{

}

float Point::getX(void)
{
	return x;
}

float Point::getY(void)
{
	return y;
}

void Point::setX(float xp)
{
	x = xp;
}

void Point::setY(float yp)
{
	y = yp;
}

const Point operator +(const Point num1,const Point& num2)
{
	float thex = num1.x + num2.x;
	float they = num1.y + num2.y;
	return Point(thex,they);
}