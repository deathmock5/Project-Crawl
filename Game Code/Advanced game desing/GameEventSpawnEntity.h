#pragma once
#include "GameEvent.h"
#include "Entity.h"
class Entity;
class GameEventSpawnEntity :
	public GameEvent
{
public:
	GameEventSpawnEntity(void);
	~GameEventSpawnEntity(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	Entity monstertospawn;
	Bounds monsterpos;
};

