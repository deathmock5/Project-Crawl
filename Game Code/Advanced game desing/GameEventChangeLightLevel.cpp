#include "GameEventChangeLightLevel.h"


GameEventChangeLightLevel::GameEventChangeLightLevel(void): GameEvent()
{
	int timedactivator = -1;
	string identactivator = "null";
}


GameEventChangeLightLevel::~GameEventChangeLightLevel(void)
{
	
}

void GameEventChangeLightLevel::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: change light lv.
}
void GameEventChangeLightLevel::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = va_arg(messages,int);
	amount = va_arg(messages,int);
	if(number > 1)
	{
		myidentactivator = va_arg(messages,string);
	}
}
