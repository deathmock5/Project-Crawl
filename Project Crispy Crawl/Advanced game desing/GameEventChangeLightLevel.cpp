#include "GameEventChangeLightLevel.h"


GameEventChangeLightLevel::GameEventChangeLightLevel(void): GameEvent()
{

}


GameEventChangeLightLevel::~GameEventChangeLightLevel(void)
{
	
}

void GameEventChangeLightLevel::applyEvent()
{
	//TODO: change light lv.
	getGameRefrence()->sendMessageToAllObjects(posibleidentiget,CLASSTYPE_EVENTMANAGER);
}

void GameEventChangeLightLevel::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage = "LIGHT_" + va_arg(messages,int);
	posibleidentiget = va_arg(messages,string);
}
