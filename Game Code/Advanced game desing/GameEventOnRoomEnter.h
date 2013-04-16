#pragma once
#include "gameevent.h"
class GameEventOnRoomEnter :
	public GameEvent
{
public:
	GameEventOnRoomEnter(void);
	~GameEventOnRoomEnter(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
};

