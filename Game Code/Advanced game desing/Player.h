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

//#ifndef _Player_h_
//#define _Player_h_

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Entity.h"
#include "Tile.h"
#include "Item.h"
#include "SystemVars.h"
#include "Bounds.h"
#include "Dungion.h"
using namespace std;
class Entity;
class Tile;
class Item;
class Dungion;

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
	void update(vector<Entity>,Tile[19][25],Dungion&);
	void processInput(ACTIONS,DIRECTION);
	DIRECTION getFaceingDir(int,int);
	Bounds getBounds();
	void setBounds(Bounds);
	int getHealth();
	int getMana();
	int getLives();
	int getMoney();
	void damageMe(int);
private:
	//animation and rendering
	int delay;
	int maxDelay;
	bool stateChanged;
	ALLEGRO_BITMAP* tileset;
	DIRECTION direction;
	Bounds mybounds;
	int framecount;
	int animation;
	float tilesize;
	//player data
	Item invintory[9];
	int health;
	int mana;
	int lives;
	int money;
	string playername;
};
//#endif // !_Player_h_