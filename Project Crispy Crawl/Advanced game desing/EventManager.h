#pragma once
//=================================
// include guard
#ifndef _EventManager_H_
#define _EventManager_H_

//=================================
// forward declared dependencies
class GameEvent;

//=================================
// included dependencies
#include <locale>
#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include "SystemVars.h"
#include "GameEvent.h"
#include "GameScriptFileDataset.h"
#include "GameEventChangeLightLevel.h"
#include "GameEventDialog.h"
#include "GameEventMovePlayer.h"
#include "GameEventOnRoomEnter.h"
#include "GameEventPlaySfx.h"
#include "GameEventSpawnEntity.h"
#include "GameEventSpawnGold.h"
#include "GameEventSpawnTorch.h"
#include "GameEventWarpToMap.h"
#include "GameObject.h"

using namespace std;

//=================================
// the actual class

class EventManager : public GameObject
{
public:
	EventManager(void);
	virtual void sendMessage(string data);
	~EventManager(void);
	bool tickUpdate();
	void eventProcess();//Process an event
	bool isEventInProcess();//is an event already running and awanting to pass control back to user?
	void loadEvents(string file);
private:
	int curenttimer;
	vector<int> popedevents;
	LINETYPE getLineType(string);
	bool is_number(const std::string& s);
	vector<GameEvent*>gamevents;
};
#endif
