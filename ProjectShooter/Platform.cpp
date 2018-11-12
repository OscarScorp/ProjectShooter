#include "pch.h"
#include "Platform.h"

int Platform::getWidth()
{
	return width;
}

void Platform::setWidth(int w)
{
	width = w;
	return;
}

int Platform::getHeight()
{
	return height;
}

void Platform::setHeight(int h)
{
	height = h;
	return;
}

std::string Platform::getName()
{
	return name;
}

void Platform::setName(std::string n)
{
	name = n;
}
