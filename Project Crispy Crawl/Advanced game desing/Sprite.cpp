#include "Sprite.h"


Sprite::Sprite(void)
{
	
	tileheight = 0;
	tilewidth = 0;
	hasBeenInated = false;
}

Sprite::Sprite(ALLEGRO_BITMAP * set)
{
	tileset = set;
	tilesetheight = al_get_bitmap_height(tileset);
	tilesetwidth = al_get_bitmap_width(tileset);
	tileheight = tilesetheight / 25;
	tilewidth = tilesetwidth / 13;
	hasBeenInated = true;
}

Sprite::~Sprite(void)
{
	//delete(tileset);
}

void Sprite::Draw(int posx,int posy)
{
	al_draw_bitmap(tileset,posx,posy,0);
}