#pragma once
#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#endif // !_allegro_h_
#ifndef _Entity_h_
#define _Entity_h_
#include "Player.h"
#include "Map.h"
#include "SystemVars.h"
class Player;
class Map;
class Entity
{
public:
	Entity();
	Entity(float,float);
	~Entity();
	void draw(float,float);
	void travelToPos(float tarx,float tary,float speed);
	void update(std::vector<Player>,int,Map);
	bool isLiveingCreature();
	bool isAlive();
	bool isSolid();
	void drawLight();
	bool exists();
private:
	float posx;
	float posy;
	float speed;
	float velocityx;
	float velocityy;
};
#endif // !_Entity_h_