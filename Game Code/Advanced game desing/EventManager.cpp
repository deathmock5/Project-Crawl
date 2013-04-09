#include "EventManager.h"


EventManager::EventManager(void)
{

}
EventManager::~EventManager(void)
{
}
bool EventManager::tickUpdate()
{
	return false;
	//TODO: return true if theres an event to process.
	//int curentmanagedevent = theevent
}
void EventManager::eventProcess(Dungion&,Menu&)
{
	//TODO: ok. i have a ref to the dung and to the menu, lets make things hapen.
	//what event is suposed to pop?

}
bool EventManager::isEventInProcess()
{
	//TODO: if curentmanagedevent == -1
	return false;
	
}
void EventManager::loadEvents(string file)
{
	//TODO: load the events from the file.
}
void EventManager::addDialogEvent(int time)
{
	//TODO: add a dialog event to the stack.
}
void EventManager::addDIilogEvent(string uniqeid)
{
	//TODO: add a dialog event by uniqueid
}
void EventManager::addEntitySpawnEvent(int time)
{

}
void EventManager::addEntitySpawnEvent(string uniqueid)
{}
void EventManager::addLightChangeEvent(int time)
{}
void EventManager::addLightChangeEvent(string uniqueid)
{}
void EventManager::addSpawnTorchEvent(int time)
{}
void EventManager::addSpawnTorchEvent(string uniqueid)
{}
void EventManager::addSpawnGoldEvent(int time)
{}
void EventManager::addSpawnGoldEvent(string uniqueid)
{}
void EventManager::addPlaySfxEvent(int time)
{}
void EventManager::addPlaySfxEvent(string uniqueid)
{}
void EventManager::addMovePlayerEvent(int time)
{}
void EventManager::addMovePlayerEvent(string uniqueid)
{}
void EventManager::addRoomEnterEvent(string roomid)
{}
void EventManager::addWarpToMapEvent(int time)
{}
void EventManager::addWarpToMapEvent(string uniqueid)
{}