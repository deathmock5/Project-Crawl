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
//variables
//	ALLEGRO_BITMAP* tileset;
//	ALLEGRO_SAMPLE* bgs;
//	int rooms;
//	int curentroom;
//	std::vector<Map> maps;

Dungion::Dungion(void)
{
	//tileset
	//bgs
	rooms = 0;
	curentroom = 0;
	//load
}

Dungion::Dungion(string dungfile)
{
	Load(dungfile);
}

Dungion::Dungion(Player curentplayer)
{
	//TODO: Load from player.
}

Dungion::~Dungion(void)
{
	//TODO: Unload information
}

void Dungion::Draw()
{
	//TODO: Draw
}

void Dungion::Update()
{
	//TODO: Update
}

void Dungion::Load(string myfile)
{
	//TODO: loadshit.
	ifstream dungfile;
	ifstream maptemplate;
	ifstream monstertemplate;
	dungfile.open(myfile.c_str());
	//dungfile.open(myfile.c_str());
	
    if(!dungfile.fail())
    {
		logHelperMessage(OK,3,"File:'",myfile.c_str(),"' open.");
		char next = '\n';
        string filetileset;
		string filebgs;
		string filenumrooms;
		string filemon1;
		string filemon2;
		string fileboss;
		dungfile.get(next);
		dungfile.get(next);
		dungfile.get(next);
		dungfile >> filetileset;
		filetileset = myconcat("Images\\","TileSets\\",filetileset);
		dungfile >> filebgs;
		//filebgs = strcat("Sound\\BGS\\",filebgs.c_str());
		dungfile >> filenumrooms;
		dungfile >> filemon1;
		dungfile >> filemon2;
		dungfile >> fileboss;
		logHelperMessage(INFO,1,filetileset.c_str());
		logHelperMessage(INFO,1,filebgs.c_str());
		logHelperMessage(INFO,1,filenumrooms.c_str());
		logHelperMessage(INFO,1,filemon1.c_str());
		logHelperMessage(INFO,1,filemon2.c_str());
		logHelperMessage(INFO,1,fileboss.c_str());
		dungfile.close();//close file
		tileset = load_image(filetileset);//load tileset
		bgs = load_sound(filebgs); //Load bgs
        //TODO: get difculty multiplier
        //TODO:		set darkness level bace
		Entity monster1;
		Entity monster2;
			  //monsters.push_back(
        //TODO:		load monster(s)
        //TODO:     	load spritesheet
        //TODO:			load bgs
        //TODO:	get a basic room
        //bool keyneeded = false;
        /*for(rooms)
        {   
            if(rooms % 4)
            {
                request new locked door 
                Map newmap = makenewroom(avalibleRooms,true);
                
            }
            
        }*/
        }
    else
    {
		logHelperMessage(SEVERE,2,"Unable to open file:",myfile);
        //cout << "Unable to open file:" << myfile << endl;
    }
    
}

Map* Dungion::reftoCurrentMap()
{
	return &maps[curentroom];
}