#include "pch.h"
#include "ResourceManager.h"
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