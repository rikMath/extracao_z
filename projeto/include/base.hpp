#include <fstream>
#include "./map.hpp"
#include "./queue.hpp"
#include "./robotArray.hpp"

#ifndef BASE_H
#define BASE_H

class Base {
private:
  int resources, aliens;
  Map* map;
  RobotArray* robots;

public:
  Base (std::ifstream &mapFile);
  virtual ~Base ();

  inline void print_map() const {map->print();}

  inline void print_resources() const {std::cout<<"BASE: TOTAL DE ALIENS "<<aliens<<" RECURSOS "<<resources<<std::endl;}

  void activate_robot(int);
  void return_robot(int);
  void print_relatory(int);
  void execute_order(int);

  void add_normal_order(std::string, int);
  void add_order_with_priority(std::string, int);
};

#endif
