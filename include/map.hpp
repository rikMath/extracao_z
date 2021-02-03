#include <fstream>
#include <string>
#include "./matrix.hpp"

#ifndef MAP_H
#define MAP_H

class Map {
private:
  static std::string obstacle;
  static std::string alien;
  static std::string resource;
  static std::string empty;

  Matrix* elements;

  inline std::string visit_position(int x, int y) const {return (*elements)[x-1][y-1];};

public:


  // Construtor
  Map (std::ifstream &myFile);

  // Destrutor
  ~Map();

  // Operações no mapa
  bool move_to(int x, int y) const;
  bool destroy_alien(int x, int y);
  bool colect_resource(int x, int y);

  // Variados
  void print();
};

#endif
