#pragma once
#include "gameevent.h"
class GameEventSpawnTorch :
	public GameEvent
{
public:
	GameEventSpawnTorch(void);
	~GameEventSpawnTorch(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	Entity torchent;
};

