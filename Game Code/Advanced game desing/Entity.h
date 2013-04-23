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
#include <queue>
#include "Player.h"
#include "Map.h"
#include "SystemVars.h"
#include "Point.h"
#include "Bounds.h"
#include "Node.h"


using namespace std;
using std::ifstream;

class Entity
{
public:
	Entity();
	Entity(float,float);
	Entity(Bounds);
	Entity(Bounds,bool);
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
private:
		void load(string);
		string pathFind(Point playerpos);
		bool hasbeeninited;
		ALLEGRO_BITMAP* tileset;
		ALLEGRO_SAMPLE* monatacknoise;
		ALLEGRO_SAMPLE* mondamagesnd;
		ATACKSTYLE style;
		FRAMESET animation;
		DIRECTION direction;
		bool isliveingcreature; //is it a moveable thing?
		bool alive; //is it onscreen
		int framecount;
		int delay;
		int maxDelay;
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
	//Const
		int hpbace;
		int damagebace;
	//pathfinding
	int n; // horizontal size of the map
	int m; // vertical size size of the map
	bool mapHasBeenSet;
	int map[25][19];
	int closed_Nodes_map[25][19]; // map of closed (tried-out) Nodes
	int open_Nodes_map[25][19]; // map of open (not-yet-tried) Nodes
	int dir_map[25][19]; // map of directions
	int dir; // number of possible directions to go at any position
	// if dir==4
	//static int dx[dir]={1, 0, -1, 0};
	//static int dy[dir]={0, 1, 0, -1};
	// if dir==8
    priority_queue<Node> pq[2]; // list of open (not-yet-tried) Nodes
    int pqi; // pq index
    Node* n0;
    Node* m0;
	string pathtoplayer;
};
#endif // !_Entity_h_