#include "SpriteCharicter.h"


SpriteCharicter::SpriteCharicter(void): Sprite()
{

}
SpriteCharicter::SpriteCharicter(ALLEGRO_BITMAP * set) : Sprite(set)
{
	tileset = set;
	animationdoneonce = false;
	framecount = 0;
	animation = STANDING;
	direction = FORWARD;
	delay = 0;
	maxDelay = 1;
	stateChanged = false;
}
SpriteCharicter::~SpriteCharicter(void)
{

}
void SpriteCharicter::Draw(int posx,int posy)
{
	if(hasBeenInated)
	{
		//al_draw_filled_rectangle(posx,posy,posx + tilewidth,posy + tileheight,al_map_rgb(0,255,0));
		if(delay++ >= maxDelay)
		{
		if(framecount++ >= frameSet[animation][4] -1)
		{
			framecount = 0;
			if(animation != WALKING && animation != STANDING && animation != DEAD)
			{
				//we have finished the animation lets go back idle.
				animation = STANDING;
			}
			animationdoneonce = true;
		}
		delay = 0;
		}
		al_draw_bitmap_region(tileset,(float)framecount * tilewidth,(float)frameSet[animation][direction] * tileheight,tilewidth,tileheight,posx - (tilewidth / 2),posy - (tileheight / 2),0);
	}
}
void SpriteCharicter::setAnimation(FRAMESET val)
{
	animation = val;
	animationdoneonce = false;
	stateChanged = true;
	framecount = 0;
}
FRAMESET SpriteCharicter::getAnimation()
{
	return animation;
}
void SpriteCharicter::setDirection(DIRECTION dir)
{
	direction = dir;
}
DIRECTION SpriteCharicter::getDirection()
{
	return direction;
}
bool SpriteCharicter::hasCompletedAnimationOnce()
{
	return animationdoneonce;
}