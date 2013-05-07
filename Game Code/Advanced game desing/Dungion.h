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
class EventManager;
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
#include <math.h>
#include "SystemVars.h"
#include "Entity.h"
#include "Player.h"
#include "EventManager.h"
#include "GameObject.h"
#include "Map.h"

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
	virtual void sendMessage(string data);
	Map* reftoCurrentMap();
	Player* refToCurrentPlayer();
	bool curentMapDoorUnlocked();
	void unllockCurentMapDoor();
	int curentplayers;
	std::vector<Player> players;
private:
	//methods.
	void Load(string);
	Map getRandomRoomDesign();
	Map getRandomRoomDesignWC();
	EventManager* thisdungenventmanager;
	//variables
	ALLEGRO_BITMAP* tileset;
	ALLEGRO_BITMAP* arrowsprite;
	ALLEGRO_BITMAP* fireballsprite;

	int rooms;
	int curentroom;
	int dificulty;
	std::vector<Map> maps;
	string bgs;
};
#endif