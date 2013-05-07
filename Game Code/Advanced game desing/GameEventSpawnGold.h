#pragma once
//=================================
// include guard
#ifndef _GameEventSpawnGold_H_
#define _GameEventSpawnGold_H_


//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"

//=================================
// the actual class

class GameEventSpawnGold : public GameEvent
{
public:
	GameEventSpawnGold(void);
	~GameEventSpawnGold(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
