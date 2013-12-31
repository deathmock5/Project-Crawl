#include "GameSoundManager.h"
using namespace std;
GameSoundManager::GameSoundManager()
{
	bgscurentplaying = "";
}
void GameSoundManager::preLoadBGSFile(string file)
{
	bgs.push_back(load_sound(file));
	bgs_filenames.push_back(file);
}
void GameSoundManager::preLoadSFXFile(string file)
{
	sfx.push_back(load_sound(file));
	sfx_filenames.push_back(file);
}
void GameSoundManager::playSFX(string file)
{
	bool foundsample = false;
	for(int i = 0;i < (int)sfx.size();i++)
	{
		if(sfx_filenames[i] == file)
		{
			al_play_sample(sfx[i],0.5f,0,1,ALLEGRO_PLAYMODE_ONCE,&bgs_id);
			//logHelperMessage(INFO,1,"PLAYNG");
			foundsample = true;
			break;
		}
	}
	if(!foundsample)
	{
		sfx.push_back(load_sound(file));
		sfx_filenames.push_back(file);
		playSFX(file);
	}
}
void GameSoundManager::pauseMusic()
{

}
void GameSoundManager::playMusic()
{
	//unpause
}
void GameSoundManager::stopMusic()
{
	//killallmusic!
	al_stop_sample(&bgs_id);
}
void GameSoundManager::transitionBGMTo(string file)
{
	if(bgscurentplaying != file)
		{
		al_stop_samples();
		bool foundsample = false;
		for(int i = 0;i < (int)bgs.size();i++)
		{
			if(bgs_filenames[i] == file)
			{
				al_play_sample(bgs[i],0.5f,0,1,ALLEGRO_PLAYMODE_LOOP,&bgs_id);
				bgscurentplaying = file;
				foundsample = true;
				break;
			}
		}
		if(!foundsample)
		{
			bgs.push_back(load_sound(file));
			bgs_filenames.push_back(file);
			transitionBGMTo(file);
		}
	}
}
void GameSoundManager::sendMessage(string data)
{
	//TARGET,ACTION,FILE
	//SFX_PLAY_BLABLABLA
	string ident = data.substr(0,3);
	if(ident == "SFX")
	{
		ident = data.substr(4,4);
		if(ident == "LOAD")
		{
			ident = data.substr(9);
			preLoadSFXFile(ident);
		}
		else if(ident == "PLAY")
		{
			ident = data.substr(9);
			playSFX(ident);
		}
		else
		{
			logHelperMessage(WARNING,2,"Unknown identsfx:",ident.c_str());
		}
	}
	else if(ident == "BGM")
	{
		ident = data.substr(4,4);
		if(ident == "LOAD")
		{
			ident = data.substr(9);
			preLoadBGSFile(ident);
		}
		else if(ident == "PLAY")
		{
			ident = data.substr(9);
			transitionBGMTo(ident);
		}
		else
		{
			logHelperMessage(WARNING,2,"Unknown identbgm:",ident.c_str());
		}
	}
	else
	{
		logHelperMessage(WARNING,2,"Unknown ident:",ident.c_str());
	}
}
GameSoundManager::~GameSoundManager(void)
{

}
