#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#endif // !_allegro_h_

#ifndef _Tile_h_
#define _Tile_h_
const enum TILETYPE{FLOOR,WALL,DOOR,WATER};
class Tile
{
public:
	Tile();
	Tile(TILETYPE,ALLEGRO_BITMAP*,float,float);
	Tile(TILETYPE,ALLEGRO_BITMAP*,float,float,int);
	void draw(float posx,float posy);
	void drawLight(float posx,float posy);
	TILETYPE getTileType();
	bool passable();
private:
	TILETYPE type;
	float gridx;
	float gridy;
	ALLEGRO_BITMAP *myimg;
	ALLEGRO_COLOR color;
	int mystate;
};
#endif // !_Tile_h_