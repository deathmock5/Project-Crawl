#pragma once
#include "GameEvent.h"
class Player;
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

