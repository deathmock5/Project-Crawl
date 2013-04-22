#pragma once
#include "GameEvent.h"
class GameEventWarpToMap :
	public GameEvent
{
public:
	GameEventWarpToMap(void);
	~GameEventWarpToMap(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
};

