#pragma once
#ifndef _Tile_h_
#define _Tile_h_


#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "SystemVars.h"

const enum TILETYPE{FLOOR,WALL,DOOR,WATER,POT,CHEST,TORCH};

class Tile
{
public:
	Tile();
	Tile(TILETYPE,ALLEGRO_BITMAP*,float,float);
	Tile(TILETYPE,ALLEGRO_BITMAP*,float,float,int);
	Tile(TILETYPE,ALLEGRO_BITMAP*,float,float,int,int);
	void toggleState2();
	void draw(float posx,float posy);
	void drawLight(float posx,float posy);
	TILETYPE getTileType();
	int isDoor();
	bool passable();
private:
	TILETYPE type;
	float gridx;
	float gridy;
	ALLEGRO_BITMAP *myimg;
	ALLEGRO_COLOR color;
	int mystate;
	int mystate2;
};
#endif // !_Tile_h_