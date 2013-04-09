#include "Bounds.h"


Bounds::Bounds()
{
	position.setX(0);
	position.setY(0);
	w = 0;
	h = 0;
}
Bounds::Bounds(float x,float y,int width,int height)
{
	position.setX(x);
	position.setY(y);
	w = width;
	h = height;
}
Bounds::Bounds(Point mypos,int width,int height)
{
	position = mypos;
	w = width;
	h = height;
}
Bounds::~Bounds(void)
{

}
float Bounds::getX()
{
	return position.getX();
}
float Bounds::getY()
{
	return position.getY();
}
int Bounds::getW()
{
	return w;
}
int Bounds::getH()
{
	return h;
}
void Bounds::setX(float x)
{
	position.setX(x);
}
void Bounds::setY(float y)
{
	position.setY(y);
}
void Bounds::setW(int width)
{
	w = width;
}
void Bounds::setH(int height)
{
	h = height;
}
Point Bounds::getUpperLeftPoint()
{
	return position;
}
Point Bounds::getLowerRightPoint()
{
	Point lowerright = position;
	lowerright.setX(lowerright.getX() + w);
	lowerright.setY(lowerright.getY() + h);
	return lowerright;
}
Point Bounds::getCenterPoint()
{
	Point center = position;
	center.setX(center.getX() + w / 2);
	center.setY(center.getY() + h / 2);
	return center;
}
Point Bounds::getGridPos()
{
	Point returnpoint;
	returnpoint.setX(position.getX() / 32);
	returnpoint.setY(position.getY() / 32);
	return returnpoint;
}
bool Bounds::hasColidedWith(Bounds otherobj)
{
	//al_draw_filled_rectangle(getX(),getY(),getX() + getW(),getY() + getH(),al_map_rgb(255,255,255));
	//al_draw_filled_rectangle(otherobj.getX(),otherobj.getY(),otherobj.getX() + otherobj.getW(),otherobj.getY() + otherobj.getH(),al_map_rgb(255,255,255));
	if(	getX() < otherobj.getX() + otherobj.getW() &&
		getX() + getW() > otherobj.getX() &&
		getY() < otherobj.getY() + otherobj.getH() &&
		getY() + getH() > otherobj.getY())
	{
		//cout << "HIT:{" << getX() << "|" << getY() << "|" << getW() << "|" << getH() << "},{" << otherobj.getX() << "|" << otherobj.getY() << "|" << otherobj.getW() << "|" << otherobj.getH()  << endl;
		return true;
	}
	return false;
}
