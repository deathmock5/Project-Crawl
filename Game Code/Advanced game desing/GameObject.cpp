#include "GameObject.h"

GameObject::GameObject():MYTYPE(CLASSTYPE_NULL)
{
	//do not register
}

GameObject::GameObject(CLASSTYPE mtype)
{
	MYTYPE = mtype;
	//register this object into the gameobject list.
	//getGameRefrence()->registerGameObject(this);
}


GameObject::~GameObject(void)
{
	getGameRefrence()->unregisterGameObject(this);
}

void GameObject::sendMessage(string data)
{
	logHelperMessage(INFO,1,"Recived the message in GameObject");
}

CLASSTYPE GameObject::getMyClassType()
{
	return MYTYPE;
}

void GameObject::setMyClassType(CLASSTYPE newrecip)
{

}
void GameObject::setId(int val)
{
	myid = val;
}
int GameObject::getId()
{
	return myid;
}