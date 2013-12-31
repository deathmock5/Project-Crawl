#pragma once
//=================================
// include guard
#ifndef _GameSoundManager_H_
#define _GameSoundManager_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <allegro5\allegro.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include "SystemVars.h"
#include <iostream>
#include <vector>
using namespace std;
//=================================
// the actual class
class GameSoundManager
{
public:
	GameSoundManager(void);
	void preLoadBGSFile(string file);
	void preLoadSFXFile(string file);
	void playSFX(string file);
	void pauseMusic();
	void playMusic();
	void stopMusic();
	void transitionBGMTo(string file);
	void sendMessage(string data);
	~GameSoundManager(void);
private:
	vector<ALLEGRO_SAMPLE*> bgs;
	vector<string> bgs_filenames;
	vector<ALLEGRO_SAMPLE*> sfx;
	vector<string> sfx_filenames;
	ALLEGRO_SAMPLE_ID bgs_id;
	string bgscurentplaying;
};
#endif
