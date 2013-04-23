#include "GameEventOnRoomEnter.h"


GameEventOnRoomEnter::GameEventOnRoomEnter(void): GameEvent()
{

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

	myidentactivator = va_arg(messages,string);
}