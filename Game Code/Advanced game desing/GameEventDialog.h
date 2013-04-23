#pragma once
//#ifndef _GAMEEVENTDIALOG_H_
//#define _GAMEEVENTDIALOG_H_
#include "GameEvent.h"
#include "Dungion.h"
#include "Menu.h"
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
//#endif