#pragma once

//=================================
// include guard
#ifndef _Dungion_h_
#define _Dungion_h_

//=================================
// forward declared dependencies
class Player;
class Map;
class Entity;

//=================================
// included dependencies
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
#include "Player.h"
#include "Map.h"
#include "Entity.h"
#include "GameObject.h"
#include "EventManager.h"
using namespace std;
using std::ifstream;

class Dungion : public GameObject
{
public:
	Dungion(void);
	Dungion(string);//path to dungfile
	Dungion(Player);//if loading from a player
	~Dungion(void);
	//operators
	Dungion & operator =(const Dungion &rhs);
	void Draw();
	void Update();
	void triggerPlayerTransferToNewMap(int tomap,int playerid);
	
	Map* reftoCurrentMap();
	Player* refToCurrentPlayer();
		
	int curentplayers;
	std::vector<Player> players;
private:
	//methods.
	void Load(string);
	Map getRandomRoomDesign();
	Map getRandomRoomDesignWC();
	EventManager thisdungenventmanager;
	//variables
	ALLEGRO_BITMAP* tileset;
	ALLEGRO_SAMPLE* bgs;
	int rooms;
	int curentroom;
	int dificulty;
	std::vector<Map> maps;
	//
	//players

};
#endif