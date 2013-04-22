#pragma once

#include <string>
#include <vector>
//#ifndef _GAMEEVENT_H_
//#define _GAMEEVENT_H_
#include "SystemVars.h"
#include "Dungion.h"
#include "Menu.h"
using namespace std;
class Dungion;
class Menu;
class GameEvent
{
public:
	GameEvent(void);
	~GameEvent(void);
	virtual void applyEvent(Dungion&,Menu&);
	virtual void setEventPramiters(int,...);
protected:
	GAMEEVENTTYPE mytype;
	int mytimedactivator;
	string myidentactivator;
	string posibleidentiget;
};
//#endif
