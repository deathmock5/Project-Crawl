#pragma once
#include "GameEvent.h"
#include "Entity.h"
class Entity;
class GameEventSpawnTorch : public GameEvent
{
public:
	GameEventSpawnTorch(void);
	~GameEventSpawnTorch(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	Entity torchent;
};

