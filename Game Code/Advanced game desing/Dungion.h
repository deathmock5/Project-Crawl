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

class Dungion
{
public:
	Dungion(void);
	Dungion(string);
	~Dungion(void);
	void Load();
	void Draw();
	void Update();
private:

};

