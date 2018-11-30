#include "pch.h"
#include "Map.h"


bool Map::loadMap(std::string levelName)
{
	std::string currLine;
	std::ifstream myfile("Map1.txt");
	if (myfile.is_open()) {

		while (!myfile.eof())
		{
			getline(myfile, currLine); //line 1
			//for (int c = 0; c < currLine.length(); ++c) {
			GameObject model;
			std::size_t pos = currLine.find(",");
			/*
			type = stoi(currLine.substr(0, pos));
			model = currLine.substr(pos+1, pos+5);
			x = stoi(currLine.substr(pos + 8));
			y = stoi(currLine.substr(pos + 10));
			z = stoi(currLine.substr(currLine.length()-1));*/
			model.setType(stoi(currLine.substr(0, pos)));
			model.setName(currLine.substr(pos + 1, pos + 5));
			model.setX(stoi(currLine.substr(pos + 8)));
			model.setY(stoi(currLine.substr(pos + 10)));
			model.setZ(stoi(currLine.substr(currLine.length()-1)));
		}
	}
	return false;
}

Map::Map()
{
}


Map::~Map()
{
}
