#include "GameEvent.h"


GameEvent::GameEvent()
{
    mytimedactivator = -1;
	myidentactivator = "null";
	posibleidentiget = "null";
}

int GameEvent::getMyTimedActivator()
{
	return mytimedactivator;
}
string GameEvent::getMyIdentActivator()
{
	return myidentactivator;
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
