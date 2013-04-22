#include "GameEventSpawnGold.h"


GameEventSpawnGold::GameEventSpawnGold(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventSpawnGold::~GameEventSpawnGold(void)
{

}
void GameEventSpawnGold::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO:Spawn each entity in map.
}
void GameEventSpawnGold::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = va_arg(messages,int);
	Bounds positionofspawn;
	positionofspawn.setX(va_arg(messages,int));
	positionofspawn.setY(va_arg(messages,int));
	int amount = va_arg(messages,int);
	//TODO: loop and create a list of coins useing the change program
	if(number > 4)
	{
		myidentactivator = va_arg(messages,string);
	}
}