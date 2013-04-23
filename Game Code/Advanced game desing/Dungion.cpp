#include "Dungion.h"
using namespace std;
using std::ifstream;
//methods
//	Dungion(void);
//	Dungion(string);//path to dungfile
//	Dungion(Player);//if loading from a player
//	~Dungion(void);
//	void Draw();
//	void Update();
//	void Load();
//variables07/skill Potion
//	ALLEGRO_BITMAP* tileset;
//	ALLEGRO_SAMPLE* bgs;
//	int rooms;
//	int curentroom;
//	std::vector<Map> maps;
//TODO: move player into this file
Dungion::Dungion(void) : GameObject(CLASSTYPE_DUNGION)
{
	//tileset
	//bgs
	rooms = 0;
	curentroom = 0;
	//load
}

Dungion::Dungion(string dungfile): GameObject(CLASSTYPE_DUNGION)
{
	Load(dungfile);
	curentroom = 0;
	maps[curentroom].show();
}

Dungion::Dungion(Player curentplayer): GameObject(CLASSTYPE_DUNGION)
{
	//TODO: Load from player.
}

Dungion::~Dungion(void)
{
	//TODO: Unload information
}

Dungion& Dungion::operator=(const Dungion &rhs) {
    // Do the assignment operation!
	//variables
	//ALLEGRO_BITMAP* tileset;
	//ALLEGRO_SAMPLE* bgs;
	///int rooms;
	//int curentroom;
	//int dificulty;
	//std::vector<Map> maps;
	curentplayers = rhs.curentplayers;
	players = rhs.players;
	tileset = rhs.tileset;
	bgs = rhs.bgs;
	rooms = rhs.rooms;
	curentroom = rhs.curentroom;
	dificulty = rhs.dificulty;
	maps = rhs.maps;
    return *this;  // Return a reference to myself.
 }

void Dungion::Draw()
{
	//TODO: Draw
	maps[curentroom].draw();
	for(int i = 0;i < curentplayers;i++)
		{
			players[i].draw();
		}
	/*for(int i = 0;i < curentplayers;i++)
		{
			players[i].drawLight(torchlight);
		}*/
}

void Dungion::Update()
{
	//TODO: Update
	maps[curentroom].update(*this);
}

void Dungion::Load(string myfile)
{
	//TODO: loadshit.
	ifstream dungfile;
	dungfile.open(myconcat(5,"Dungions\\",myfile.c_str(),"\\",myfile.c_str(),".dung"));
	//dungfile.open(myfile.c_str());
	
    if(!dungfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myconcat(5,"Dungions\\",myfile.c_str(),"\\",myfile.c_str(),".dung").c_str(),"' open.");
		char next = '\n';
        string filetileset;
		string filebgs;
		string filenumrooms;
		string filemon1;
		string filemon2;
		string fileboss;
		string dungionscript = "null";
		dungfile.get(next);
		dungfile.get(next);
		dungfile.get(next);
		dungfile >> filetileset;
		filetileset = myconcat("Images\\","TileSets\\",filetileset);
		dungfile >> filebgs;
		//TODO: filebgs = strcat("Sound\\BGS\\",filebgs.c_str());
		dungfile >> filenumrooms;
		dungfile >> filemon1;
		dungfile >> filemon2;
		dungfile >> fileboss;
		if(!dungfile.eof())
		{
			dungfile >> dungionscript;
			thisdungenventmanager.loadEvents(dungionscript);
		}
		//logHelperMessage(INFO,1,filetileset.c_str());
		//logHelperMessage(INFO,1,filebgs.c_str());
		//logHelperMessage(INFO,1,filenumrooms.c_str());
		//logHelperMessage(INFO,1,filemon1.c_str());
		//logHelperMessage(INFO,1,filemon2.c_str());
		//logHelperMessage(INFO,1,fileboss.c_str());
		dungfile.close();//close file
		tileset = load_image(filetileset);//load tileset
		ALLEGRO_BITMAP* torchlight = load_image(myconcat("Images/","LightCore", "/Light.png").c_str());
		//ALLEGRO_BITMAP* playertls = load_image(myconcat(
		bgs = load_sound(filebgs); //Load bgs
        //TODO: get difculty multiplier
        //TODO:	set darkness level bace
		Entity monster1 = Entity(filemon1);
		Entity monster2 = Entity(filemon2);
		dificulty = 1;
		Map newmap;
		int randx = 1;
		int randy = 1;
		srand(time(NULL));
		bool firstroom = true;
		for(int i = 0; i < atoi(filenumrooms.c_str());i++)
		{
			//newmap = Map();
			newmap = Map(tileset,torchlight,bgs,getrandommaplayout(false),i);
			for(int nm = 0; nm < 4; nm++)
			{
				//srand(i+nm + randx + randy);
				randx = rand() % 736 + 32;
				randy = rand() % 568 + 64;
				if(rand() % 2 + 1 == 1)
				{
					monster1.setBounds(Bounds(Point(randx,randy),64,64));
					monster1.addColider("PLAYER");
					monster1.addTag("ENEMY");
					monster1.addColider("PLAYER_SLASH");
					newmap.spawnEnttityInMap(monster1);
				}
				else
				{
					monster2.setBounds(Bounds(Point(randx,randy),64,64));
					monster2.addColider("PLAYER");
					monster2.addTag("ENEMY");
					monster2.addColider("PLAYER_SLASH");
					newmap.spawnEnttityInMap(monster2);
				}
			}
			if(firstroom)
			{
				firstroom = false;
			}
			else
			{
				//TODO: make doors a bit more random? also
				newmap.addDoor(BACK,i-1,false);
				maps[i-1].addDoor(FORWARD,i,false);
			}
			maps.push_back(newmap);
		}		
		curentroom = 0;
        }
		
    else
    {
		logHelperMessage(SEVERE,2,"Unable to open file:",myfile);
        //cout << "Unable to open file:" << myfile << endl;
    }
    curentplayers = 1;
	players.push_back(Player("Player"));
	
}

Map* Dungion::reftoCurrentMap()
{
	return &maps[curentroom];
}

Player* Dungion::refToCurrentPlayer()
{
	return &players[0];
}

void Dungion::triggerPlayerTransferToNewMap(int tomap,int playerid)
{
	curentroom = tomap;
	maps[curentroom].hide();
	maps[tomap].show();
	Bounds curentpos = players[playerid].getBounds();
	if(curentpos.getX() > 600)
	{
		//i exited right tp me left..
		curentpos.setX(64);
	}
	else if(curentpos.getX() < 300)
	{
		//i exited left tp me right..
		curentpos.setX(736);
	}
	else if(curentpos.getY() > 500)
	{
		//i exited down, tp me top.
		curentpos.setY(48);
	}
	else
	{
		//i exited top, tpme botom.
		curentpos.setY(536);
	}
	players[playerid].setBounds(curentpos);
}