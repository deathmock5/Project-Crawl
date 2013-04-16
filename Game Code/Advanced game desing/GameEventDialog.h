#pragma once
#include "GameEvent.h"
class GameEventDialog : public GameEvent
{
public:
	GameEventDialog(void);
	~GameEventDialog(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	ALLEGRO_BITMAP* faceimg;
	string text;
};

