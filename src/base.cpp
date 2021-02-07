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
  // std::cout << "entrando destrutor base" << std::endl;
  delete map;
  delete robots;
  // std::cout << "saindo destrutor base" << std::endl;
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
    int alien_robot = robots->return_aliens_to_base(id);
    robots->return_to_base(id);
    std::cout << "BASE: ROBO " << id << " RETORNOU ALIENS " << alien_robot <<
      " RECURSOS " << resources_robot << std::endl;
    this->resources += resources_robot;
    this->aliens += alien_robot;
    return;
  }
  std::cout << "BASE: ROBO " << id << " NAO ESTA EM MISSAO" << std::endl;
}

void Base::print_relatory(int id) {
  robots->print_relatory(id);
}

void Base::execute_order(int id) {
  robots->execute_order(id, *map);
}

void Base::add_normal_order(std::string order, int id) {
  robots->add_normal_order(order, id);
}

void Base::add_order_with_priority(std::string order, int id) {
  robots->add_order_with_priority(order, id);
}
