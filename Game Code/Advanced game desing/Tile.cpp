#include "Tile.h"


Tile::Tile()
{
	myimg = NULL;
}
Tile::Tile(TILETYPE mytype,ALLEGRO_BITMAP* img,float x,float y)
{
	int v2 = rand() % 4 + 1;  
	myimg = img;
	type = mytype;
	gridx = x;
	gridy = y;
	color = al_map_rgba(0, 0, 0, 180);
}
Tile::Tile(TILETYPE mytype,ALLEGRO_BITMAP* img,float x,float y,int state)
{
	myimg = img;
	type = mytype;
	gridx = x;
	gridy = y;
	color = al_map_rgba(0, 0, 0, 180);
	mystate = state;
}
Tile::Tile(TILETYPE mytype,ALLEGRO_BITMAP* img,float x,float y,int state,int secondarystate)
{
	myimg = img;
	type = mytype;
	gridx = x;
	gridy = y;
	color = al_map_rgba(0, 0, 0, 180);
	mystate = state;
	mystate2 = secondarystate;
}
void Tile::toggleState2()
{
	mystate2 = 1;
}
void Tile::draw(float posx,float posy)
{
	//const enum TILETYPE{FLOOR,WALL,DOOR,WATER,POT,CHEST,TORCH};
		switch (type)
		{
		case FLOOR:
			al_draw_bitmap_region(myimg,mystate * 32.0f, 0, 32.0f, 32.0f,posx,posy,0);
			break;
		case WALL:
			al_draw_bitmap_region(myimg,mystate * 32.0f,32.0f,32.0f,32.0f,posx,posy,0);
		
			break;
		case DOOR:
			if(gridy == 12)
			{
				if(gridx == 0)
				{
					if(mystate2 == 0)
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 0.0f / 180.0f,0);
					}
					else
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,32.0f,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 0.0f / 180.0f,0);
					}
				}
				else
				{
					if(mystate2 == 0)
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 180.0f / 180.0f,0);
					}
					else
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,32.0f,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 180.0f/ 180.0f,0);
					}
				}
			}
			else
			{
				if(gridy == 0)
				{
					if(mystate2 == 0)
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 270.0f/ 180.0f,0);
					}
					else
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,32.0f,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 270.0f/ 180.0f,0);
					}
				}
				else
				{
					if(mystate2 == 0)
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 *  90.0f / 180.0f,0);
					}
					else
					{
						al_draw_tinted_scaled_rotated_bitmap_region(myimg,32.0f,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 *  90.0f / 180.0f,0);
					}
				}
			}
		
			break;
		case WATER:
			if(mystate > 32)
			{
				mystate = 0;
			}
				al_draw_bitmap_region(myimg,mystate++, 160, 32.0f, 32.0f,posx,posy,0);
			break;
		case POT:
				al_draw_bitmap_region(myimg,0, 0, 32.0f, 32.0f,posx,posy,0);
				al_draw_bitmap_region(myimg,mystate * 32.0 + 64, 64, 32.0f, 32.0f,posx,posy,0);
			break;
		case CHEST:
				al_draw_bitmap_region(myimg,0, 0, 32.0f, 32.0f,posx,posy,0);
				al_draw_bitmap_region(myimg,mystate * 32.0 + 64, 96, 32.0f, 32.0f,posx,posy,0);
			break;
		case TORCH:
			break;
		default:
			break;
			//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
		}
}
void Tile::drawLight(float posx,float posy)
{
}
TILETYPE Tile::getTileType()
{
	return type;
}
bool Tile::passable()
{
	//const enum TILETYPE{FLOOR,WALL,DOOR,WATER,POT,CHEST,TORCH};
	if(type == WALL || type == WATER || type == POT || type == CHEST || type == TORCH )
	{
		return false;
	}
	else
	{
		if(type == DOOR)
		{
			if(mystate2 == 0)
			{
				return false;
			}
		}
		return true;
	}
}
int Tile::isDoor()
{
	if(type == DOOR)
	{
		return mystate;
	}
	else
	{
		return -1;
	}
}