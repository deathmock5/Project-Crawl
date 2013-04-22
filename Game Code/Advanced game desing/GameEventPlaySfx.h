#pragma once
#include "GameEvent.h"
class GameEventPlaySfx :
	public GameEvent
{
public:
	GameEventPlaySfx(void);
	~GameEventPlaySfx(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	ALLEGRO_SAMPLE* sfx;
};

