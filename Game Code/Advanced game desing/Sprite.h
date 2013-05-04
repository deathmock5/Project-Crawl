#pragma once
//=================================
// include guard
#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
//=================================
// forward declared dependencies

//=================================
// included dependencies

//=================================
// the actual class
class Sprite
{
public:
	Sprite(void);
	Sprite(ALLEGRO_BITMAP*);
	virtual void Draw(int posx,int posy);
	~Sprite(void);
protected:
	int hasBeenInated;
	ALLEGRO_BITMAP* tileset;
	int tilewidth;
	int tileheight;
	int tilesetwidth;
	int tilesetheight;
};
#endif // __MYCLASS_H_INCLUDED__ 