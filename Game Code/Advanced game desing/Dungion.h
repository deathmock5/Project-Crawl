#pragma once

//Allegro Imports
#ifndef _dungion_h_
#define _dungion_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_image.h>


#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using std::ifstream;
#include "Player.h"
#include "Map.h"


class Dungion
{
public:
	Dungion(void);
	Dungion(string);//path to dungfile
	Dungion(Player);//if loading from a player
	~Dungion(void);
	void Draw();
	void Update();
	Map* reftoCurrentMap();
private:
	//methods.
	void Load(string);
	Map getRandomRoomDesign();
	Map getRandomRoomDesignWC();
	//variables
	ALLEGRO_BITMAP* tileset;
	ALLEGRO_SAMPLE* bgs;
	int rooms;
	int curentroom;
	std::vector<Map> maps;
	Entity monsters[2];
	Entity boss;
};
#endif