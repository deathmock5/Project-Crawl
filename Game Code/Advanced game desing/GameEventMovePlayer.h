#pragma once
//=================================
// include guard
#ifndef _GameEventMovePlayer_H_
#define _GameEventMovePlayer_H_
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"
//=================================
// the actual class

class GameEventMovePlayer : public GameEvent
{
public:
	GameEventMovePlayer(void);
	~GameEventMovePlayer(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif