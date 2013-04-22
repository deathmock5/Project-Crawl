#pragma once
#ifndef _EventManager_H_
#define  _EventManager_H_
#include "GameEvent.h"
//#include "GameEventChangeLightLevel.h"
#include "GameEventDialog.h"
//#include "GameEventMovePlayer.h"
//#include "GameEventOnRoomEnter.h"
//#include "GameEventPlaySfx.h"
//#include "GameEventSpawnEntity.h"
//#include "GameEventSpawnGold.h"
//#include "GameEventSpawnTorch.h"
//#include "GameEventWarpToMap.h"
#include "SystemVars.h"
//#include "Dungion.h"
//#include "Menu.h"
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
class EventManager
{
public:
	EventManager(void);
	~EventManager(void);
	bool tickUpdate();
	void eventProcess(Dungion&,Menu&);//Process an event
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
	string getLineValue(string data);
	vector<GameEvent>gamevents;
	vector<string> eventtimes;
	vector<GAMEEVENTTYPE> eventtypes;
	vector<string> eventprams;
	
};
#endif
