#pragma once
class Entity
{
public:
	Entity(float,float);
	~Entity();
	void draw();
	void travelToPos(float tarx,float tary,float speed);
	void update();
	bool isLiveingCreature();
	bool isAlive();
	void drawLight();
private:
	float posx;
	float posy;
	float speed;
	float velocityx;
	float velocityy;
};