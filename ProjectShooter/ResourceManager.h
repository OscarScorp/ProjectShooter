#pragma once
class ResourceManager
{
private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager * ptr;
public:
	static ResourceManager*getPtr();
};

