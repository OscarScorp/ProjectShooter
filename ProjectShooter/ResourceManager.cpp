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
	std::cout << "Reading content..." << std::endl;
	//folderReader(ResourceDir);
	folderReader(SpritesDir);
	folderReader(SoundsDir);
	folderReader(ModelsDir);
}

void ResourceManager::folderReader(std::string _path)
{
	std::cout << "Reading folder..." << std::endl;

	for (auto &p : std::experimental::filesystem::directory_iterator(_path))
	{
		//if (fileType == nullptr)

		std::string fileName = p.path().filename().generic_string();
		if (p.path().filename().extension() == ".bmp")
			assetPusher(fileName, ".bmp", 0);
		if (p.path().filename().extension() == ".wav")
			assetPusher(fileName, ".wav", 1);
		if (p.path().filename().extension() == ".obj")
			assetPusher(fileName, ".obj", 2);
	}
}

void ResourceManager::assetPusher(std::string _file, std::string _ext, int _type)
{
	GameObject fileObject;
	fileObject.setType(_type);
	fileObject.setName(_file);
	assets.push_back(fileObject);
	std::cout << "Debug: " << _type << " file found." << std::endl;
}
