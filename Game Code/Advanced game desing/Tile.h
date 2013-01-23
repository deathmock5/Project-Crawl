#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>

class Tile
{
public:
	Tile();
	Tile(bool,ALLEGRO_BITMAP*,float,float);
	void draw(float posx,float posy);
	void drawLight(float posx,float posy);
	bool isWall();
private:
	bool wall;
	float gridx;
	float gridy;
	ALLEGRO_BITMAP *myimg;
	ALLEGRO_COLOR color;
};
