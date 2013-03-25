#include "Map.h"


using namespace std;
Map::Map()
{
}
Map::Map(string dungname,string layout,int player)
{
	lvtileset = load_image(myconcat("Dungions/" ,dungname, "/Sprites.png").c_str());
	torchlight = load_image(myconcat("Images/","LightCore", "/Light.png").c_str());
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
	curentplayers = 1;
	players.push_back(Player("Player"));
	logHelperMessage(WARNING,3,"Map:",dungname.c_str()," Created-Depricated");
	hide();
}
Map::Map(ALLEGRO_BITMAP* tls,ALLEGRO_BITMAP* light,ALLEGRO_SAMPLE* bg,string mapfile,int roomnumber)
{
	//load the file
	logHelperMessage(INFO,2,"Opening:",mapfile.c_str());
	ifstream map_file;
	map_file.open(myconcat(2,"FloorLayouts\\",mapfile.c_str()));
	if(!map_file.fail())
	{
		char singlevalue;
		for(int r = 0;r <= 18;r++)
		{
			for(int c = 0;c <= 24;c++)
			{
				if(r == 0 || r == 18 || c == 0 || c == 24)
				{
					//its an edge
					maptiles[r][c] = Tile(WALL,tls,r,c,rand() % 3 + 0);
					//TODO: add a "add door " method in dungion.cpp to ass a door and a dungion.
				}
				else
				{
					singlevalue = map_file.get();
					if(singlevalue == '\n')
					{
						singlevalue = map_file.get();
					}
					switch (singlevalue)
					{
						case '#':
							//floor;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '@':
							//wall;
							maptiles[r][c] = Tile(WALL,tls,r,c,rand() % 3 + 0);
							break;
						case '$':
							//door;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '1':
							//chest;
							maptiles[r][c] = Tile(CHEST,tls,r,c,rand() % 3 + 0);
							break;
						case '2':
							//pot;
							maptiles[r][c] = Tile(POT,tls,r,c,rand() % 3 + 0);
							break;
						case '3':
							//damagetile;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '4':
							//torch;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							//TODO: Spawn torch at this position
							break;
						case '5':
							//mon1;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '6':
							//mon2;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '7':
							//mon3;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
						case '8':
							//water;
							maptiles[r][c] = Tile(WATER,tls,r,c,rand() % 3 + 0);
							break;
						case '9':
							//boss;
							maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
							break;
							
					default:
						logHelperMessage(WARNING,2,"Unknown map file token:",singlevalue);
						maptiles[r][c] = Tile(FLOOR,tls,r,c,rand() % 3 + 0);
						break;
					}
					
				}
			}
		}
	}
	else
	{
		logHelperMessage(WARNING,2,"Failed to load data from:",mapfile.c_str());
		
	}
	shadowlayer = al_create_bitmap(800,608);
	curentplayers = 1;
	players.push_back(Player("Player"));
	logHelperMessage(OK,5,"Map:",mapfile.c_str(), " - ", std::to_string(roomnumber).c_str() ," Created");
	originx = 0;
	originy = 0;
	onscreen = false;
	lvtileset = tls;
	torchlight = light;
	bgs = bg;
	map_file.close();
	hide();
}
void Map::draw()
{
	//TODO: transition logic
	if(isOnScreen())
	{
		for(int r = 0;r < 19;r++)
		{
			for(int c = 0;c < 25;c++)
			{
				maptiles[r][c].draw((32.0f * c) + originx,(32.0f * r) + originy + 32.0f);
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
			//entitys[i].update(players,curentplayers,maptiles);
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
void Map::spawnEnttityInMap(Entity thing,int posx, int posy)
{
	//TODO: position the entity;
	entitys.push_back(thing);
}
//string Map::myconcat(string folder,string innerfolder,string filename)
//{
//	std::stringstream ss;
//	ss << folder << innerfolder << "/" << filename;
//	std::string s = ss.str();
//	//cout << s << endl;
//	return s;
//}