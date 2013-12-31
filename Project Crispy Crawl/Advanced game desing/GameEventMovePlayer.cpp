#include "GameEventMovePlayer.h"


GameEventMovePlayer::GameEventMovePlayer(void): GameEvent()
{

}


GameEventMovePlayer::~GameEventMovePlayer(void)
{
}
void GameEventMovePlayer::applyEvent()
{
	//TODO: move the playeraa
	getGameRefrence()->sendMessageToAllObjects(posibleidentiget,CLASSTYPE_EVENTMANAGER);
}
void GameEventMovePlayer::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage = "MOVEP_-_" + va_arg(messages,string), ",";
	datamessage += va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);
}