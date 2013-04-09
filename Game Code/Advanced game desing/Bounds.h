#pragma once
#ifndef _Bounds_h_
#define _Bounds_h_
#include "Point.h"
#include "SystemVars.h"
class Bounds
{
public:
	Bounds(void);
	Bounds(float,float,int,int);
	Bounds(Point,int,int);
	~Bounds(void);
	float getX();
	float getY();
	int getW();
	int getH();
	void setX(float);
	void setY(float);
	void setW(int);
	void setH(int);

	Point getUpperLeftPoint();
	Point getLowerRightPoint();
	Point getCenterPoint();
	Point getGridPos();
	bool hasColidedWith(Bounds);
private:
	Point position;
	int w;
	int h;
};
#endif