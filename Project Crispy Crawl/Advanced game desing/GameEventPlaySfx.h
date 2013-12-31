#pragma once
//=================================
// include guard
#ifndef _GameEventPlaySfx_H_
#define _GameEventPlaySfx_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"

//=================================
// the actual class
class GameEventPlaySfx : public GameEvent
{
public:
	GameEventPlaySfx(void);
	~GameEventPlaySfx(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
