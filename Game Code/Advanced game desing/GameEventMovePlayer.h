#pragma once
#ifndef _GameEventMovePlayer_H_
#define _GameEventMovePlayer_H_
class Player; //in dung file, so all good
#include "GameEvent.h"
#include "Bounds.h"

class GameEventMovePlayer : public GameEvent
{
public:
	GameEventMovePlayer(void);
	~GameEventMovePlayer(void);
	void applyEvent(Dungion&,Menu&);
	void setEventPramiters(int,...);
private:
	Bounds newpos;
};
#endif