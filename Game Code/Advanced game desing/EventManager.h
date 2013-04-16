#pragma once
#ifndef _EventManager_H_
#define  _EventManager_H_
#include "Dungion.h"
#include "Menu.h"
#include "GameEvent.h"
#include "SystemVars.h"
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
	vector<GameEvent>gamevents;
	vector<string> eventtimes;
	vector<GAMEEVENTTYPE> eventtypes;
	vector<string> eventprams;
	
};
#endif
