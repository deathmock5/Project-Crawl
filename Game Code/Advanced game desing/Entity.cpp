#include "Entity.h"
using namespace std;
using std::ifstream;
Entity::Entity()
{
	framecount = -1;
	hasbeeninited = false;
	mapHasBeenSet = false;
}
Entity::Entity(float spawnx,float spawny)
{
	hasbeeninited = false;
	curenthealth = 1;
	mapHasBeenSet = false;
}
Entity::Entity(Bounds hitboxSquare,bool ishitbox)
{
	framecount = -1;
	mybounds = hitboxSquare;
	isliveingcreature = false;
	curenthealth = 1;
	mapHasBeenSet = false;
}
Entity::Entity(string file)
{
	frametimeout = -1;
	load(file);
	hasbeeninited = true;
	mapHasBeenSet = false;
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
	mapHasBeenSet = false;
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
		if(!mapHasBeenSet)
		{
			for(int h = 0;h < 19;h++)
			{
				for(int w = 0; w < 25;w++)
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
			mapHasBeenSet = true;
		}
		else
		{
			//ok the map is all set up.
			//Lets get a apath!
			if(pathtoplayer == "")
			{
				//lets try to path;
				//pathtoplayer = pathFind(players[0].getBounds().getGridPos());//TODO: thread me.
				//TODO: a* causes pointer errors.
			}
			else
			{
				//TODO: lets make this ent move!
				/*
				* -3-
				* 2-0
				* -1-
				*/
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
string Entity::pathFind(Point playerpos)
{
	//TODO: move the statics.
	//TODO: threading.
	//const int & xStart, const int & yStart, const int & xFinish, const int & yFinish
	n = 25; // horizontal size of the map
	m = 19; // vertical size size of the map
	dir = 4; // number of possible directions to go at any position
	// if dir==4
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	// if dir==8
	//static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
	//static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};
	int i, j, x, y, xdx, ydy;
    char c;
    pqi=0;

    // reset the Node maps
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_Nodes_map[x][y]=0;
            open_Nodes_map[x][y]=0;
        }
    }

    // create the start Node and push into list of open Nodes
    n0=new Node(mybounds.getX(), mybounds.getY(), 0, 0);
    n0->updatePriority(playerpos.getX(), playerpos.getY());
    pq[pqi].push(*n0);
    open_Nodes_map[x][y]=n0->getPriority(); // mark it on the open Nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current Node w/ the highest priority
        // from the list of open Nodes
        n0=new Node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // remove the Node from the open list
        open_Nodes_map[x][y]=0;
        // mark it on the closed Nodes map
        closed_Nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==playerpos.getX() && y==playerpos.getY()) 
        {
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==mybounds.getX() && y==mybounds.getY()))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover Nodes
            while(!pq[pqi].empty()) pq[pqi].pop();           
            return path;
        }

        // generate moves (child Nodes) in all possible directions
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || map[xdx][ydy]==1 
                || closed_Nodes_map[xdx][ydy]==1))
            {
                // generate a child Node
                m0=new Node( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(playerpos.getX(), playerpos.getY());

                // if it is not in the open list then add into that
                if(open_Nodes_map[xdx][ydy]==0)
                {
                    open_Nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    // mark its parent Node direction
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                }
                else if(open_Nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open_Nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+dir/2)%dir;

                    // replace the Node
                    // by emptying one pq to the other one
                    // except the Node to be replaced will be ignored
                    // and the new Node will be pushed in instead
                    while(!(pq[pqi].top().getxPos()==xdx && 
                           pq[pqi].top().getyPos()==ydy))
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pq[pqi].pop(); // remove the wanted Node
                    
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better Node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return ""; // no route found
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