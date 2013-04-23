#include "GameEventMovePlayer.h"


GameEventMovePlayer::GameEventMovePlayer(void): GameEvent()
{

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

	mytimedactivator = va_arg(messages,int);
	newpos.setX(va_arg(messages,int));
	newpos.setY(va_arg(messages,int));
	if(number > 3)
	{
		myidentactivator = va_arg(messages,string);
	}
}