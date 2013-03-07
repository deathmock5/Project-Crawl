#include "Map.h"


using namespace std;
Map::Map()
{
}
Map::Map(string mystring,int player)
{

	//lvtileset = al_load_bitmap(myconcat("Dungions/" ,mystring, "Sprites.png").c_str());
	lvtileset = load_image(myconcat("Dungions/" ,mystring, "Sprites.png").c_str());
	//TODO: Update to new format
	//torchlight = al_load_bitmap(myconcat("Images/","LightCore", "Light.png").c_str());
	torchlight = load_image(myconcat("Images/","LightCore", "Light.png").c_str());
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
				maptiles[r][c] = Tile(WALL,lvtileset,r,c,rand() % 3 + 0);
			}
			else
			{
				maptiles[r][c] = Tile(FLOOR,lvtileset,r,c,rand() % 3 + 0);
			}
		}
	}
	maptiles[12][0] = Tile(DOOR,lvtileset,12,0);
	maptiles[12][18] = Tile(DOOR,lvtileset,12,18);
	maptiles[0][9] = Tile(DOOR,lvtileset,0,9);
	maptiles[24][9] = Tile(DOOR,lvtileset,24,9);
	shadowlayer = al_create_bitmap(800,608);
	originx = 0;
	originy = 32.0;
	curentplayers = player;
	players.push_back(Player("Player"));
}
Map::Map(ALLEGRO_BITMAP* tls,ALLEGRO_BITMAP* light,ALLEGRO_SAMPLE* bg)
{
	originx = 0;
	originy = 0;
	onscreen = false;
	lvtileset = tls;
	torchlight = light;
	bgs = bg;
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
		for(int i = 0;i < (int)entitys.size();i++)
		{
			entitys[i].draw(originx,originy);
		}
		for(int i = 0;i < curentplayers;i++)
		{
			players[i].draw();
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
		for(int i = 0;i < (int)entitys.size();i++)
		{
			entitys[i].drawLight();
		}
		for(int i = 0;i < curentplayers;i++)
		{
			players[i].drawLight(torchlight);
		}
		//al_draw_tinted_bitmap(torchlight,al_map_rgba(1,1,1,255),60,60,0);
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
		al_set_target_bitmap(al_get_backbuffer(display));//return to the display
		al_draw_tinted_bitmap(shadowlayer,al_map_rgba(0,0,0,255),0,32,0);
	}
}
void Map::moveMapToPos(float posx,float posy,float speed)
{
}
void Map::update()
{
	if(isOnScreen())
	{
		for(int i = 0;i < (int)entitys.size();i++)
		{
			entitys[i].update(players,curentplayers,maptiles);
		}
		for(int i = 0;i < curentplayers;i++)
		{
			players[i].update(entitys,maptiles);
		}
	}
}
bool Map::isOnScreen()
{
	return onscreen;
}
void Map::show()
{
	onscreen = true;
}
void Map::hide()
{
	onscreen = false;
}
//string Map::myconcat(string folder,string innerfolder,string filename)
//{
//	std::stringstream ss;
//	ss << folder << innerfolder << "/" << filename;
//	std::string s = ss.str();
//	//cout << s << endl;
//	return s;
//}