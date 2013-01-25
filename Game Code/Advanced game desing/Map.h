#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
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
using namespace std;
class Map
{
public:
	Map();
	Map(string,int);
	void draw();
	void drawLight(ALLEGRO_DISPLAY*);
	void moveMapToPos(float posx,float posy,float speed);
	void update();
	bool isOnScreen();
	void show();
	void hide();
	Player players[8];
private:
	float originx;
	float originy;

	//floor tiles
	ALLEGRO_BITMAP *floortiletype1;//normal
	ALLEGRO_BITMAP *floortiletype2;//diffrent
	ALLEGRO_BITMAP *floortiletype3;//diffrent
	ALLEGRO_BITMAP *floortiletype4;//broken

	//wall tiles
	ALLEGRO_BITMAP *walltiletype1;//normal
	ALLEGRO_BITMAP *walltiletype2;//diffrent
	ALLEGRO_BITMAP *walltiletype3;//diffrent
	ALLEGRO_BITMAP *walltiletype4;//broken

	ALLEGRO_BITMAP *doortileopen;
	ALLEGRO_BITMAP *doortileclosed;

	ALLEGRO_BITMAP *potimg;
	ALLEGRO_BITMAP *torchimgs[5];
	ALLEGRO_BITMAP *chestimg;

	ALLEGRO_BITMAP *shadowlayer;
	ALLEGRO_BITMAP *gorelayer;

	ALLEGRO_BITMAP *torchlight;
	//tiles
	Tile maptiles[25][19];
	//enemys
	std::vector<Entity> entitys;
	//players
	
	int curentplayers;
	//methods
	ALLEGRO_BITMAP* randomTileType(bool);
	string myconcat(string,string);
	void spawnEnttityInMap(string,int,int);
};
#endif // !_Map_h_