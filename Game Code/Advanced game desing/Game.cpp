#include "Game.h"
#include "Player.h"
#include "Dungion.h"

Game::Game(void)
{
	//setGameRefrence(this);
	numberofobjects = 0;
	numberofcreatedobjects = 0;
	//logHelperMessage(INFO,1,"Registerd game");
}

void Game::registerGameObject(GameObject * s)
{
	//logHelperMessage(INFO,1,"ADDED an object");
	s->setId(numberofcreatedobjects);
	gameobjects.push_back(s);
	numberofobjects++;
	numberofcreatedobjects++;
	//logHelperMessage(INFO,1,"ADDEDANOBJECT");
}

void Game::unregisterGameObject(GameObject * s)
{
	//logHelperMessage(INFO,1,"Removed an object");
	for(int i = 0;i < numberofobjects;i++)
	{
		if(s->getId() == i)
		{
			//logHelperMessage(INFO,1,"REMOVEDANOBJECT");
			gameobjects.erase(gameobjects.begin() + i);
			numberofobjects--;
		}
	}
}

void Game::sendMessageToAllObjects(string message)
{
	if(gameobjects.size() == 0)
	{
		logHelperMessage(INFO,1,"But que is empty.");
	}
	vector<GameObject*>::iterator p;
      for(p = gameobjects.begin(); p != gameobjects.end(); p++)
	  {
		  //logHelperMessage(INFO,1,"Sent from game");
         //static_cast<Player*>(*p)->sendMessage(message);
		  (*p)->sendMessage(message);
	  }
}

void Game::sendMessageToAllObjects(string message,CLASSTYPE recip)
{
	if(gameobjects.size() == 0)
	{
		logHelperMessage(INFO,1,"But que is empty.");
	}
	vector<GameObject*>::iterator p;
      for(p = gameobjects.begin(); p != gameobjects.end(); p++)
	  {
		  if((*p)->getMyClassType() == recip)
		  {
			  switch (recip)
			  {
			  case CLASSTYPE_NULL:
				  //logHelperMessage(INFO,1,"SENT TO NULL");
				  break;
			  case CLASSTYPE_PLAYER:
				  //logHelperMessage(INFO,1,"SENT TO PLAYER");
				  static_cast<Player*>(*p)->sendMessage(message);
				  break;
			  case CLASSTYPE_DUNGION:
				  //logHelperMessage(INFO,1,"SENT TO DUNG");
				  static_cast<Dungion*>(*p)->sendMessage(message);
				  break;
			  case CLASSTYPE_ENTITY:
				  //logHelperMessage(INFO,1,"SENT TO ENTITY");
				  break;
			  case CLASSTYPE_MAP:
				  //logHelperMessage(INFO,1,"SENT TO MAP");
				  break;
			  case CLASSTYPE_MENU:
				  //logHelperMessage(INFO,1,"SENT TO MENU");
				  break;
			  default:
				  //logHelperMessage(INFO,1,"SENT TO NO IDEA");
				  break;
			  }
			 //static_cast<Player*>(*p)->sendMessage(message);
			  //(*p)->sendMessage(message);
		  }
	  }
}

Game::~Game(void)
{

}
