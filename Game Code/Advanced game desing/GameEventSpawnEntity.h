#pragma once
#include "gameevent.h"
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

