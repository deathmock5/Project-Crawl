#pragma once
#include "GameEvent.h"
#include "Dungion.h"
#include "Menu.h"
class GameEventPlaySfx :
	public GameEvent
{
public:
	GameEventPlaySfx(void);
	~GameEventPlaySfx(void);
	void applyEvent(class Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	ALLEGRO_SAMPLE* sfx;
};

