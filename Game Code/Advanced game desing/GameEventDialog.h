#pragma once
#ifndef _GAMEEVENTDIALOG_H_
#define _GAMEEVENTDIALOG_H_
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"
//=================================
// the actual class


class GameEventDialog : public GameEvent
{
public:
	GameEventDialog(void);
	~GameEventDialog(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif