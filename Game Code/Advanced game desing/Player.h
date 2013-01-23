#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_native_dialog.h>

#include <vector>
#include <cstdlib>
#include <sstream>

#include "Tile.h"
#include "Entity.h"
#include "Item.h"

using namespace std;
const enum ACTIONS{STAND,WALK,ATACK};
const enum FRAMESET{ULTI = 0,MAGIC = 1, WALKING = 2,SLASH = 3,BOW = 4,DEAD = 5,STANDING = 6};
const enum DIRECTION{BACK,LEFT,FORWARD,RIGHT};
const int frameSet[7][5] = {{0,1,2,3,7},
							{4,5,6,7,8},
							{8,9,10,11,8},
							{12,13,14,15,6},
							{16,17,18,19,13},
							{20,20,20,20,5},
							{21,22,23,24,1}};
class Player
{
public:
	Player();
	Player(string);
	void draw();
	void drawLight();
	void update();
	void processInput(ACTIONS,DIRECTION);
private:
	float posx,posy;
	ALLEGRO_BITMAP* tileset;
	DIRECTION direction;
	int framecount;
	int animation;
	float tilesize;
	Item invintory[8];
	int delay;
	int maxDelay;
	bool stateChanged;
	string playername;
};
