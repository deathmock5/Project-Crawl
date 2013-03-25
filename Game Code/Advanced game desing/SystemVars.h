#pragma once
#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#endif // !_allegro_h_

#ifndef _systemvars_h_
#define _systemvars_h_
//includes
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
using namespace std;
//enums
const enum loglevel{INFO,WARNING,OK,SEVERE};
const enum ATACKSTYLE{MAGIC,MELEE,RANGED}; 
const enum ACTIONS{STAND,WALK,ATACK};
const enum FRAMESET{ULTI = 0,WAND = 1, WALKING = 2,SLASH = 3,BOW = 4,DEAD = 5,STANDING = 6};
const enum DIRECTION{BACK,LEFT,FORWARD,RIGHT};

//vector<string> listOfDnglv; //files

ALLEGRO_BITMAP* load_image(string);
ALLEGRO_SAMPLE* load_sound(string);
void logHelperMessage(loglevel,int, ...);
void threadedloghelpermessage(loglevel,string);
string myconcat(string,string,string);
string myconcat(int,...);
string getrandommaplayout(bool);

class SystemVars
{
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 640;
	static const int FPS = 30;
	static int bla;
	
private:

};
#endif