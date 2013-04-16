#pragma once
#include "gameevent.h"
class GameEventChangeLightLevel :
	public GameEvent
{
public:
	GameEventChangeLightLevel(void);
	~GameEventChangeLightLevel(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	int amount;
};

