#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#endif // !_allegro_h_

#ifndef _Tile_h_
#define _Tile_h_

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
#endif // !_Tile_h_