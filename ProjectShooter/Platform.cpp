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


void Platform::readConfig()
{
	std::string currLine;
	std::ifstream myfile("run.txt");
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
			getline(myfile, currLine); 
				Key key;
				key.asciiValue = currLine[currLine.length() - 1]; //P1UP=w
				keyMap[currLine.substr(currLine.length()-2)] = key; //si el mapa no tiene el string que queremos meter, se mete.
			getline(myfile, currLine);
				key.asciiValue = currLine[currLine.length() - 1]; //P1DOWN=s
				keyMap[currLine.substr(currLine.length() - 2)] = key;
			getline(myfile, currLine);
				key.asciiValue = currLine[currLine.length() - 1]; //P1LEFT=a
				keyMap[currLine.substr(currLine.length() - 2)] = key;
			getline(myfile, currLine);
				key.asciiValue = currLine[currLine.length() - 1]; //P1RIGHT=d
				keyMap[currLine.substr(currLine.length() - 2)] = key;
		}
		catch (...) {
			width = 600;
			height = 400;
			name = "POOII Window Default Name";
			windowGet = 0; //Windowed mode.
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

