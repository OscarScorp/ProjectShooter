#pragma once
#include <string>
class GameObject
{
protected:
	int type = 0;
	std::string name;
public:
	void setType(int _t);
	int getType();
	void setName(std::string _n);
	std::string getName();
	GameObject();
	~GameObject();
};

