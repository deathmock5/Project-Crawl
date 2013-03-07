#include "Entity.h"
Entity::Entity()
{
	//TODO: make constants
	hasbeeninited = false;
}
Entity::Entity(float spawnx,float spawny)
{
	hasbeeninited = false;
}
Entity::Entity(string file)
{
	load(file);
}
Entity::Entity(string nam,ALLEGRO_BITMAP* ts,int w,int h,ALLEGRO_SAMPLE* atksnd,ALLEGRO_SAMPLE* dmgsnd,ATACKSTYLE sty,int hp,int dmg)
{
	tileset = ts;
	tilesizewidth = w;
	tilesizeheight = h;
	monatacknoise = atksnd;
	mondamagesnd = dmgsnd;
	style = sty;
	hpbace = hp;
	damagebace = dmg;
	isliveingcreature = true;
	alive = false;
	//frameinformation
	framecount = 0;
	animation = STANDING;
	direction = FORWARD;
	delay = 0;
	maxDelay = 1;
	statechanged = false;

	posx = 0;
	posy = 0;
	speed = 0;
	velocityx = 0;
	velocityy = 0;
	hasbeeninited = true;
}
Entity::~Entity()
{
	//delete tileset;
	//delete monatacknoise;
	//delete mondamagesnd;
}
void Entity::spawnAtLocation(int x,int y)
{
	posx = x;
	posy = y;
	alive = true;
}
void Entity::draw(float originposx,float originposy)
{
	if(isliveingcreature)
	{
		//al_draw_filled_rectangle(posx,posy,posx+1.0f,posy+1.0f,al_map_rgb(255,255,255));
		if(delay++ >= maxDelay)
		{
		if(framecount++ >= frameSet[animation][4] -1)
		{
			framecount = 0;
			if(animation != WALKING && animation != STANDING)
			{
				animation = STANDING;
			}
		}
		delay = 0;
		}
		al_draw_bitmap_region(tileset,(float)framecount * tilesizewidth,(float)frameSet[animation][direction] * tilesizeheight,tilesizewidth,tilesizeheight,posx,posy,0);
	}
}
void Entity::travelToPos(float tarx,float tary,float speed){}//TODO: traveltopos
void Entity::update(std::vector<Player> players,int numplayers,Tile tiles[25][19])
{
	if(statechanged)
	{
		switch(animation)
		{
		case ULTI:

			break;
		case WAND:
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
			//TODO: Hitbox stuff
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
			statechanged = false;
		}
		//TODO: Player colisions;
	}
}
bool Entity::isLiveingCreature()
{
	return isliveingcreature;
}
bool Entity::isAlive()
{
	return alive;
}
void Entity::drawLight()
{

}//TODO: draw light
bool Entity::exists()
{
	return hasbeeninited;
}
void Entity::load(string file)
{

}