#include "pch.h"
#include "GameObject.h"


void GameObject::setType(int _t)
{
	type = _t;
}

int GameObject::getType()
{
	return type;
}

void GameObject::setName(std::string _n)
{
	name = _n;
}

std::string GameObject::getName()
{
	return name;
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}
