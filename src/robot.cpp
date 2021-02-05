#include <string>
#include<fstream>
#include <iostream>
#include "../include/map.hpp"
#include "../include/queue.hpp"
#include "../include/robot.hpp"

Robot::Robot(int current_id, int x/*= 0*/, int y/*= 0*/):id(current_id){
  // std::cout << "Criando robo" << current_id << std::endl;
  pos_x = x;
  pos_y = y;
  resources = 0;
  aliens = 0;
  active = false;
  toExecuteOrders = new PriorityQueue<std::string>;
  executedOrders = new PriorityQueue<std::string>;
}

Robot::~Robot() {
  // std::cout << "entrando destrutor robot " << id << std::endl;
  delete toExecuteOrders;
  delete executedOrders;
  // std::cout << "saindo destrutor robot " << id <<std::endl;
}

bool Robot::activate() {
  bool was_active = this->active;
  this->active = true;
  return was_active;
}

bool Robot::move_to(const Map& map, int x, int y){
  if (map.move_to(x, y)){
    this->pos_x = x;
    this->pos_y = y;
    return true;
  }
  return false;
}

bool Robot::destroy_alien(Map& map, int x, int y){
  if (map.destroy_alien(x, y)){
    this->aliens++;
    return true;
  }
  return false;
}

bool Robot::collect_resource(Map& map, int x, int y){
  if (map.colect_resource(x, y)){
    this->resources++;
    return true;
  }
  return false;
}

int Robot::return_resources_to_base() {
  int r = this->resources;
  this->resources = 0;
  return r;
}

int Robot::return_aliens_to_base() {
  int r = this->aliens;
  this->aliens = 0;
  return r;
}
