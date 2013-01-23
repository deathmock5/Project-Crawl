#include "Player.h"
#include <iostream>

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
void Player::drawLight()
{
}
void Player::update()
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
				posy--;
				break;
			case LEFT:
				posx--;
				break;
			case FORWARD:
				posy++;
				break;
			case RIGHT:
				posx++;
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
	framecount = 0;
	direction = dir;
}