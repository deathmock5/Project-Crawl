#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

#include <vector>;

#include "Tile.h"
#include "Entity.h"

class Map
{
public:
	Map();
	void draw();
	void drawLight();
	void moveMapToPos(float posx,float posy,float speed);
	bool isOnScreen();
	void show();
	void hide();
private:
	int originx;
	int originy;

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

	//tiles
	Tile maptiles[25][19];
	//enemys
	std::vector<Entity> entitys;
};