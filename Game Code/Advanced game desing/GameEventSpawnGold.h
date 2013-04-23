#pragma once
#include "GameEvent.h"
#include "Menu.h"
#include "Entity.h"
class Entity;
class GameEventSpawnGold :
	public GameEvent
{
public:
	GameEventSpawnGold(void);
	~GameEventSpawnGold(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	vector<Entity> coins;
};

