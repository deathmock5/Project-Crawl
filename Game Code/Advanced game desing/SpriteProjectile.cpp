#include "SpriteProjectile.h"


SpriteProjectile::SpriteProjectile(void) : Sprite()
{
	angleset = false;
}
SpriteProjectile::SpriteProjectile(ALLEGRO_BITMAP * set) :Sprite(set)
{
	tileset = set;
	tilewidth = 32.0f;
	tileheight = 32.0f;
	rotation = 0.0f;
	framecount = 0;
	delay = 0;
	maxDelay = 5;
	angleset = false;
}
void SpriteProjectile::Draw(int posx,int posy)
{
	if(hasBeenInated)
	{
		al_draw_filled_rectangle(posx,posy,posx + tilewidth,posy + tileheight,al_map_rgb(0,255,0));
		if(delay++ >= maxDelay)
		{
			if(framecount++ >= 2)
			{
				framecount = 0;
			}
			delay = 0;
		}
		//TODO: fix rotation
		//cout << rotation << endl;
	al_draw_tinted_scaled_rotated_bitmap_region(tileset,(float)framecount * tilewidth,0,tilewidth,tileheight,al_map_rgb(255,255,255),tilewidth / 2, tileheight / 2,posx + (tilewidth / 2),posy + (tileheight / 2),1.0f,1.0f,rotation,0);
	//al_draw_Rotated_bitmap_region(tileset,(float)framecount * tilewidth,(float)framecount * tileheight,tilewidth,tileheight,posx - (tilewidth / 2),posy - (tileheight / 2),0);
	}
}
void SpriteProjectile::setRotation(float val)
{
	rotation = val;
	angleset = true;
}
bool SpriteProjectile::angleHasBeenSet()
{
	return angleset;
}
SpriteProjectile::~SpriteProjectile(void)
{
}
