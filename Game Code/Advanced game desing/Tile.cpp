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
void Tile::draw(float posx,float posy)
{
	switch (type)
	{
	case FLOOR:
			al_draw_bitmap_region(myimg,mystate * 32.0f, 0, 32.0f, 32.0f,posx,posy,0);
		break;
	case WALL:
		al_draw_bitmap_region(myimg,mystate * 32.0f,32.0f,32.0f,32.0f,posx,posy,0);
		//if(gridx == 0)
		//{
		//	if(gridy > 0 && gridy < 18)
		//	{
		//		//left wall
		//		al_draw_filled_rectangle(posx + 16.0f, posy, posx + 32.0f, posy + 32.0f, color);
		//	}
		//	else if(gridy == 0)
		//	{
		//		//top left corner
		//		al_draw_filled_rectangle(posx + 16.0f, posy + 16.0f, posx + 32.0f, posy + 32.0f, color);
		//	}
		//	else
		//	{
		//		//bottom left corner
		//		al_draw_filled_rectangle(posx + 16.0f, posy, posx + 32.0f, posy + 16.0f, color);
		//	}
		//}
		//else if(gridx == 24)
		//{
		//	//right wall
		//	if(gridy > 0 && gridy < 18)
		//	{
		//		//normal wall
		//		al_draw_filled_rectangle(posx, posy, posx + 16.0f, posy + 32.0f, color);
		//	}
		//	else if(gridy == 0)
		//	{
		//		//top right corner
		//		al_draw_filled_rectangle(posx, posy+ 16.0f, posx + 16.0f, posy + 32.0f, color);
		//	}
		//	else
		//	{
		//		//bottom right corner
		//		al_draw_filled_rectangle(posx, posy, posx + 16.0f, posy + 16.0f, color);
		//	}
		//}
		//else
		//{
		//	if(gridy == 0)
		//	{
		//		//top wall
		//		al_draw_filled_rectangle(posx, posy + 16.0f, posx + 32.0f, posy + 32.0f, color);
		//	}
		//	else
		//	{
		//		//bottom wall
		//		al_draw_filled_rectangle(posx, posy, posx + 32.0f, posy + 16.0f, color);
		//	}
		//}
		break;
	case DOOR:
		
		if(gridx == 12)
		{
			if(gridy == 0)
			{
				al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,0,0);
			}
			else
			{
				al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 180.0f / 180.0f,0);
			}
		}
		else
		{
			if(gridx == 0)
			{
				al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 270.0f / 180.0f,0);
			}
			else
			{
				al_draw_tinted_scaled_rotated_bitmap_region(myimg,0,64.0f,32.0f,32.0f,al_map_rgb(255,255,255),16.0f,16.0f,posx + 16.0f,posy + 16.0f,1.0f,1.0f,3.14 * 90.0f / 180.0f,0);
			}
		}
		
		break;
	case WATER:
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
	if(type == WALL || type == WATER)
	{
		return false;
	}
	else
	{
		return true;
	}
}