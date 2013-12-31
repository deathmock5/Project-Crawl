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
Dungion::Dungion(void) : GameObject()
{
	//tileset
	//bgs
	rooms = 0;
	curentroom = 0;
	//load
}

Dungion::Dungion(string dungfile) : GameObject(CLASSTYPE_DUNGION)
{
	Load(dungfile);
	curentroom = 0;
	maps[curentroom].show();
	//logHelperMessage(INFO,1,"Sending test");
	//getGameRefrence()->sendMessageToAllObjects("test",CLASSTYPE_PLAYER);
	
}

Dungion::Dungion(Player curentplayer): GameObject(CLASSTYPE_DUNGION)
{
	//TODO: Load from player.
}

Dungion::~Dungion(void)
{
	if(players.size() >= 1)
	{
		//delete &(players[0]);
	}
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
	rooms = rhs.rooms;
	curentroom = rhs.curentroom;
	dificulty = rhs.dificulty;
	maps = rhs.maps;
    return *this;
 }

void Dungion::Draw()
{
	//TODO: Draw
	maps[curentroom].draw();
	for(int i = 0;i < curentplayers;i++)
		{
			players[i].draw();
		}
	for(int i = 0;i < curentplayers;i++)
		{
			//players[i].drawLight(torchlight);
		}
}

