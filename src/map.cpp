#include <string>
#include<fstream>
#include <iostream>
#include "../include/map.hpp"

Map::Map(std::ifstream &myFile){
  elements = new Matrix(myFile);
}

Map::~Map() {
  // std::cout << "entrando destrutor map" << std::endl;
  delete elements;
  // std::cout << "saindo destrutor map" << std::endl;
}

std::string Map::obstacle = "O";

std::string Map::alien = "H";

std::string Map::resource = "R";

std::string Map::empty = ".";

bool Map::move_to(int x, int y) const {
  std::string current_pos_value = this->visit_position(x, y);

  if (current_pos_value != this->obstacle){
    return true;
  }
  return false;
}

bool Map::destroy_alien(int x, int y) {
  std::string current_pos_value = this->visit_position(x, y);

  if (current_pos_value == this->alien){
    elements->set(x+1, y+1, ".");
    return true;
  }
  return false;
}

bool Map::colect_resource(int x, int y) {
  std::string current_pos_value = this->visit_position(x, y);

  if (current_pos_value == this->resource){
    elements->set(x+1, y+1, ".");
    return true;
  }
  return false;
}

void Map::print() {
  elements->print();
}
