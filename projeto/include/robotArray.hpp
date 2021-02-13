#include <iostream>
#include <string>
#include "./robot.hpp"
#include "../include/map.hpp"

#ifndef ROBOTLIST_H
#define ROBOTLIST_H

class RobotArray {
private:
  Robot* robots[50];

public:
  RobotArray ();
  virtual ~RobotArray ();
  bool activate_robot(int);
  bool is_active_robot(int);
  void return_to_base(int);

  int return_resources_to_base(int);
  int return_aliens_to_base(int);
  void print_relatory(int);
  void execute_order(int, Map&);

  void add_normal_order(std::string, int);
  void add_order_with_priority(std::string, int);
};

#endif
