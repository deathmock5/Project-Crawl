#pragma once
#ifndef _allegro_h_
#define _allegro_h_
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#endif // !_allegro_h_

#ifndef _MENU_H_
#define _MENU_H_

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "Bounds.h"
#include "SystemVars.h"
#include "GameObject.h"
using namespace std;
class Menu : public GameObject
{
public:
	Menu(void);
	~Menu(void);
	void draw();
	string hasScrolledOverOption(float x,float y);
	void acitonClick();
	virtual void sendMessage(string data) override;
	//adds
	void addButton(float x, float y, ALLEGRO_BITMAP *imageup,ALLEGRO_BITMAP *imagedown,string action,void (*function)());
	void addImage(float x, float y, ALLEGRO_BITMAP *image);
	void addText(Bounds,string,string);
	void addNumber(Bounds,string,int);
	void addGauge(ALLEGRO_BITMAP*,Bounds,GAUGETYPES,int,string);
	void addDialog(ALLEGRO_BITMAP*,string);
	//removers
	void removeButton(string);
	//updaters
	void showDialog();
	void closeDialog();
	void updateGaugeValue(string,int);
	void mouseLocation(int,int);
	void setClickSound(string);
	void setBgs(string);
	void playBgs();
	void pauseBgs();
	
private:
	ALLEGRO_FONT *whiteArial24;
	bool aDialogIsShown;
	//button
	vector<string> btnactions;
	vector<void (*)()> buttonactionpointers;
	vector<ALLEGRO_BITMAP*> btnimages;
	vector<ALLEGRO_BITMAP*> btnimagesdown;
	vector<short> btnxpos;
	vector<short> btnypos;
	vector<bool> btnisdown;
	string curenthoverdoption;

	//image
	vector<ALLEGRO_BITMAP*> images;
	vector<short> imagexpos;
	vector<short> imageypos;

	//text
	vector<string> textvars;
	vector<string> textuniqueID;
	vector<Bounds> textbounds;

	//number
	vector<int> numbervars;
	vector<string> numberuniqueids;
	vector<Bounds> numberbounds;

	//dialog
	vector<ALLEGRO_BITMAP*> dialogImages;
	vector<Bounds> dialogbounds;
	vector<string> dialogtexts;

	//sound
	string menubgs;
	string menuclicksound;
	string menuhoversound;

	//gauge
	vector<ALLEGRO_BITMAP*> gaugeimages;
	vector<string> gaugenames;
	vector<Bounds> gaugepositions;
	vector<int> gaugevalues;
	vector<int> gaugemaxes;
	vector<GAUGETYPES> gaugetypes;
};
#endif

