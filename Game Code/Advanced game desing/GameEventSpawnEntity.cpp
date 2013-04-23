#include "GameEventSpawnEntity.h"


GameEventSpawnEntity::GameEventSpawnEntity(void): GameEvent()
{

}

GameEventSpawnEntity::~GameEventSpawnEntity(void)
{

}

void GameEventSpawnEntity::applyEvent(Dungion& dung,Menu& menu)
{
	dung.reftoCurrentMap()->spawnEnttityInMap(monstertospawn);
}
void GameEventSpawnEntity::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = va_arg(messages,int);
	monstertospawn = Entity(va_arg(messages,string));
	monsterpos = monstertospawn.getBounds();
	monsterpos.setX(va_arg(messages,int));
	monsterpos.setY(va_arg(messages,int));
	monstertospawn.setBounds(monsterpos);
	if(number > 3)
	{
		myidentactivator = va_arg(messages,string);
	}
}
