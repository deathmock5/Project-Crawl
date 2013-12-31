#pragma once
//=================================
// include guard
#ifndef _GameEventSpawnEntity_H_
#define _GameEventSpawnEntity_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"

//=================================
// the actual class

class GameEventSpawnEntity : public GameEvent
{
public:
	GameEventSpawnEntity(void);
	~GameEventSpawnEntity(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
