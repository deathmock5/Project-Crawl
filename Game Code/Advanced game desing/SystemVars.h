#pragma once
//=================================
// include guard
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#ifndef _SYSTEMVARS_H_
#define _SYSTEMVARS_H_

//=================================
// forward declared dependencies
class Game;
//=================================
// included dependencies
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include "Game.h"
using namespace std;
//=================================
// the actual class
//TODO: update all enums to ENUMNAME_TYPE
#ifndef _GAMEENUMS_
#define _GAMEENUMS_
const enum loglevel{INFO,WARNING,OK,SEVERE};
const enum ATACKSTYLE{MAGIC,MELEE,RANGED}; 
const enum ACTIONS{STAND,WALK,ATACK};
const enum FRAMESET{ULTI = 0,WAND = 1, WALKING = 2,SLASH = 3,BOW = 4,DEAD = 5,STANDING = 6};
const enum DIRECTION{BACK,LEFT,FORWARD,RIGHT};
const enum TAGANDCOLIDERTYPES{TAGENEMY,TAGPLAYER,TAGTORCH};
const enum GAUGETYPES{GAUGE_FILL,GAUGE_LAYER};
const enum GAMEEVENTTYPE{EVENT_DIALOG,EVENT_ENTITYSPAWN,EVENT_LIGHTCHANGE,EVENT_SPAWNTORCH,EVENT_SPAWNGOLD,EVENT_PLAYSFX,EVENT_MOVEPLAYER,EVENT_ROOMENTER,EVENT_WARP};
const enum LINETYPE{
	LINETYPE_COMMENT,
	LINETYPE_DIALOG,
	LINETYPE_SPAWNENTITY,
	LINETYPE_CHANGELIGHTLEVEL,
	LINETYPE_SPAWNTORCH,
	LINETYPE_SPAWNGOLD,
	LINETYPE_PLAYSFX,
	LINETYPE_MOVEPLAYER,
	LINETYPE_ONROOMENTER,
	LINETYPE_WARPTOMAP,
	LINETYPE_UNKNOWN
};
const enum CLASSTYPE{CLASSTYPE_NULL,CLASSTYPE_PLAYER,CLASSTYPE_DUNGION,CLASSTYPE_ENTITY,CLASSTYPE_MAP,CLASSTYPE_MENU,CLASSTYPE_SOUNDMANAGER,CLASSTYPE_EVENTMANAGER};
#endif

ALLEGRO_BITMAP* load_image(string);
ALLEGRO_SAMPLE* load_sound(string);
void logHelperMessage(loglevel,int, ...);
void threadedloghelpermessage(loglevel,string);
void updateThreadQue();
void setGameRefrence(Game*);
Game* getGameRefrence();
//utils
template <typename T>
string NumberToString ( T Number );
template <typename T>
T StringToNumber ( const string &Text );
string myconcat(string,string,string);
string myconcat(int,...);
string getrandommaplayout(bool);
float getAngleToTarget(float x1,float y1,float x2,float y2);
#ifndef _GAMECONSTS_
#define _GAMECONSTS_
const int SCREEN_TILE_WIDTH = 25;
const int SCREEN_TILE_HEIGHT = 19;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;
const int GAMEFPS = 30;
const bool IS_IN_DEBUG_MODE = true;

#endif
#endif