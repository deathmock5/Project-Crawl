#include "Entity.h"
using namespace std;
using std::ifstream;
Entity::Entity()
{
	//framecount = -1;
	hasbeeninited = false;
	immoveing = false;
	isahitbox = false;
}
Entity::Entity(float spawnx,float spawny)
{
	hasbeeninited = false;
	curenthealth = 1;
	immoveing = false;
	isahitbox = false;
}
Entity::Entity(Bounds hitboxSquare,ALLEGRO_BITMAP* ts)
{
	//framecount = -1;
    mybounds = hitboxSquare;
	isliveingcreature = false;
	curenthealth = 1;
	immoveing = false;
	speed = 5;
	isahitbox = true;
	projecsprite = SpriteProjectile(ts);
}
Entity::Entity(string file)
{
	frametimeout = -1;
	load(file);
	hasbeeninited = true;
	immoveing = false;
	isahitbox = false;
}
Entity::Entity(string nam,ALLEGRO_BITMAP* ts,int w,int h,ALLEGRO_SAMPLE* atksnd,ALLEGRO_SAMPLE* dmgsnd,ATACKSTYLE sty,int hp,int dmg)
{
	//framecount = -1;
	sprite = SpriteCharicter(ts);
	monatacknoise = atksnd;
	mondamagesnd = dmgsnd;
	style = sty;
	isliveingcreature = true;
	alive = false;
	//frameinformation
	//framecount = 0;
	//animation = STANDING;
	//direction = FORWARD;
	//delay = 0;
	//maxDelay = 1;
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
	immoveing = false;
	isahitbox = false;
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
		//al_draw_filled_rectangle(mybounds.getX() - (mybounds.getW() / 2),mybounds.getY() - (mybounds.getH() / 2),mybounds.getX() + (mybounds.getW() / 2),mybounds.getY() + (mybounds.getH() / 2),al_map_rgb(255,0,0));
		sprite.Draw(mybounds.getX(),mybounds.getY());
		if(sprite.getAnimation() == DEAD)
		{
			if(sprite.hasCompletedAnimationOnce())
			{
				alive = false;
			}
		}
	}
	else
	{
		if(isahitbox)
		{
			//al_draw_filled_rectangle(mybounds.getX(),mybounds.getY(),mybounds.getX() + mybounds.getW(),mybounds.getY() + mybounds.getH(),al_map_rgb(255,255,255));
			projecsprite.Draw(mybounds.getX(),mybounds.getY());
		}
		
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
			if(!mypather.locationHasBeenSet()){mypather.setMyLocation(Point(mybounds.getGridPos().getX(),mybounds.getGridPos().getY()));}
			if(!mypather.targetHasBeenSet()){mypather.setTargetLocation(Point(players[0].getBounds().getGridPos().getX(),players[0].getBounds().getGridPos().getY()));}
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
			//ok got the path ext ext. lets set this puppy to move!
			mypather.updatePather(speed);
			if(!immoveing)
			{
				ACTIONS action;
				if(mypather.getDistanceToTarget() > 3)
				{
					sprite.setDirection(mypather.moveThisDirectionOneSpaceToGetToGoal());
					statechanged = true;
					immoveing = true;
					action = WALK;
				}
				else
				{
					action = ATACK;
				}
			switch (action)
			{
			case STAND:
				sprite.setAnimation(STANDING);
				break;
			case WALK:
				sprite.setAnimation(WALKING);
				break;
			case ATACK:
				if(sprite.getAnimation() == SLASH)
				{
					return; //if were already atacking then dont atack again....
				}
				//TODO: Get enemy weapon and then run atack animation
				sprite.setAnimation(SLASH);
				statechanged = true;
				immoveing = false;
				
				break;
			default:
				break;
			}
				
			}
		}
	}
	if(statechanged)
	{
		double varience = rand() % 100 + 1;
		switch(sprite.getAnimation())
		{
		case ULTI:
			//TODO: ultimate code
			break;
		case WAND:
			//TODO: Spawn fireball projectile
			break;
		case WALKING:
			switch (sprite.getDirection())
			{
			case BACK:
				if(tiles[((int)(mybounds.getY() - 16.0f/* + 32.0f*/)/32)-1][((int)(mybounds.getX()/*+ 32.0f*/)/32)].passable())//
				{
					mybounds.setY(mybounds.getY() - (speed + (varience / 200.0 )));
				}
				break;
			case LEFT:
				if(tiles[((int)(mybounds.getY())/32)-1][((int)(mybounds.getX() - 16.0f)/32)].passable())
				{
					mybounds.setX(mybounds.getX() - (speed + (varience / 200.0 )));
				}
				break;
			case FORWARD:
				if(tiles[((int)(mybounds.getY() - 16.0f/* + 32.0f*/)/32)][((int)(mybounds.getX())/32)].passable())
				{
					mybounds.setY(mybounds.getY() + (speed + (varience / 200.0 )));
				}
				break;
			case RIGHT:
				if(tiles[((int)(mybounds.getY() - 32.0f)/32)][((int)(mybounds.getX() - 16.0f)/32)+1].passable())
				{
					mybounds.setX(mybounds.getX() + (speed + (varience / 200.0 )));
				}
			default:
				break;
			}
			break;
		case SLASH:
			getGameRefrence()->sendMessageToAllObjects("ENEMY_0_SLASH",CLASSTYPE_DUNGION);
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
		if(sprite.hasCompletedAnimationOnce())
		{
			if(sprite.getAnimation() == WALKING)
			{
				immoveing = false;
			}
			statechanged = false;
		}
	}
	if(!isliveingcreature && (velocityx != 0 || velocityy != 0))
	{
		mybounds.setX(mybounds.getX() + velocityx * speed);
		mybounds.setY(mybounds.getY() - velocityy * speed);
		if(!projecsprite.angleHasBeenSet())
		{
			Point getchords = players[0].getLastKnownMouseChords();
			projecsprite.setRotation(getAngleToTarget(players[0].getBounds().getX(),players[0].getBounds().getY() * -1.0f,getchords.getX(),getchords.getY() * -1.0f));
		}
		if(!(tiles[((int)mybounds.getY()/32)][((int)mybounds.getX()/32)].passable()))
		{
			alive = false;//i hit a wall, explode!
		}
		if(mybounds.getX() > SCREEN_WIDTH + 50 || mybounds.getY() > SCREEN_HEIGHT + 50)
		{
			alive = false;
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
		sprite = SpriteCharicter(load_image(myconcat(2,"Monster\\",filemontileset.c_str())));
		monatacknoise = load_sound(myconcat(2,"Monster\\",filemonatksnd.c_str()));
		mondamagesnd = load_sound(myconcat(2,"Monster\\",filemonhitsnd.c_str()));
		//TODO: Get monster atack style
		hpbace = atoi(filemonhpbace.c_str());
		curenthealth = atoi(filemonhpbace.c_str());
		damagebace = atoi(filemondmgbace.c_str());
		isliveingcreature = true;
		//framecount = 0;
		//animation = STANDING;
		//direction = FORWARD;
		//delay = 0;
		//maxDelay = 1;
		statechanged = false;
		mybounds.setX(128.0f);
		mybounds.setY(128.0f);
		mybounds.setW(atoi(filemonwidth.c_str()));
		mybounds.setH(atoi(filemonheight.c_str()));
		speed = 1.0f;
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
	if(curenthealth < 0 && sprite.getAnimation() != DEAD)
	{
		statechanged = true;
		sprite.setAnimation(DEAD);
		if(isahitbox)
		{
			alive = false;
		}
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
void Entity::setVelocity(float xv,float yv)
{
	velocityy= yv;
	velocityx = xv;
}