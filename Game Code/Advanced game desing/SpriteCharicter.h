#pragma once
//=================================
// include guard
#ifndef _MYCLASS_H_
#define _MYCLASS_H_


//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "sprite.h"
#include "SystemVars.h"
const int frameSet[7][5] = {{0,1,2,3,7},
							{4,5,6,7,8},
							{8,9,10,11,8},
							{12,13,14,15,6},
							{16,17,18,19,13},
							{20,20,20,20,5},
							{21,22,23,24,1}};
//const enum FRAMESET{ULTI = 0,MAGIC = 1, WALKING = 2,SLASH = 3,BOW = 4,DEAD = 5,STANDING = 6};
//=================================
// the actual class
class SpriteCharicter : public Sprite
{
public:
	SpriteCharicter(void);
	SpriteCharicter(ALLEGRO_BITMAP*);
	~SpriteCharicter(void);
	//Sprite(void);
	//Sprite(ALLEGRO_BITMAP*);
	virtual void Draw(int posx,int posy);
	void setAnimation(FRAMESET val);
	FRAMESET getAnimation();
	void setDirection(DIRECTION dir);
	DIRECTION getDirection();
	bool hasCompletedAnimationOnce();
	//~Sprite(void);
private:
	//int hasBeenInated;
	//ALLEGRO_BITMAP* tileset;
	//int tilewidth;
	//int tileheight;
	//int tilesetwidth;
	//int tilesetheight;
	//animation and rendering
	int delay;
	int maxDelay;
	bool stateChanged;
	DIRECTION direction;
	int framecount;
	FRAMESET animation;
	bool animationdoneonce;
};
#endif // __MYCLASS_H_INCLUDED__ 
