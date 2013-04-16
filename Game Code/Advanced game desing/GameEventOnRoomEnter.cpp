#include "GameEventOnRoomEnter.h"


GameEventOnRoomEnter::GameEventOnRoomEnter(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventOnRoomEnter::~GameEventOnRoomEnter(void)
{
}
void GameEventOnRoomEnter::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: throw an event.
}
void GameEventOnRoomEnter::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	identactivator = va_arg(messages,string);
}