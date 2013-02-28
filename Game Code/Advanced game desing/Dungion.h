#pragma once

//Allegro Imports
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_image.h>

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

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
private:
	//methods.
	void Load(string);

	//variables
	ALLEGRO_BITMAP* tileset;
	ALLEGRO_SAMPLE* bgs;
	int rooms;
	int curentroom;
	std::vector<Map> maps;
};