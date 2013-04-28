#include "Entity.h"
using namespace std;
using std::ifstream;
Entity::Entity()
{
	framecount = -1;
	hasbeeninited = false;
}
Entity::Entity(float spawnx,float spawny)
{
	hasbeeninited = false;
	curenthealth = 1;
}
Entity::Entity(Bounds hitboxSquare,bool ishitbox)
{
	framecount = -1;
	mybounds = hitboxSquare;
	isliveingcreature = false;
	curenthealth = 1;
}
Entity::Entity(string file)
{
	frametimeout = -1;
	load(file);
	hasbeeninited = true;
}
Entity::Entity(string nam,ALLEGRO_BITMAP* ts,int w,int h,ALLEGRO_SAMPLE* atksnd,ALLEGRO_SAMPLE* dmgsnd,ATACKSTYLE sty,int hp,int dmg)
{
	framecount = -1;
	tileset = ts;
	monatacknoise = atksnd;
	mondamagesnd = dmgsnd;
	style = sty;
	isliveingcreature = true;
	alive = false;
	//frameinformation
	framecount = 0;
	animation = STANDING;
	direction = FORWARD;
	delay = 0;
	maxDelay = 1;
	statechanged = false;
	mybounds = Bounds(0,0,w,h);
	speed = 0;
	velocityx = 0;
	velocityy = 0;
	hasbeeninited = true;
	hpbace = hp;
	curenthealth = hp;
	damagebace = dmg;
	addTag("ENEMY");
}
Entity::~Entity()
{
	//delete tileset;
	//delete monatacknoise;
	//delete mondamagesnd;
}
void Entity::spawnAtLocation(int id)
{
	uniqueid = id;
	alive = true;
	curenthealth = hpbace;
}
void Entity::spawnAtLocation(int x,int y,string uniquetag,int timeout)
{
	frametimeout = timeout;
	addTag(uniquetag);
	mybounds.setX(x);
	mybounds.setY(y);
	alive = true;
	curenthealth = hpbace;
}
void Entity::spawn(Point newpoint,string uniquetag)
{
	addTag(uniquetag);
	mybounds.setX(newpoint.getX());
	mybounds.setY(newpoint.getY());
	curenthealth = hpbace;
	alive = true;
}
void Entity::spawn(Bounds varbounds,string uniquetag)
{
	addTag(uniquetag);
	mybounds = varbounds;
	alive = true;
	curenthealth = hpbace;
}
void Entity::spawnWithVelocity(Bounds varbound,float vx,float vy,string uniquetag)
{
	addTag(uniquetag);
	mybounds = varbound;
	velocityx = vx;
	velocityy = vy;
}
void Entity::draw(float originposx,float originposy)
{
	if(isliveingcreature && hasbeeninited)
	{
		//al_draw_filled_rectangle(posx,posy,posx+1.0f,posy+1.0f,al_map_rgb(255,255,255));
		if(delay++ >= maxDelay)
		{
		if(framecount++ >= frameSet[animation][4] -1)
		{
			framecount = 0;
			if(animation == DEAD)
			{
				alive = false;
			}
			if(animation != WALKING && animation != STANDING)
			{
				animation = STANDING;
			}
		}
		delay = 0;
		}
		al_draw_bitmap_region(tileset,(float)framecount * mybounds.getW(),(float)frameSet[animation][direction] *  mybounds.getH(), mybounds.getW(), mybounds.getH(),mybounds.getX(),mybounds.getY(),0);
	}
	else
	{
		al_draw_filled_rectangle(mybounds.getX(),mybounds.getY(),mybounds.getX() + mybounds.getW(),mybounds.getY() + mybounds.getH(),al_map_rgb(255,255,255));
	}
}
void Entity::travelToPos(float tarx,float tary,float speed)
{
	//TODO: traveltopos
	//add somthing to the 'update' method to set a destination.
}
void Entity::update(vector<Player> &players,vector<Entity> &ents,Tile tiles[19][25])
{
	if(isAlive())
	{
		if(isliveingcreature)
		{
			if(!mypather.locationHasBeenSet())
			{
				mypather.setMyLocation(Point(mybounds.getGridPos().getX(),mybounds.getGridPos().getY()));
			}
			if(!mypather.targetHasBeenSet())
			{
				mypather.setTargetLocation(Point(players[0].getBounds().getGridPos().getX(),players[0].getBounds().getGridPos().getY()));
			}
			if(!mypather.mapHasBeenSet())
			{
				int map[19][25];
				for(int h = 0;h < SCREEN_TILE_HEIGHT;h++)
				{
					for(int w = 0; w < SCREEN_TILE_WIDTH;w++)
					{
						if(tiles[h][w].passable())
						{
							map[h][w] = 0;//passable
						}
						else
						{
							map[h][w] = 1;//notpassable
						}
					}
				}
				mypather.setMap(map);
			}
			try
			{
				mypather.beginPathing();
			}
			catch(...)
			{
				logHelperMessage(SEVERE,1,"Unable to compute path");
			}
		}
	}
	if(statechanged)
	{
		switch(animation)
		{
		case ULTI:
			//TODO: ultimate code
			break;
		case WAND:
			//TODO: Spawn fireball projectile
			break;
		case WALKING:
			switch (direction)
			{
			case BACK:
				if(tiles[(int)(mybounds.getX() + 32.0f)/32][((int)(mybounds.getY() + 32.0f)/32)-1].passable())
				{
					mybounds.setY(mybounds.getY() - 2.0f);
				}
				break;
			case LEFT:
				if(tiles[((int)(mybounds.getX()  + 48.0f)/32)-1][((int)(mybounds.getY()  + 14.0f)/32)].passable())
				{
					mybounds.setX(mybounds.getX() - 2.0f);
				}
				break;
			case FORWARD:
				if(tiles[((int)(mybounds.getX() + 32.0f)/32)][((int)(mybounds.getY()  + 0.0f)/32)+1].passable())
				{
					mybounds.setY(mybounds.getY() + 2.0f);
				}
				break;
			case RIGHT:
				if(tiles[((int)(mybounds.getX()  + 16.0f)/32)+1][((int)(mybounds.getY() + 14.0f)/32)].passable())
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
			break;
		case BOW:
			//TODO: create projectile and spawn it with velocity
			break;
		case DEAD:
			//TODO: play death animation and stuff.
			break;
		case STANDING:
			//TODO: idle animation?
			break;
		}
		if(animation != WALKING)
		{
			statechanged = false;
		}
	}
	if(isAlive() && frametimeout >= 0)
	{
		if(frametimeout > 0)
		{
			frametimeout--;
		}
		else
		{
			//TODO: kill me
			alive = false;
		}
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
	ifstream monsterdata;
	monsterdata.open(myconcat(2,"Monster\\",file.c_str()));
	if(!monsterdata.fail())
	{
		logHelperMessage(OK,3,"File: '","Monster\\",file.c_str(),"' loaded.");
		char next = '\n';
        string filemonname;
		string filemontileset;
		string filemonwidth;
		string filemonheight;
		string filemonatksnd;
		string filemonhitsnd;
		string filemonatkstyle;
		string filemonhpbace;
		string filemondmgbace;
		monsterdata.get(next);
		monsterdata.get(next);
		monsterdata.get(next);
		monsterdata >> filemonname;
		monsterdata >> filemontileset;
		monsterdata >> filemonwidth;
		monsterdata >> filemonheight;
		monsterdata >> filemonatksnd;
		monsterdata >> filemonhitsnd;
		monsterdata >> filemonhpbace;
		monsterdata >> filemondmgbace;
		tileset = load_image(myconcat(2,"Monster\\",filemontileset.c_str()));
		monatacknoise = load_sound(myconcat(2,"Monster\\",filemonatksnd.c_str()));
		mondamagesnd = load_sound(myconcat(2,"Monster\\",filemonhitsnd.c_str()));
		//TODO: Get monster atack style
		hpbace = atoi(filemonhpbace.c_str());
		curenthealth = atoi(filemonhpbace.c_str());
		damagebace = atoi(filemondmgbace.c_str());
		isliveingcreature = true;
		framecount = 0;
		animation = STANDING;
		direction = FORWARD;
		delay = 0;
		maxDelay = 1;
		statechanged = false;
		mybounds.setX(128.0f);
		mybounds.setY(128.0f);
		mybounds.setW(atoi(filemonwidth.c_str()));
		mybounds.setH(atoi(filemonheight.c_str()));
		speed = 2.0f;
		velocityx = 1.0f;
		velocityy = 1.0f;
		monsterdata.close();
	}
	else
	{
		logHelperMessage(SEVERE,4,"File: '","Monster\\",file.c_str(),"' failed.");
	}
}
void Entity::addTag(string val)
{
	tags.push_back(val);
}
void Entity::removeTag(string val)
{
	for(int i = 0;i <= (int)tags.size();i++)
	{
		if(val == tags[i])
		{
			tags[i].erase();
		}
		else
		{
			logHelperMessage(WARNING,3,"Value of:'",val,"' Not found.");
		}
	}
}
const bool Entity::hasTag(string val)
{
	for(int i = 0;i <= (int)tags.size();i++)
	{
		if(val == tags[i])
		{
			return true;
		}
	}
	return false;
}
void Entity::addColider(string val)
{
	coliders.push_back(val);
}
void Entity::removeColider(string val)
{
	for(int i = 0;i <= (int)coliders.size();i++)
	{
		if(val == coliders[i])
		{
			coliders[i].erase();
		}
		else
		{
			logHelperMessage(WARNING,3,"Value of:'",val,"' Not found.");
		}
	}
}
const bool Entity::hasColider(string val)
{
	for(int i = 0;i < (int)coliders.size();i++)
	{
		if(val == coliders[i])
		{
			return true;
		}
	}
	return false;
}
const string Entity::getMyColider()
{
	return tags[0];
}
bool Entity::hasColidedWith(Entity ent)
{
	if(hasColider(ent.getMyColider()))
	{
		//ok i can colide with it
		if(mybounds.hasColidedWith(ent.getBounds()))
		{
			return true;
		}
	}
	return false;
}
bool Entity::hasColidedWith(Player& pla)
{
	//TODO: has colided with pla
	//check if it can colide with that
	//if it can preform boundscheckign
	return false;
}
Bounds Entity::getBounds()
{
	return mybounds;
}
void Entity::setBounds(Bounds varbounds)
{
	mybounds = varbounds;
}
void Entity::setUniqueId(int id)
{
	uniqueid = id;
}
int Entity::getUniqueId()
{
	return uniqueid;
}
int Entity::getCurentHealth()
{
	return curenthealth;
}
void Entity::setCurentHealth(int health)
{
	curenthealth = health;
}
void Entity::damageMe(int amount)
{
	curenthealth = curenthealth - amount;
	//diable boundschecking untill next update.
	if(curenthealth < 0)
	{
		statechanged = true;
		animation = DEAD;
	}
}
void Entity::damageMe(Item)
{
	//TODO: handle being hit with a weapon.
}
void Entity::setTimeout(int val)
{
	frametimeout = val;
}