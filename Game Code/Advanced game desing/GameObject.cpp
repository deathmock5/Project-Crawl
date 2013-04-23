#include "GameObject.h"

GameObject::GameObject() : _MYCURRENTCLASSTYPE(CLASSTYPE_NULL)
{
	//do not register
}

GameObject::GameObject(CLASSTYPE mytype): _MYCURRENTCLASSTYPE(mytype)
{
	//register this object into the gameobject list.
	registerGameobject(*this);
}


GameObject::~GameObject(void)
{

}

void GameObject::sendMessage(string data,CLASSTYPE recip)
{

}

CLASSTYPE GameObject::getMyClassType()
{
	return _MYCURRENTCLASSTYPE;
}

void GameObject::setMyClassType(CLASSTYPE newrecip)
{

}