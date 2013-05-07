#pragma once
//=================================
// include guard
#ifndef _GameEventChangeLightLevel_H_
#define _GameEventChangeLightLevel_H_
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "GameEvent.h"
//=================================
// the actual class
class GameEventChangeLightLevel : public GameEvent
{
public:
	GameEventChangeLightLevel(void);
	~GameEventChangeLightLevel(void);
	void applyEvent();
	void setEventPramiters(int,...);
};
#endif
