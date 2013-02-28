#include "Dungion.h"

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
	dungfile.open(myfile);
    if(dungfile.is_open())
    {
        char * filetileset;
		char * filebgs;
		char * filenumrooms;
		char * filemon1;
		char * filemon2;
		char * fileboss;
		dungfile >> filetileset;
		filetileset = strcat("Images\\TileSets\\",filetileset);
		dungfile >> filebgs;
		filebgs = strcat("Sound\\BGS\\",filebgs);
		dungfile >> filenumrooms;
		dungfile >> filemon1;
		dungfile >> filemon2;
		dungfile >> fileboss;
		tileset = al_load_bitmap(filetileset);	//load tileset
        //TODO: Load bgs
        //TODO: get difculty multiplier
        //TODO:		set darkness level bace
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
        cout << "Unable to open file:" << myfile << endl;
    }
    
}