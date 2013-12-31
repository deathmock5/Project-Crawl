#include "GameEventOnRoomEnter.h"


GameEventOnRoomEnter::GameEventOnRoomEnter(void): GameEvent()
{

}


GameEventOnRoomEnter::~GameEventOnRoomEnter(void)
{

}

void GameEventOnRoomEnter::applyEvent()
{
	//TODO: throw an event.
	getGameRefrence()->sendMessageToAllObjects(posibleidentiget,CLASSTYPE_EVENTMANAGER);
}

void GameEventOnRoomEnter::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);

	posibleidentiget = va_arg(messages,string);
}