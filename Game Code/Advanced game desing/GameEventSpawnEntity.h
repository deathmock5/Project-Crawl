#pragma once
#include "GameEvent.h"
#include "Menu.h"
#include "Entity.h"
class GameEventSpawnEntity :
	public GameEvent
{
public:
	GameEventSpawnEntity(void);
	~GameEventSpawnEntity(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	class Entity monstertospawn;
	Bounds monsterpos;
};

