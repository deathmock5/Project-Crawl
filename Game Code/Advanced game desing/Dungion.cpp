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
	curentroom = 0;
	maps[curentroom].show();
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
	maps[curentroom].draw();
}

void Dungion::Update()
{
	//TODO: Update
	maps[curentroom].update();
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
		logHelperMessage(INFO,1,filetileset.c_str());
		logHelperMessage(INFO,1,filebgs.c_str());
		logHelperMessage(INFO,1,filenumrooms.c_str());
		logHelperMessage(INFO,1,filemon1.c_str());
		logHelperMessage(INFO,1,filemon2.c_str());
		logHelperMessage(INFO,1,fileboss.c_str());
		dungfile.close();//close file
		tileset = load_image(filetileset);//load tileset
		ALLEGRO_BITMAP* torchlight = load_image(myconcat("Images/","LightCore", "/Light.png").c_str());
		//ALLEGRO_BITMAP* playertls = load_image(myconcat(
		bgs = load_sound(filebgs); //Load bgs
        //TODO: get difculty multiplier
        //TODO:		set darkness level bace
		Entity monster1 = Entity(filemon1);
		Entity monster2 = Entity(filemon2);
		monsters[0] = monster1;
		monsters[1] = monster2;
		for(int i = 0; i < atoi(filenumrooms.c_str());i++)
		{
			//get a random room layout
			Map newmap = Map(tileset,torchlight,bgs,getrandommaplayout(false),i);
			//Map newmap = Map(myfile.c_str(),getrandommaplayout(false),0);
			//newmap.spawnEnttityInMap(monster1,0,0);
			//TODO: fill it with monstershizzles.
			maps.push_back(newmap);
		}		
			/*maptiles[12][0] = Tile(DOOR,lvtileset,12,0);
			maptiles[12][18] = Tile(DOOR,lvtileset,12,18);
			maptiles[0][9] = Tile(DOOR,lvtileset,0,9);
			maptiles[24][9] = Tile(DOOR,lvtileset,24,9);*/
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