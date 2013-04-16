#pragma once
#include "gameevent.h"
class GameEventMovePlayer :
	public GameEvent
{
public:
	GameEventMovePlayer(void);
	~GameEventMovePlayer(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	Bounds newpos;
};

