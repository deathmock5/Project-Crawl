#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>

#include <vector>
#include <cstdlib>
#include <sstream>

#include "Tile.h"
#include "Entity.h"
using namespace std;
class Map
{
public:
	Map();
	Map(string);
	void draw();
	void drawLight(ALLEGRO_DISPLAY*);
	void moveMapToPos(float posx,float posy,float speed);
	void update();
	bool isOnScreen();
	void show();
	void hide();
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

	ALLEGRO_BITMAP *torchlight;
	//tiles
	Tile maptiles[25][19];
	//enemys
	std::vector<Entity> entitys;

	ALLEGRO_BITMAP* randomTileType(bool);
	string myconcat(string,string);
	void spawnEnttityInMap(string,int,int);
};
Map::Map()
{
}
Map::Map(string mystring)
{
	floortiletype1 = al_load_bitmap(myconcat(mystring, "floor1.png").c_str());
	floortiletype2 = al_load_bitmap(myconcat(mystring, "floor2.png").c_str());
	floortiletype3 = al_load_bitmap(myconcat(mystring, "floor3.png").c_str());
	floortiletype4 = al_load_bitmap(myconcat(mystring, "floor4.png").c_str());

	walltiletype1 = al_load_bitmap(myconcat(mystring, "wall1.png").c_str());
	walltiletype2 = al_load_bitmap(myconcat(mystring, "wall2.png").c_str());
	walltiletype3 = al_load_bitmap(myconcat(mystring, "wall3.png").c_str());
	walltiletype4 = al_load_bitmap(myconcat(mystring, "wall4.png").c_str());

	doortileopen = al_load_bitmap(myconcat(mystring, "dooropen.png").c_str());
	doortileclosed = al_load_bitmap(myconcat(mystring, "doorclosed.png").c_str());
	
	torchlight = al_load_bitmap(myconcat(mystring, "Light.png").c_str());
	
	//garbage blocks load1
	//garbage blocks load2
	//garbage blocks load3
	//garbage blocks load4

	//chest tile file load

	//lightsource[] tile array load

	//.dngent file for entitys.
	//switch over to .dnglv file
	for(int r = 0;r < 25;r++)
	{
		for(int c = 0;c < 19;c++)
		{
			if(r == 0 || r == 24 || c == 0 || c == 18)
			{
				//its an edge
				maptiles[r][c] = Tile(true,randomTileType(true),r,c);
				cout << "#";
			}
			else
			{
				maptiles[r][c] = Tile(false,randomTileType(false),r,c);
				cout << "@";
			}
			
		}
		cout << endl;
	}
	maptiles[12][0] = Tile(false,doortileclosed,12,0);
	shadowlayer = al_create_bitmap(800,608);
	originx = 0;
	originy = 32.0;
}
void Map::draw()
{
	//transition logic
	if(isOnScreen())
	{
		for(int r = 0;r < 25;r++)
		{
			for(int c = 0;c < 19;c++)
			{
				maptiles[r][c].draw((32.0f * r) + originx,(32.0f * c) + originy);
			}
		}
		for(Entity myent : entitys)
		{
			myent.Draw();
		}
	}
}
void Map::drawLight(ALLEGRO_DISPLAY* display)
{
	if(isOnScreen())
	{
		al_set_target_bitmap(shadowlayer);
		al_clear_to_color(al_map_rgba(0,0,0,255));
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
		for(int r = 0;r < 25;r++)
		{
			for(int c = 0;c < 19;c++)
			{
				maptiles[r][c].drawLight((32.0f * r) + originx,(32.0f * c) + originy);
			}
		}
		for(Entity myent : entitys)
		{
			myent.drawLight();
		}
		//al_draw_tinted_bitmap(torchlight,al_map_rgba(1,1,1,255),60,60,0);
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
		al_set_target_bitmap(al_get_backbuffer(display));//return to the display
		al_draw_tinted_bitmap(shadowlayer,al_map_rgba(0,0,0,175),0,32,0);
	}
}
void Map::moveMapToPos(float posx,float posy,float speed)
{
}
void Map::update()
{
	if(isOnScreen())
	{
		for(int i = 0;i < entitys.size();i++)
		{
			entitys[i].update();
		}
	}
}
bool Map::isOnScreen()
{
	return true;
}
void Map::show()
{
}
void Map::hide()
{
}
ALLEGRO_BITMAP* Map::randomTileType(bool iswall)
{
	int v2 = rand() % 4 + 1;     // v2 in the range 1 to 4
	switch(v2)
	{
	case 1:
		if(iswall)
		{
			return walltiletype1;
		}
		else
		{
			return floortiletype1;
		}
		break;
	case 2:
		if(iswall)
		{
			return walltiletype2;
		}
		else
		{
			return floortiletype2;
		}
		break;
	case 3:
		if(iswall)
		{
			return walltiletype3;
		}
		else
		{
			return floortiletype3;
		}
		break;
	case 4:
		if(iswall)
		{
			return walltiletype4;
		}
		else
		{
			return floortiletype4;
		}
		break;
	}
	return NULL;
}
string Map::myconcat(string var1,string var2)
{
	std::stringstream ss;
	string var3 = "Images/";
	ss << var3 << var1 << "/" << var2;
	std::string s = ss.str();
	return s;
}