void Dungion::Update()
{
	if(!thisdungenventmanager->isEventInProcess())
	{
		if(thisdungenventmanager->tickUpdate())
		{
			thisdungenventmanager->eventProcess();
		}
		else
		{
			maps[curentroom].update(*this);
		}
	}
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
		dungfile >> filetileset;
		filetileset = myconcat(3,"Images\\","TileSets\\",filetileset.c_str());
		dungfile >> filebgs;
		//TODO: filebgs = strcat("Sound\\BGS\\",filebgs.c_str());
		dungfile >> filenumrooms;
		dungfile >> filemon1;
		dungfile >> filemon2;
		dungfile >> fileboss;
		if(!dungfile.eof())
		{
			dungfile >> dungionscript;
			thisdungenventmanager = new EventManager();
			thisdungenventmanager->loadEvents(dungionscript);
			getGameRefrence()->registerGameObject(thisdungenventmanager);
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
		fireballsprite = load_image("Images\\Projectiles\\MagicAtack.png");
		arrowsprite = load_image("Images\\Projectiles\\ArrowAtack.png");

		getGameRefrence()->sendMessageToAllObjects(myconcat(2,"BGM_LOAD_Sound\\BGS\\",filebgs.c_str()),CLASSTYPE_SOUNDMANAGER);
		bgs = myconcat(2,"Sound\\BGS\\",filebgs.c_str());
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 1.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 2.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 3.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 4.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 5.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster 6.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster Hurt.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Monster Hurt 2.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Player Attack.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Player Hurt.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Big Sword Whip.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Big Sword Hit.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Arrow Shot.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Arrow Hit.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Magic Fire.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Magic Hit.wav",CLASSTYPE_SOUNDMANAGER);
        //TODO: get difculty multiplier 
        //TODO:	set darkness level bace
		Entity monster1 = Entity(filemon1);
		Entity monster2 = Entity(filemon2);
		dificulty = 1;
		Map newmap;
		//int randx = 1;
		//int randy = 1;
		srand(time(NULL));
		bool firstroom = true;
		for(int i = 0; i < atoi(filenumrooms.c_str());i++)
		{
			//newmap = Map();
			newmap = Map(tileset,torchlight,myconcat(2,"Sound\\BGS\\",filebgs.c_str()),getrandommaplayout(false),i);
			for(int nm = 0; nm < i * 2 + 1; nm++)
			{
				//srand(i+nm + randx + randy);
				//randx = rand() % 736 + 32;
				//randy = rand() % 568 + 64;
				if(rand() % 2 + 1 == 1)
				{
					//monster1.setBounds(Bounds(Point(0,0),64,64));
					monster1.addColider("PLAYER");
					monster1.addTag("ENEMY");
					monster1.addColider("PLAYER_SLASH");
					monster1.addColider("PLAYER_MAGIC");
					monster1.addColider("PLAYER_RANGE");
					newmap.spawnEnttityInMap(monster1);
				}
				else
				{
					//monster2.setBounds(Bounds(Point(0,0),64,64));
					monster2.addColider("PLAYER");
					monster2.addTag("ENEMY");
					monster2.addColider("PLAYER_SLASH");
					monster2.addColider("PLAYER_MAGIC");
					monster2.addColider("PLAYER_RANGE");
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
	Player* newplayer = new Player("MINE");
	getGameRefrence()->registerGameObject(newplayer);
	players.push_back(*newplayer);
}

Map* Dungion::reftoCurrentMap()
{
	return &maps[curentroom];
}

Player* Dungion::refToCurrentPlayer()
{
	return &players[0];
}
bool Dungion::curentMapDoorUnlocked()
{
	return true;
}
void Dungion::unllockCurentMapDoor()
{

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
	if(tomap == maps.size() - 1)
	{
		getGameRefrence()->sendMessageToAllObjects("BGM_PLAY_Sound\\BGS\\boss.wav",CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("BOSS",CLASSTYPE_EVENTMANAGER);
	}
	else
	{
		getGameRefrence()->sendMessageToAllObjects(myconcat(2,"BGM_PLAY_",bgs.c_str()).c_str(),CLASSTYPE_SOUNDMANAGER);
		getGameRefrence()->sendMessageToAllObjects("BOSS",CLASSTYPE_EVENTMANAGER);
	}
}

void Dungion::sendMessage(string data)
{
	//decompile the message.
	/*5,1,5,...
	PLAYR_1_MELEE
	ENEMY_14_MAGIC*/
	string identifer = data.substr(0,5);
	if(identifer == "PLAYR")
	{
		//player stuff
		//lets get the player
		string playernumb = data.substr(6,1);
		//now what does it want."PLAYER0_MAGIC"
		identifer = data.substr(8,5);
		if(identifer == "SLASH" || identifer == "MAGIC" || identifer == "RANGE")
		{
			Bounds atackhitboxbounds;
			Entity myatackhitbox;
			Point velocity;
			Point lastmouseloc = players[0].getLastKnownMouseChords();
			float angle = getAngleToTarget(players[0].getBounds().getX(),players[0].getBounds().getY(),lastmouseloc.getX(),lastmouseloc.getY());
			velocity.setX(cos(angle));
			velocity.setY(sin(angle));
			atackhitboxbounds.setW(32);
			atackhitboxbounds.setH(32);
			switch (players[0].getDirection())
					{
					case BACK:
						atackhitboxbounds.setX(players[0].getBounds().getX() - 16.0f);
						atackhitboxbounds.setY(players[0].getBounds().getY() - 48.0f);
						break;
					case LEFT:
						atackhitboxbounds.setX(players[0].getBounds().getX() - 48.0f);
						atackhitboxbounds.setY(players[0].getBounds().getY() - 20.0f);
						break;
					case FORWARD:
						atackhitboxbounds.setX(players[0].getBounds().getX() - 16.0f);
						atackhitboxbounds.setY(players[0].getBounds().getY() + 16.0f);
						break;
					case RIGHT:
						atackhitboxbounds.setX(players[0].getBounds().getX() + 16.0f);
						atackhitboxbounds.setY(players[0].getBounds().getY() - 20.0f);
						break;
					default:
						break;
					}
			myatackhitbox = Entity(atackhitboxbounds,fireballsprite);
			if(identifer == "SLASH")
			{
				//ok the player wants to slash.
					myatackhitbox.addTag("PLAYER_SLASH");
					myatackhitbox.addColider("ENEMY");
					myatackhitbox.setTimeout(3);
					maps[curentroom].spawnEnttityInMap(myatackhitbox,fireballsprite);
					getGameRefrence()->sendMessageToAllObjects("SFX_PLAY_Sound\\SFX\\Player Attack.wav",CLASSTYPE_SOUNDMANAGER);
					getGameRefrence()->sendMessageToAllObjects("SFX_PLAY_Sound\\SFX\\Big Sword Whip.wav",CLASSTYPE_SOUNDMANAGER);
			}
			if(identifer == "MAGIC")
			{
					myatackhitbox.addTag("PLAYER_MAGIC");
					myatackhitbox.addColider("ENEMY");
					myatackhitbox.setTimeout(3000);
					myatackhitbox.setVelocity(velocity.getX(),velocity.getY());
					maps[curentroom].spawnEnttityInMap(myatackhitbox,fireballsprite);
					getGameRefrence()->sendMessageToAllObjects("SFX_PLAY_Sound\\SFX\\Player Attack.wav",CLASSTYPE_SOUNDMANAGER);
					getGameRefrence()->sendMessageToAllObjects("SFX_PLAY_Sound\\SFX\\Magic Fire.wav",CLASSTYPE_SOUNDMANAGER);
			}
			if(identifer == "RANGE")
			{
					myatackhitbox.addTag("PLAYER_RANGE");
					myatackhitbox.addColider("ENEMY");
					myatackhitbox.setTimeout(3000);
					myatackhitbox.setVelocity(velocity.getX(),velocity.getY());
					maps[curentroom].spawnEnttityInMap(myatackhitbox,fireballsprite);
					getGameRefrence()->sendMessageToAllObjects("SFX_PLAY_Sound\\SFX\\Player Attack.wav",CLASSTYPE_SOUNDMANAGER);
					getGameRefrence()->sendMessageToAllObjects("SFX_LOAD_Sound\\SFX\\Arrow Shot.wav",CLASSTYPE_SOUNDMANAGER);
			}
			
		}
	}
	else if(identifer == "ENEMY")
	{
		//"ENEMY_0_SLASH"
		identifer = data.substr(8);
		logHelperMessage(INFO,1,"Enemy is declareing");
		if(identifer == "SLASH")
		{
			logHelperMessage(INFO,1,"---A melee atack");
		}
		else if(identifer == "MAGIC")
		{
			//magic 'n' shit
			logHelperMessage(INFO,1,"---A magic atack");
		}
		else if(identifer == "RANGE")
		{
			//fire that bitch an arrow.
			//bitches love arrows
			logHelperMessage(INFO,1,"---A ranged atack");
		}
	}
	else
	{
		logHelperMessage(INFO,3,"Message: '",data.c_str(),"' unknown.");
	}
}