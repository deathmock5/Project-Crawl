#include "GameEventMovePlayer.h"


GameEventMovePlayer::GameEventMovePlayer(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventMovePlayer::~GameEventMovePlayer(void)
{
}
void GameEventMovePlayer::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: move the player
}
void GameEventMovePlayer::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	timedactivator = va_arg(messages,int);
	newpos.setX(va_arg(messages,int));
	newpos.setY(va_arg(messages,int));
	if(number > 3)
	{
		identactivator = va_arg(messages,string);
	}
}