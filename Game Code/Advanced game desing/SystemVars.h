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
using namespace std;
//enums
const enum loglevel{INFO,WARNING,OK,SEVERE};


ALLEGRO_BITMAP* load_image(string);
void logHelperMessage(loglevel,int, ...);
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