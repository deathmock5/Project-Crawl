#pragma once
//=================================
// include guard
#ifndef _Entity_h_
#define _Entity_h_
//=================================
// forward declared dependencies
class Player;
class Map;
class Tile;
//=================================
// included dependencies
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
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
#include "GameEntityPath.h"
#include "SpriteCharicter.h"
#include "SpriteProjectile.h"
using namespace std;
using std::ifstream;

class Entity
{
public:
	Entity();
	Entity(float,float);
	Entity(Bounds);
	Entity(Bounds,ALLEGRO_BITMAP*);
	Entity(string);
	Entity(string,ALLEGRO_BITMAP*,int,int,ALLEGRO_SAMPLE*,ALLEGRO_SAMPLE*,ATACKSTYLE,int,int);
	~Entity();
	void spawnAtLocation(int);
	void spawnAtLocation(int x,int y,string,int);
	void spawn(Point,string);
	void spawn(Bounds,string);
	void spawnWithVelocity(Bounds,float,float,string);
	void draw(float,float);
	void travelToPos(float tarx,float tary,float speed);
	void update(vector<Player>&,vector<Entity>&,Tile tiles[19][25]);
	bool isLiveingCreature();
	bool isAlive();
	bool isSolid();
	void drawLight();
	bool exists();
	void addTag(string);
	void removeTag(string);
	const bool hasTag(string);
	void addColider(string);
	void removeColider(string);
	const bool hasColider(string);
	const string getMyColider();
	bool hasColidedWith(Entity);
	bool hasColidedWith(Player&);
	Bounds getBounds();
	void setBounds(Bounds);
	void setUniqueId(int);
	int getUniqueId();
	int getCurentHealth();
	void setCurentHealth(int);
	void damageMe(int);
	void damageMe(Item);
	void setTimeout(int);
	void setVelocity(float,float);
private:
		void load(string);
		bool hasbeeninited;
		//ALLEGRO_BITMAP* tileset;
		ALLEGRO_SAMPLE* monatacknoise;
		ALLEGRO_SAMPLE* mondamagesnd;
		ATACKSTYLE style;
		//FRAMESET animation;
		//DIRECTION direction;
		bool isliveingcreature; //is it a moveable thing?
		bool alive; //is it onscreen
		//int framecount;
		//int delay;
		//int maxDelay;
		bool statechanged;
	//dynamic variables
		Bounds mybounds;
		float speed;
		float velocityx;
		float velocityy;
		vector<string> tags;
		vector<string> coliders;
		int uniqueid;
		int curenthealth;
		int frametimeout;
		GameEntityPath mypather;
		bool immoveing;
		SpriteCharicter sprite;
		SpriteProjectile projecsprite;
		bool isahitbox;
	//Const
		int hpbace;
		int damagebace;
};
#endif // !_Entity_h_