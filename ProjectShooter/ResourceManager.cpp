#include "pch.h"
#include "ResourceManager.h"
#include <iostream>
ResourceManager * ResourceManager::ptr;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager * ResourceManager::getPtr()
{
	if (ptr == nullptr)
		ptr = new ResourceManager();
	return ptr;
}

void ResourceManager::createGameObject(std::string _name, int _type)
{
}

void ResourceManager::readContent(std::string _path)
{
	for (auto &p : std::experimental::filesystem::directory_iterator(_path))
	{
		std::cout << p.path().filename() << std::endl;

		for (auto &p : std::experimental::filesystem::directory_iterator(SpritesDir))
		{
			std::cout << p.path().filename() << std::endl;
		}
		for (auto &p : std::experimental::filesystem::directory_iterator(SoundsDir))
		{
			std::cout << p.path().filename() << std::endl;
		}

	}
}
