#include <string>
#include<fstream>
#include <iostream>
#include "../include/map.hpp"

Map::Map(std::ifstream &myFile){
  elements = new Matrix(myFile);
}

Map::~Map() {
  delete elements;
}

std::string Map::obstacle = "O";

std::string Map::alien = "H";

std::string Map::resources = "R";

std::string Map::empty = ".";

void Map::print() {
  elements->print();
}
