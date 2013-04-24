#include "Map.h"


using namespace std;
Map::Map()
{
	entitysonmap = 0;
}
Map::Map(string dungname,string layout,int player)
{
	entitysonmap = 0;
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
	
	logHelperMessage(WARNING,3,"Map:",dungname.c_str()," Created-Depricated");
	hide();
}
Map::Map(ALLEGRO_BITMAP* tls,ALLEGRO_BITMAP* light,ALLEGRO_SAMPLE* bg,string mapfile,int roomnumber)
{
	entitysonmap = 0;
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
			//entitys[i].draw(originx,originy);
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
		
		//al_draw_tinted_bitmap(torchlight,al_map_rgba(1,1,1,255),60,60,0);
		al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
		al_set_target_bitmap(al_get_backbuffer(display));//return to the display
		al_draw_tinted_bitmap(shadowlayer,al_map_rgba(0,0,0,255),0,32,0);
	}
}
void Map::moveMapToPos(float posx,float posy,float speed)
{

}
void Map::update(Dungion& dung)
{
	if(isOnScreen())
	{
		for(int i = 0;i < (int)entitys.size(); i++)
		{
			entitys[i].update(dung.players,entitys,maptiles);
			
			for(int ii = 0; ii < (int)entitys.size();ii++)//alright lets look through all the entitys on screen.
			{
				if(entitys[i].getUniqueId() != entitys[ii].getUniqueId())//Am i hitting myself?
				{
					//No im not, im hitting somthing else.
					if(entitys[i].hasColider(entitys[ii].getMyColider())) //determine if i can colide with it
					{
						//Ok this object Can colide with me.
						if(entitys[i].getBounds().hasColidedWith(entitys[ii].getBounds())) //Check colisions
						{
							//Alright, i have colided with this object, apply damage.
							//TODO: apply actual damage...
							entitys[i].damageMe(5);
						}
					}
				}
			}
			if(!entitys[i].isAlive())
			{
				entitys.erase(entitys.begin() + i);
			}
		}
		for(int i = 0;i < dung.curentplayers;i++)
		{
			dung.players[i].update(entitys,maptiles,dung);
			int doortransfer = maptiles[((int)(dung.players[i].getBounds().getY() + 16.0f)/32)][((int)(dung.players[i].getBounds().getX() + 14.0f)/32)+1].isDoor();
			if(doortransfer > -1)
			{
				dung.triggerPlayerTransferToNewMap(doortransfer,i);
				//cout << doortransfer;
			}
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
void Map::addDoor(DIRECTION dir,int tomapid,bool needskey)
{
	//TODO: setup information for keys
	switch (dir)
	{
	case BACK:
		//down
		maptiles[18][12] = Tile(DOOR,lvtileset,18,12,tomapid);
		break;
	case LEFT:
		break;
	case FORWARD:
		maptiles[0][12] = Tile(DOOR,lvtileset,0,12,tomapid);
		break;
	case RIGHT:
		break;
	default:
		break;
	}
}
void Map::spawnEnttityInMap(Entity thing)
{
	//TODO: make cleener;
	//TODO: uniqueid
	thing.spawnAtLocation(entitysonmap++);
	entitys.push_back(thing);
}
void Map::bakeTilemap()
{
	//TODO: bake the tilemap into an image and just display the image.
}