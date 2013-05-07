#include "GameEventPlaySfx.h"


GameEventPlaySfx::GameEventPlaySfx(void): GameEvent()
{

}


GameEventPlaySfx::~GameEventPlaySfx(void)
{

}
void GameEventPlaySfx::applyEvent()
{
	//TODO: playsfx
}
void GameEventPlaySfx::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);

	posibleidentiget = va_arg(messages,string);
}