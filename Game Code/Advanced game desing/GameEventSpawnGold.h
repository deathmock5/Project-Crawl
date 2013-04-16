#pragma once
#include "gameevent.h"
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

