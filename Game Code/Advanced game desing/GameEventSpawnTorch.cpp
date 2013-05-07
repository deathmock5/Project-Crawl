#include "GameEventSpawnTorch.h"


GameEventSpawnTorch::GameEventSpawnTorch(void): GameEvent()
{

}


GameEventSpawnTorch::~GameEventSpawnTorch(void)
{
}

void GameEventSpawnTorch::applyEvent()
{
	//dung.reftoCurrentMap()->spawnEnttityInMap(torchent);
}
void GameEventSpawnTorch::setEventPramiters(int number,...)
{
	va_list messages;
	va_start(messages,number);

	mytimedactivator = atoi(va_arg(messages,string).c_str());
	myidentactivator = va_arg(messages,string);
	datamessage = "TORCH_" + va_arg(messages,string) + ",";
	datamessage += va_arg(messages,string);
	posibleidentiget = va_arg(messages,string);
}

