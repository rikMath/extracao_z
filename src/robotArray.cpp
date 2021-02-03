#include "../include/robotArray.hpp"
#include "../include/robot.hpp"

RobotArray::RobotArray() {
  for (int i=0; i<50; i++) {
    robots[i] = new Robot(i);
  }
}

RobotArray::~RobotArray() {
  for (int i=0; i<50; i++) {
    delete robots[i];
  }
}

bool RobotArray::activate_robot(int id) {
  return robots[id]->activate() ? true : false;
};
