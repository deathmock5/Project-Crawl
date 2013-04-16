#include "GameEventWarpToMap.h"


GameEventWarpToMap::GameEventWarpToMap(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventWarpToMap::~GameEventWarpToMap(void)
{
}

void GameEventWarpToMap::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: warp to map;
}
void GameEventWarpToMap::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	timedactivator = va_arg(messages,int);
	if(number > 1)
	{
		identactivator = va_arg(messages,string);
	}
}