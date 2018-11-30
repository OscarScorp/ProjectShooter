#pragma once
#include <string>
#include <fstream>
#include <string>
#include "GameObject.h"
class Map
{
public:
	bool loadMap(std::string levelName);
	Map();
	~Map();
};

