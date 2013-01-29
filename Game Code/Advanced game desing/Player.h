#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#endif // !_allegro_h_

#ifndef _Player_h_
#define _Player_h_



#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Tile.h"
#include "Entity.h"
#include "Item.h"

using namespace std;
class Tile;
class Entity;
class Item;

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
	void drawLight(ALLEGRO_BITMAP*);
	void update(vector<Entity>,Tile[25][19]);
	void processInput(ACTIONS,DIRECTION);
	Entity playerHasBeenHit(vector<Entity>);
private:
	//animation and rendering
	int delay;
	int maxDelay;
	bool stateChanged;
	float posx,posy;
	ALLEGRO_BITMAP* tileset;
	DIRECTION direction;
	int framecount;
	int animation;
	float tilesize;
	//player data
	Item invintory[9];
	int health;
	int mana;
	int lives;
	string playername;
};
#endif // !_Player_h_