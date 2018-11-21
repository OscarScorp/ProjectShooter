#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Key.h"

class Platform
{
private:
	int width, height;
	std::string name;
	void readInputs(std::ifstream & file);
	
protected:
	int windowGet;
	std::map<std::string, Key> keyMap;

public:
	int getWidth();
	void setWidth(int w);
	int getHeight();
	void setHeight(int h);
	std::string getName();
	void setName(std::string n);
	virtual void init();
	void readConfig();
	virtual int inputOne() = 0; //Abstracta pura.
	
	Platform();
	~Platform();
};