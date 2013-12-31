#include "GameEventWarpToMap.h"


GameEventWarpToMap::GameEventWarpToMap(void): GameEvent()
{

}


GameEventWarpToMap::~GameEventWarpToMap(void)
{

}

void GameEventWarpToMap::applyEvent()
{
	//TODO: warp to map;
	getGameRefrence()->sendMessageToAllObjects(posibleidentiget,CLASSTYPE_EVENTMANAGER);
}
void GameEventWarpToMap::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);
}