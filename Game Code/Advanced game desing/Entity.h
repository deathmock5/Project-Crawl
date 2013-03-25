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
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

#include "Player.h"
#include "Map.h"
#include "SystemVars.h"
#include "Point.h"
#include "Bounds.h"

class Player;
class Map;
using namespace std;
using std::ifstream;
class Entity
{
public:
	Entity();
	Entity(float,float);
	Entity(string);
	Entity(string,ALLEGRO_BITMAP*,int,int,ALLEGRO_SAMPLE*,ALLEGRO_SAMPLE*,ATACKSTYLE,int,int);
	~Entity();
	void spawnAtLocation(int,int);
	void spawn(Point);
	void spawn(Bounds);
	void spawnWithVelocity(Bounds,float,float);
	void draw(float,float);
	void travelToPos(float tarx,float tary,float speed);
	void update(std::vector<Player>,int,Tile[25][19]);
	bool isLiveingCreature();
	bool isAlive();
	bool isSolid();
	void drawLight();
	bool exists();
	void addTag(string);
	void removeTag(string);
	bool hasTag(string);
	void addColider(string);
	void removeColider(string);
	bool hasColidedWith(Entity);
	bool hasColidedWith(Player);
private:
	void load(string);
	bool hasbeeninited;
	ALLEGRO_BITMAP* tileset;
	ALLEGRO_SAMPLE* monatacknoise;
	ALLEGRO_SAMPLE* mondamagesnd;
	ATACKSTYLE style;
	FRAMESET animation;
	DIRECTION direction;
	bool isliveingcreature;
	bool alive;
	int framecount;
	int delay;
	int maxDelay;
	bool statechanged;
	//dynamic variables
	int tilesizewidth;
	int tilesizeheight;
	Point mypos;
	float speed;
	float velocityx;
	float velocityy;
	vector<string> tags;
	vector<string> coliders;
	//Const
	int hpbace;
	int damagebace;
};
#endif // !_Entity_h_