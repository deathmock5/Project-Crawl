#pragma once
#include <string>
#include <vector>
#include "SystemVars.h"
#include "Dungion.h"
#include "Menu.h"
using namespace std;

class GameEvent
{
public:
	GameEvent(void);
	~GameEvent(void);
	virtual void applyEvent(Dungion&,Menu&);
	virtual void setEventPramiters(int,...);
protected:
	GAMEEVENTTYPE mytype;
	int timedactivator;
	string identactivator;
};

