#include "../include/robotArray.hpp"
#include "../include/robot.hpp"

RobotArray::RobotArray() {
  for (int i=0; i<50; i++) {
    robots[i] = new Robot(i);
  }
}

RobotArray::~RobotArray() {

  // std::cout << "entrando destrutor robotArray" << std::endl;
  for (int i=0; i<50; i++) {
    delete robots[i];
  }
  // std::cout << "saindo destrutor robotArray" << std::endl;
}

int RobotArray::return_resources_to_base(int id) {
  return robots[id]->return_resources_to_base();
};

int RobotArray::return_aliens_to_base(int id) {
  return robots[id]->return_aliens_to_base();
};

void RobotArray::print_relatory(int id) {
  robots[id]->print_relatory();
};

bool RobotArray::activate_robot(int id) {
  return robots[id]->activate() ? true : false;
};

bool RobotArray::is_active_robot(int id) {
  return robots[id]->is_active();
}
