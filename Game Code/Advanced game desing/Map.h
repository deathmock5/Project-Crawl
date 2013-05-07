#pragma once
//=================================
// include guard
#ifndef _Map_h_
#define _Map_h_

//=================================
// forward declared dependencies
class Player;

//=================================
// included dependencies
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Tile.h"
#include "Item.h"
#include "Player.h"
#include "Entity.h"
#include "SystemVars.h"

using namespace std;

class Map
{
public:
	Map();
	Map(string,string,int);
	Map(ALLEGRO_BITMAP*,ALLEGRO_BITMAP*,string,string,int);
	void draw();
	void drawLight(ALLEGRO_DISPLAY*);
	void moveMapToPos(float posx,float posy,float speed);
	void update(class Dungion&);
	bool isOnScreen();
	void show();
	void hide();
	void addDoor(DIRECTION dir,int tomapid,bool needskey);
	bool doorUnlocked();
	void setDoorLockStatus(bool);
	void spawnEnttityInMap(class Entity);
	void spawnEnttityInMap(class Entity,bool);
	void bakeTilemap();
private:
	float originx;
	float originy;
	bool onscreen;
	int entitysonmap;
	//floor tiles
	ALLEGRO_BITMAP *lvtileset;
	
	ALLEGRO_BITMAP *shadowlayer;
	ALLEGRO_BITMAP *gorelayer;

	ALLEGRO_BITMAP *torchlight;
	string bgs;
	//tiles
	Tile maptiles[19][25];
	//enemys
	std::vector<Entity> entitys;
	
	//methods
	//string myconcat(string,string,string);
};
#endif // !_Map_h_