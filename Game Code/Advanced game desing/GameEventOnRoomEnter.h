#pragma once
//=================================
// include guard
#ifndef _GameEventOnRoomEnter_H_
#define _GameEventOnRoomEnter_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"
//=================================
// the actual class

class GameEventOnRoomEnter : public GameEvent
{
public:
	GameEventOnRoomEnter(void);
	~GameEventOnRoomEnter(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
