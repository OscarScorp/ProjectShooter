#include "pch.h"
#include "Platform.h"

void Platform::readInputs(std::ifstream & file)
{
	std::string currLine;
	Key key;
	getline(file, currLine);
	key.asciiValue = currLine[currLine.length() - 1];
	keyMap[currLine.substr(0, currLine.length() - 2)] = key;
}

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

void Platform::readConfig()
{
	std::string currLine;
	std::ifstream myfile("config.txt");
	if (myfile.is_open())
	{
		try {
			getline(myfile, currLine);
				width = stoi(currLine);
			getline(myfile, currLine);
				height = stoi(currLine);
			getline(myfile, currLine);
				name = currLine;
			getline(myfile, currLine);
				windowGet = stoi(currLine);
			for(int i = 0; i < 10; ++i)
				readInputs(myfile);
		}
		catch (...) {
			width = 600;
			height = 400;
			name = "POOII Window Default Name";
			windowGet = 0; //Windowed mode.
			/*P1UP = w
			P1DOWN = s
			P1LEFT = a
			P1RIGHT = d
			P1SHOOT = spacebar
			P2UP = i
			P2DOWN = k
			P2LEFT = j
			P2RIGHT = l
			P2SHOOT = o*/
		}
		myfile.close();
	}
	else std::cout << "Unable to open file";
}

Platform::Platform()
{
	
}

Platform::~Platform()
{
}

