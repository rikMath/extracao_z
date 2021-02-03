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
};

#endif
