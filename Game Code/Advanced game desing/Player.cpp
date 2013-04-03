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
	//TODO: remove me
	health = 1;
	lives = 3;
	mana = 4;
}
Player::Player(string username)
{
	
	framecount = 0;
	animation = STANDING;
	mybounds.setX(60);
	mybounds.setY(60);
	mybounds.setW(32);
	mybounds.setH(64);
	tilesize = 64.0f;
	tileset = load_image("Images\\mainChar.png");
	direction = FORWARD;
	delay = 0;
	maxDelay = 1;
	stateChanged = false;
	health = 1;
	lives = 3;
	mana = 4;
}
void Player::draw()
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
	al_draw_bitmap_region(tileset,(float)framecount * tilesize,(float)frameSet[animation][direction] * tilesize,tilesize,tilesize,mybounds.getX(),mybounds.getY(),0);
}
void Player::drawLight(ALLEGRO_BITMAP *torchlight)
{
	int v2 = rand() % 4 + 1;     // v2 in the range 1 to 4
	al_draw_tinted_scaled_bitmap(torchlight,al_map_rgba(1,1,1,255),0,0,64.0f,64.0f,mybounds.getX() - 32.0f + v2,mybounds.getY() - 64.0f,128.0f,128.0f + v2,0);
}
void Player::update(vector<Entity> ents,Tile tiles[19][25],Dungion& dung)
{
	if(stateChanged)
	{
		Entity myatackhitbox;
		Bounds slashhitbox;
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
				if(tiles[((int)(mybounds.getY() + 32.0f)/32)-1][((int)(mybounds.getX() + 32.0f)/32)].passable())
				{
					mybounds.setY(mybounds.getY() - 2.0f);
				}
				break;
			case LEFT:
				if(tiles[((int)(mybounds.getY() + 48.0f)/32)-1][((int)(mybounds.getX() + 14.0f)/32)].passable())
				{
					mybounds.setX(mybounds.getX() - 2.0f);
				}
				break;
			case FORWARD:
				if(tiles[((int)(mybounds.getY() + 32.0f)/32)][((int)(mybounds.getX() + 0.0f)/32)+1].passable())
				{
					mybounds.setY(mybounds.getY() + 2.0f);
				}
				break;
			case RIGHT:
				if(tiles[((int)(mybounds.getY() + 16.0f)/32)][((int)(mybounds.getX() + 14.0f)/32)+1].passable())
				{
					mybounds.setX(mybounds.getX() + 2.0f);
				}
				break;
			default:
				break;
			}
			break;
		case SLASH:
			//TODO: Hitbox stuff
			slashhitbox.setW(32);
			slashhitbox.setH(32);
			switch (direction)
			{
			case BACK:
				slashhitbox.setX(mybounds.getX() + 16);
				slashhitbox.setY(mybounds.getY() - 16);
				break;
			case LEFT:
				slashhitbox.setX(mybounds.getX() - 16);
				slashhitbox.setY(mybounds.getY() + 16);
				break;
			case FORWARD:
				slashhitbox.setX(mybounds.getX() + 16);
				slashhitbox.setY(mybounds.getY() + 48);
				break;
			case RIGHT:
				slashhitbox.setX(mybounds.getX() + 48);
				slashhitbox.setY(mybounds.getY() + 16);
				break;
			default:
				break;
			}
			myatackhitbox = Entity(slashhitbox,true);
			myatackhitbox.addTag("PLAYER_SLASH");
			myatackhitbox.addColider("ENEMY");
			myatackhitbox.setTimeout(3);
			dung.reftoCurrentMap()->spawnEnttityInMap(myatackhitbox);
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
	for(int i = 0;i < (int)ents.size();i++)//Lets look though all of the entitys.
	{
		if(ents[i].hasColider("PLAYER"))//Can it colide with the player?
		{
			if(mybounds.hasColidedWith(ents[i].getBounds()))
			{
				//ok, this entity has touched the player.
				damageMe(1);
			}
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
		if(animation == SLASH)
		{
			return; //if were already atacking then dont atack again....
		}
		//TODO: Get charicter weapon and then run atack animation
		animation = SLASH;
		break;
	default:
		break;
	}
	stateChanged = true;
	framecount = 0;
	direction = dir;
}
DIRECTION Player::getFaceingDir(int x,int y)
{
	int dleft = mybounds.getX() + 16 - x;//negitive if right, positive when left
	int dup = mybounds.getY() + 32 - y;//positive when up negitive when down
	int dright = x - (mybounds.getX() + 16);
	int ddown = y - (mybounds.getY() + 32);
	if(dleft > dright && dleft > dup && dleft > ddown)
	{
		return LEFT;
	}
	if(dright > dup && dright > ddown)
	{
		return RIGHT;
	}
	if(dup > ddown)
	{
		return BACK;
	}
	return FORWARD;
}
Bounds Player::getBounds()
{
	return mybounds;
}
void Player::setBounds(Bounds newbounds)
{
	mybounds = newbounds;
}
int Player::getHealth()
{
	return health;
}
int Player::getMana()
{
	return mana;
}
int Player::getLives()
{
	return lives;
}
void Player::damageMe(int amount)
{
	//ok im being damaged, lets apply it to my health.
	health -= amount;
	//am i still alive?
	if(health <= 0)
	{
		//nope kill me.
		if(lives > 0)//do i have any lives left?
		{
			lives -= 1;
			//TODO:apply invincibility for a few seconds.
		}
		else
		{
			//im out of lives. im dead.
			//TODO: apply game over menu and death ext.
		}
	}
}
int Player::getMoney()
{
	return money;
}