#pragma once
#include <vector>
#include "GameObject.h"
#include <filesystem>
class ResourceManager
{
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager * ptr;
	static std::vector <GameObject> assets;
	
public:
	static ResourceManager*getPtr();
	void readContent(std::string _path);
	void createGameObject(std::string _name, int _type);
	
};

const std::string ResourceDir = "Resources";
const std::string SpritesDir = "Resources/Sprites";
const std::string SoundsDir = "Resources/Sounds";