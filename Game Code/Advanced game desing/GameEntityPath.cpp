#include "GameEntityPath.h"


GameEntityPath::GameEntityPath(void)
{
	hasvalidlocation = false;
	hasvalidtarget = false;
	hasvlidmap = false;
	pathtoplayer = "";
	n = 19;
	m = 25;
	dir = 4;
	totalunitsmoved = 32;
}
void GameEntityPath::setMyLocation(Point location)//give the x/y cords.
{
	mylocation = location;
	hasvalidlocation = true;
}
void GameEntityPath::setTargetLocation(Point target)
{
	mytarget = target;
	hasvalidtarget = true;
}
void GameEntityPath::setMap(int	mymap[19][25])
{
	for(int h = 0;h < 19;h++)
	{
		for(int w = 0;w < 25;w++)
		{
			map[h][w] = mymap[h][w];
			//cout << map[h][w];
		}
		//cout << endl;
	}
	hasvlidmap = true;
}
bool GameEntityPath::locationHasBeenSet()
{
	return hasvalidlocation;
}
bool GameEntityPath::targetHasBeenSet()
{
	return hasvalidtarget;
}
bool GameEntityPath::mapHasBeenSet()
{
	return hasvlidmap;
}
bool GameEntityPath::pathHasBeenComputed()
{
	if(pathtoplayer == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool GameEntityPath::entityNeedRepath(int unitsmoved)
{
	totalunitsmoved += unitsmoved;
	if(totalunitsmoved >= 32)
	{
		totalunitsmoved = 0;
		return true;
	}
	else
	{
		return false;
	}
}
void GameEntityPath::beginPathing()
{
	if(pathtoplayer == "")
	{
		pathtoplayer = computePath();
		//logHelperMessage(INFO,2,"Path:'",pathtoplayer.c_str());
	}
}
void GameEntityPath::updatePather(float entityspeed)
{
	if(entityNeedRepath((int)entityspeed))
	{
		pathtoplayer = "";
		beginPathing();
		hasvalidlocation = false;
		hasvalidtarget = false;
	}
}
string GameEntityPath::computePath()
{
	if(hasvalidlocation && hasvalidtarget && hasvlidmap)
	{
	priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
    int pqi; // pq index
    Node* n0;
    Node* m0;
    int i, j, x, y, xdx, ydy;
    char c;
    pqi=0;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	int closed_nodes_map[25][19]; // map of closed (tried-out) nodes
	int open_nodes_map[25][19]; // map of open (not-yet-tried) nodes
	int dir_map[25][19]; // map of directions

	int xStart = mylocation.getX();
	int yStart = mylocation.getY();
	int xFinish = mytarget.getX();
	int yFinish = mytarget.getY();
    // reset the node maps
    for(y=0;y<n;y++)
    {
        for(x=0;x<m;x++)
        {
			//cout << map[y][x];
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
		//cout << endl;
    }
	//cout << "____" << endl;
    // create the start node and push into list of open nodes
    n0=new Node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[x][y]=n0->getPriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty())
    {
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new Node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // remove the node from the open list
        open_nodes_map[x][y]=0;
        // mark it on the closed nodes map
        closed_nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==xFinish && y==yFinish) 
        {
            // generate the path from finish to start
            // by following the directions
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();           
            return path;
        }
        // generate moves (child nodes) in all possible directions
        for(i=0;i<dir;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];
            if(!(xdx<0 || xdx>m-1 || ydy<0 || ydy>n-1 || map[xdx][ydy]==1 /* test */
                || closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new Node( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(xFinish, yFinish);
                // if it is not in the open list then add into that
				if(open_nodes_map[xdx][ydy]==0)
				{
					open_nodes_map[xdx][ydy]=m0->getPriority();
					pq[pqi].push(*m0);
					// mark its parent node direction
					dir_map[xdx][ydy]=(i+dir/2)%dir;
				}
                else if(open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+dir/2)%dir;
                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getxPos()==xdx && 
                           pq[pqi].top().getyPos()==ydy))
                    {
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();     
						//cout <<"{" << xdx << "," << ydy << "}";
						if(pq[pqi].size() == 0)
						{
							return "N";
						}
                    }
                    pq[pqi].pop(); // remove the wanted node
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                else delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
	}
	return "N"; // no route found
}
DIRECTION GameEntityPath::moveThisDirectionOneSpaceToGetToGoal()
{
	int dir = 0;
	if(pathtoplayer == "N")
	{
		pathtoplayer = ""; // force a repath
		dir = rand() % 4;
	}
	else
	{
		//return StringToNumber<int>(pathtoplayer.substr(pathtoplayer.length() - 1));
		dir = atoi(pathtoplayer.substr(0,1).c_str());
	}
	//TODO: lets make this ent move!
					/*
					* -3-
					* 2-0
					* -1-
					*/
	switch (dir)
	{
	case 3:
		//logHelperMessage(INFO,1,"FOR");
		return BACK;
		break;
	case 2:
		//logHelperMessage(INFO,1,"lef");
		return LEFT;
		break;
	case 1:
		//logHelperMessage(INFO,1,"bak");
		return FORWARD;
		break;
	case 0:
		//logHelperMessage(INFO,1,"rig");
		return RIGHT;
		break;
	default:
		//logHelperMessage(WARNING,2,"Unknown direction:",dir);
		return LEFT;
		break;
	}
}
int GameEntityPath::getDistanceToTarget()
{
	if(pathHasBeenComputed() && pathtoplayer != "N")
	{
		return (int)pathtoplayer.size();
	}
	else
	{
		return 999;
	}
}
GameEntityPath::~GameEntityPath(void)
{

}