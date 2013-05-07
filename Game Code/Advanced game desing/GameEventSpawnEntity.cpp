#include "GameEventSpawnEntity.h"


GameEventSpawnEntity::GameEventSpawnEntity(void): GameEvent()
{

}

GameEventSpawnEntity::~GameEventSpawnEntity(void)
{

}

void GameEventSpawnEntity::applyEvent()
{
	//dung.reftoCurrentMap()->spawnEnttityInMap(monstertospawn);
}
void GameEventSpawnEntity::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);
	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage += "ENTTY_-_SPAWN_";
	datamessage += va_arg(messages,string) + ',';
	datamessage += va_arg(messages,string) + ',';
	datamessage += va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);

}
