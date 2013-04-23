#pragma once
#include "GameEvent.h"
#include "Menu.h"
#include "Entity.h"
class GameEventSpawnTorch : public GameEvent
{
public:
	GameEventSpawnTorch(void);
	~GameEventSpawnTorch(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	class Entity torchent;
};

