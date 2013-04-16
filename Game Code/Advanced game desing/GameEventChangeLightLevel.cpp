#include "GameEventChangeLightLevel.h"


GameEventChangeLightLevel::GameEventChangeLightLevel(void)
{

}


GameEventChangeLightLevel::~GameEventChangeLightLevel(void)
{
	int timedactivator = -1;
	string identactivator = "null";
}

void GameEventChangeLightLevel::applyEvent(Dungion& dung,Menu& menu)
{
	//TODO: change light lv.
}
void GameEventChangeLightLevel::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	timedactivator = va_arg(messages,int);
	amount = va_arg(messages,int);
	if(number > 1)
	{
		identactivator = va_arg(messages,string);
	}
}
