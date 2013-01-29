#include "Player.h"


using namespace std;
//const enum FRAMESET{ULTI = 0,MAGIC = 1, WALKING = 2,SLASH = 3,BOW = 4,DEAD = 5,STANDING = 6};
/*const int frameSet[6][5] = {{0,1,2,3,7},
							{4,5,6,7,8},
							{8,9,10,11,8},
							{12,13,14,15,6},
							{16,17,18,19,7},
							{20,20,20,20,5}};*/
Player::Player()
{
}
Player::Player(string username)
{
	
	framecount = 0;
	animation = STANDING;
	posx = 60;
	posy = 60;
	tilesize = 64.0f;
	tileset = al_load_bitmap("Images\\mainChar.png");
	direction = FORWARD;
	delay = 0;
	maxDelay = 1;
	stateChanged = false;
}
void Player::draw()
{
	al_draw_filled_rectangle(posx,posy,posx+1.0f,posy+1.0f,al_map_rgb(255,255,255));
	if(delay++ >= maxDelay)
	{
	if(framecount++ >= frameSet[animation][4] -1)
	{
		framecount = 0;
	}
	delay = 0;
	}
	al_draw_bitmap_region(tileset,(float)framecount * tilesize,(float)frameSet[animation][direction] * tilesize,tilesize,tilesize,posx,posy,0);
}
void Player::drawLight(ALLEGRO_BITMAP *torchlight)
{
	int v2 = rand() % 4 + 1;     // v2 in the range 1 to 4
	al_draw_tinted_scaled_bitmap(torchlight,al_map_rgba(1,1,1,255),0,0,64.0f,64.0f,posx - 32.0f + v2,posy - 64.0f,128.0f,128.0f + v2,0);
}
void Player::update(vector<Entity> ents,Tile tiles[25][19])
{
	if(stateChanged)
	{
		switch(animation)
		{
		case ULTI:

			break;
		case MAGIC:
			break;
		case WALKING:
			switch (direction)
			{
			case BACK:
				if(tiles[(int)(posx + 32.0f)/32][((int)(posy + 32.0f)/32)-1].passable())
				{
					posy -= 2.0f;
				}
				break;
			case LEFT:
				if(tiles[((int)(posx + 48.0f)/32)-1][((int)(posy + 14.0f)/32)].passable())
				{
					posx -= 2.0f;
				}
				break;
			case FORWARD:
				if(tiles[((int)(posx + 32.0f)/32)][((int)(posy + 0.0f)/32)+1].passable())
				{
					posy += 2;
				}
				break;
			case RIGHT:
				if(tiles[((int)(posx + 16.0f)/32)+1][((int)(posy + 14.0f)/32)].passable())
				{
					posx +=2;
				}
				break;
			default:
				break;
			}
			break;
		case SLASH:
			break;
		case BOW:
			break;
		case DEAD:
			break;
		case STANDING:
			break;
		}
		if(animation != WALKING)
		{
			stateChanged = false;
		}
	}
}
void Player::processInput(ACTIONS action,DIRECTION dir)
{
	//get the curent weapon
	switch (action)
	{
	case STAND:
		animation = STANDING;
		break;
	case WALK:
		animation = WALKING;
		break;
	case ATACK:
		break;
	default:
		break;
	}
	stateChanged = true;
	framecount = 0;
	direction = dir;
}