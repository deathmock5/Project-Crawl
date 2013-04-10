#pragma once
#ifndef _EventManager_H_
#define  _EventManager_H_
#include "Dungion.h"
#include "Menu.h"
const enum EVENTTYPES{EVENT_DIALOG,EVENT_ENTITYSPAWN,EVENT_LIGHTCHANGE,EVENT_SPAWNTORCH,EVENT_SPAWNGOLD,EVENT_PLAYSFX,EVENT_MOVEPLAYER,EVENT_ROOMENTER,EVENT_WARP};
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
	vector<string> eventtimes;
	vector<EVENTTYPES> eventtypes;
	vector<string> eventprams;
	
};
#endif
