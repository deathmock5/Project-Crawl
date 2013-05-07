#pragma once
//=================================
// include guard
#ifndef _GameEventSpawnTorch_H_
#define _GameEventSpawnTorch_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"

//=================================
// the actual class

class GameEventSpawnTorch : public GameEvent
{
public:
	GameEventSpawnTorch(void);
	~GameEventSpawnTorch(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
