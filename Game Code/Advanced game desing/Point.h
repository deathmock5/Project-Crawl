#pragma once
#ifndef _Point_h_
#define _Point_h_
class Point
{
public:
	Point(void);
	Point(float,float);
	~Point(void);
	float getX(void);
	float getY(void);
	void setX(float);
	void setY(float);
	friend const Point operator +(const Point num1,const Point& num2);
private:
	float x;
	float y;
};
#endif