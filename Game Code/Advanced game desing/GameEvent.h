#pragma once
//guards
#ifndef _GAMEEVENT_H_
#define _GAMEEVENT_H_
//forwards
class Dungion;
class Menu;
//dependencys
#include <string>
#include <vector>
#include "SystemVars.h"
using namespace std;

class GameEvent
{
public:
	GameEvent();
	~GameEvent(void);
	virtual void applyEvent(Dungion&,Menu&);
	virtual void setEventPramiters(int,...);
protected:
	GAMEEVENTTYPE mytype;
	int mytimedactivator;
	string myidentactivator;
	string posibleidentiget;
};
#endif
