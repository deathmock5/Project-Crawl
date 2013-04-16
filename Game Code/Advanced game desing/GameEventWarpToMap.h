#pragma once
#include "gameevent.h"
class GameEventWarpToMap :
	public GameEvent
{
public:
	GameEventWarpToMap(void);
	~GameEventWarpToMap(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
};

