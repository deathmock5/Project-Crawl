#include "GameEventSpawnGold.h"


GameEventSpawnGold::GameEventSpawnGold(void): GameEvent()
{

}


GameEventSpawnGold::~GameEventSpawnGold(void)
{

}
void GameEventSpawnGold::applyEvent()
{
	//TODO:Spawn each entity in map.
}
void GameEventSpawnGold::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage = "SGOLD_" + va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);
}