#include <fstream>
#include "../include/base.hpp"
#include "../include/map.hpp"
#include "../include/order.hpp"
#include "../include/queue.hpp"

Base::Base(std::ifstream &mapFile) {
  resources = 0;
  aliens = 0;
  map = new Map(mapFile);
  robots = new RobotArray;
}

Base::~Base() {
  delete map;
  delete robots;
}

void Base::activate_robot(int id) {
  if(robots->activate_robot(id)) {
    std::cout << "BASE: ROBO " << id << " JA ESTA EM MISSAO" << std::endl;
    return;
  }
  std::cout << "BASE: ROBO "<< id <<" SAIU EM MISSAO" << std::endl;
}

void Base::return_robot(int id) {
  if(robots->is_active_robot(id)) {
    int resources_robot = robots->return_resources_to_base(id);
    int alien_robot = robots->return_resources_to_base(id);
    std::cout << "BASE: ROBO " << id << " RETORNOU ALIENS " << resources_robot <<
      " RECURSOS " << alien_robot << std::endl;
    return;
  }
  std::cout << "BASE: ROBO " << id << " NAO ESTA EM MISSAO" << std::endl;
}
