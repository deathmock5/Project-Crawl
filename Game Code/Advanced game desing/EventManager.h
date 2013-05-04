#pragma once
//=================================
// include guard
#ifndef _EventManager_H_
#define _EventManager_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies

#include <vector>
#include "GameEvent.h"
#include "SystemVars.h"
#include <locale>
#include <iostream>
#include <fstream>
#include <istream>
#include "GameScriptFileDataset.h"
using namespace std;
//#include "Dungion.h" - forward included
//#include "Menu.h" - forward included

//=================================
// the actual class

class EventManager
{
public:
	EventManager(void);
	~EventManager(void);
	bool tickUpdate();
	void eventProcess();//Process an event
	bool isEventInProcess();//is an event already running and awanting to pass control back to user?
	void loadEvents(string file);
private:
	void addDialogEvent(int time);
	void addDIilogEvent(string uniqeid);
	void addEntitySpawnEvent(int time);//time
	void addEntitySpawnEvent(string uniqueid);//event quekey
	void addLightChangeEvent(int time);
	void addLightChangeEvent(string uniqueid);
	void addSpawnTorchEvent(int time);
	void addSpawnTorchEvent(string uniqueid);
	void addSpawnGoldEvent(int time);
	void addSpawnGoldEvent(string uniqueid);
	void addPlaySfxEvent(int time);
	void addPlaySfxEvent(string uniqueid);
	void addMovePlayerEvent(int time);
	void addMovePlayerEvent(string uniqueid);
	void addRoomEnterEvent(string roomid);
	void addWarpToMapEvent(int time);
	void addWarpToMapEvent(string uniqueid);
	LINETYPE getLineType(string);
	bool is_number(const std::string& s);
	vector<GameEvent>gamevents;
	vector<string> eventtimes;
	vector<GAMEEVENTTYPE> eventtypes;
	vector<string> eventprams;
};
#endif
