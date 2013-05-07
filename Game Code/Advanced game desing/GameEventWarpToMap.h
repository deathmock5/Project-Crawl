#pragma once
//=================================
// include guard
#ifndef _GameEventWarpToMap_H_
#define _GameEventWarpToMap_H_


//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"
//=================================
// the actual class

class GameEventWarpToMap : public GameEvent
{
public:
	GameEventWarpToMap(void);
	~GameEventWarpToMap(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
