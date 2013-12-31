#pragma once
//=================================
// include guard
#ifndef _SpriteProjectile_H_
#define _SpriteProjectile_H_
//=================================
// forward declared dependencies

//=================================
// included dependencies

#include "sprite.h"
#include "SystemVars.h"
//=================================
// the actual class
class SpriteProjectile : public Sprite
{
public:
	SpriteProjectile(void);
	SpriteProjectile(ALLEGRO_BITMAP*);
	virtual void Draw(int posx,int posy);
	void setRotation(float val);
	bool angleHasBeenSet();
	~SpriteProjectile(void);
private:
	float rotation;
	int framecount;
	int delay;
	int maxDelay;
	bool angleset;
};
#endif
