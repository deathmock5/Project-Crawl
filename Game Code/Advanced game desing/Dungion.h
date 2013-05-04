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
#include <math.h>
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
	virtual void sendMessage(string data) override;
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
	ALLEGRO_BITMAP* arrowsprite;
	ALLEGRO_BITMAP* fireballsprite;
	ALLEGRO_SAMPLE* bgs;
	ALLEGRO_SAMPLE* monster_atack;
	ALLEGRO_SAMPLE* monster_atack2;
	ALLEGRO_SAMPLE* monster_atack3;
	ALLEGRO_SAMPLE* monster_atack4;
	ALLEGRO_SAMPLE* monster_atack5;
	ALLEGRO_SAMPLE* monster_atack6;
	ALLEGRO_SAMPLE* monster_damaged;
	ALLEGRO_SAMPLE* monster_damaged2;
	ALLEGRO_SAMPLE* player_atack;
	ALLEGRO_SAMPLE* player_damaged;
	ALLEGRO_SAMPLE* weapon_melee_swipe;
	ALLEGRO_SAMPLE* weapon_melee_hit;
	ALLEGRO_SAMPLE* weapon_ranged_fire;
	ALLEGRO_SAMPLE* weapon_ranged_hit;
	ALLEGRO_SAMPLE* weapon_magic_cast;
	ALLEGRO_SAMPLE* weapon_magic_hit;

	int rooms;
	int curentroom;
	int dificulty;
	std::vector<Map> maps;
};
#endif