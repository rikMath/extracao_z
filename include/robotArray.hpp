#include <iostream>
#include "./robot.hpp"

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

  int return_resources_to_base(int);
  int return_aliens_to_base(int);
};

#endif
