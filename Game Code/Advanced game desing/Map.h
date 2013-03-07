#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#endif // !_allegro_h_
#ifndef _Map_h_
#define _Map_h_
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Tile.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include "SystemVars.h"
using namespace std;

class Tile;
class Entity;
class Player;
class Map
{
public:
	Map();
	Map(string,int);
	Map(ALLEGRO_BITMAP*,ALLEGRO_BITMAP*,ALLEGRO_SAMPLE*);
	void draw();
	void drawLight(ALLEGRO_DISPLAY*);
	void moveMapToPos(float posx,float posy,float speed);
	void update();
	bool isOnScreen();
	void show();
	void hide();
	std::vector<Player> players;
private:
	float originx;
	float originy;
	bool onscreen;

	//floor tiles
	ALLEGRO_BITMAP *lvtileset;
	
	ALLEGRO_BITMAP *shadowlayer;
	ALLEGRO_BITMAP *gorelayer;

	ALLEGRO_BITMAP *torchlight;
	ALLEGRO_SAMPLE *bgs;
	//tiles
	Tile maptiles[25][19];
	//enemys
	std::vector<Entity> entitys;
	//players
	
	int curentplayers;
	//methods
	//string myconcat(string,string,string);
	void spawnEnttityInMap(string,int,int);
};
#endif // !_Map_h_