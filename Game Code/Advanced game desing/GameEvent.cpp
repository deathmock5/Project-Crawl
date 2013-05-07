#include "GameEvent.h"


GameEvent::GameEvent()
{
	int timedactivator = -1;
	string identactivator = "null";
}

int GameEvent::getMyTimedActivator()
{
	return mytimedactivator;
}

GameEvent::~GameEvent(void)
{

}

void GameEvent::applyEvent()
{
	logHelperMessage(INFO,1,"Test");
}

void GameEvent::setEventPramiters(int,...)
{

}
