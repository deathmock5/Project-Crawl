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

#ifndef _MENU_H_
#define _MENU_H_

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
using namespace std;
class Menu
{
public:
	Menu(void);
	~Menu(void);
	void draw();
	string hasScrolledOverOption(float x,float y);
	void acitonClick(string);
	void addButton(float x, float y, ALLEGRO_BITMAP *imageup,ALLEGRO_BITMAP *imagedown,string action);
	void addImage(float x, float y, ALLEGRO_BITMAP *image);
private:
	int buttons;
	vector<string> btnactions;
	vector<ALLEGRO_BITMAP*> btnimages;
	vector<ALLEGRO_BITMAP*> btnimagesdown;
	vector<int> btnxpos;
	vector<int> btnypos;
	vector<bool> btnisdown;
	vector<ALLEGRO_BITMAP*> images;
	vector<int> imagexpos;
	vector<int> imageypos;
	
};
#endif

