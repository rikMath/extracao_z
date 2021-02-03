#include <fstream>
#include "./map.hpp"

#ifndef BASE_H
#define BASE_H

class Base {
private:
  int resources, aliens;
  Map* map;

public:
  Base (std::ifstream &myFile);
  virtual ~Base ();

  inline void print_map() const {map->print();};
};

#endif
