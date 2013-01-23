#include "Tile.h"


Tile::Tile()
{
}
Tile::Tile(bool iswall,ALLEGRO_BITMAP* img,float x,float y)
{
	myimg = img;
	wall = iswall;
	gridx = x;
	gridy = y;
	color = al_map_rgba(0, 0, 0, 180);
}
void Tile::draw(float posx,float posy)
{
	if(!wall)
	{
		al_draw_bitmap(myimg,posx,posy,0);
	}
	else
	{
		//al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ZERO);
		al_draw_bitmap(myimg,posx,posy,0);
		if(gridx == 0)
		{
			if(gridy > 0 && gridy < 18)
			{
				//left wall
				al_draw_filled_rectangle(posx + 16.0f, posy, posx + 32.0f, posy + 32.0f, color);
			}
			else if(gridy == 0)
			{
				//top left corner
				al_draw_filled_rectangle(posx + 16.0f, posy + 16.0f, posx + 32.0f, posy + 32.0f, color);
			}
			else
			{
				//bottom left corner
				al_draw_filled_rectangle(posx + 16.0f, posy, posx + 32.0f, posy + 16.0f, color);
			}
		}
		else if(gridx == 24)
		{
			//right wall
			if(gridy > 0 && gridy < 18)
			{
				//normal wall
				al_draw_filled_rectangle(posx, posy, posx + 16.0f, posy + 32.0f, color);
			}
			else if(gridy == 0)
			{
				//top right corner
				al_draw_filled_rectangle(posx, posy+ 16.0f, posx + 16.0f, posy + 32.0f, color);
			}
			else
			{
				//bottom right corner
				al_draw_filled_rectangle(posx, posy, posx + 16.0f, posy + 16.0f, color);
			}
		}
		else
		{
			if(gridy == 0)
			{
				//top wall
				al_draw_filled_rectangle(posx, posy + 16.0f, posx + 32.0f, posy + 32.0f, color);
			}
			else
			{
				//bottom wall
				al_draw_filled_rectangle(posx, posy, posx + 32.0f, posy + 16.0f, color);
			}
		}
		
	}
}
void Tile::drawLight(float posx,float posy)
{
}
bool Tile::isWall()
{
	return wall;
}