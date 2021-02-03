#include <fstream>
#include "./map.hpp"
#include "./queue.hpp"

#ifndef BASE_H
#define BASE_H

class Base {
private:
  int resources, aliens;
  Map* map;
  // RobotArray
  // Orders -> algoritmo rodar até encontrar uma ordem de execução, então RETORNAR
  // essa ordem e ela ser cuidada na classe. Chamar uma função que descobre a ordem e vai saber
  // se deve chamar um robo o mapa ou realizar uma impressão
public:
  Base (std::ifstream &myFile);
  virtual ~Base ();

  inline void print_map() const {map->print();};
};

#endif
