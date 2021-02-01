#include <fstream>
#include <string>
#include "./matrix.hpp"

#ifndef MAP_H
#define MAP_H

class Map {
private:
  static std::string obstacle;
  static std::string alien;
  static std::string resources;
  static std::string empty;


  Matrix* elements;

public:
  Map (std::ifstream &myFile);
  ~Map();

  void print();
};

#endif
