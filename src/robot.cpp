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
  std::cout << r << std::endl;
  this->resources = 0;
  return r;
}

int Robot::return_aliens_to_base() {
  int r = this->aliens;
  this->aliens = 0;
  return r;
}

void Robot::print_relatory() {
  executedOrders->print();
  executedOrders->clear();
}

void Robot::execute_order(Map& map) {
  std::string current_order;
  while (true) {
    current_order = toExecuteOrders->delete_element();

    if (current_order == ""){
      break;
    }

    this->process_order(current_order, map);

  }
}

void Robot::process_order(std::string order, Map& map){

  if (order.find("MOVER") != std::string::npos) {
    this->move_order(order, map);
  }
  else if (order.find("COLETAR") != std::string::npos) {
    this->collect_order(map);
  }
  else if (order.find("ELIMINAR") != std::string::npos) {
    this->destroy_order(map);
  }
}

void Robot::add_normal_order(std::string order) {
  toExecuteOrders->insert(order);
}

void Robot::add_order_with_priority(std::string order) {
  toExecuteOrders->insert_with_priority(order);
}

void Robot::move_order(std::string order, Map& map) {
  int x =std::stoi(order.substr(order.find("(")+1,order.find(",")));
  int y =std::stoi(order.substr(order.find(",")+1,order.find(")")));
  std::string runned_order;
  if (this->move_to(map, x, y)) {
    runned_order = "ROBO "+std::to_string(id)+": MOVEU PARA ("+std::to_string(x)+","+std::to_string(y)+")";

  }
  else {
    runned_order = "ROBO "+std::to_string(id)+": IMPOSSIVEL MOVER PARA ("+std::to_string(x)+","+std::to_string(y)+")";

  }
  executedOrders->insert(runned_order);
}

void Robot::collect_order(Map& map) {
  std::string runned_order;
  if(this->collect_resource(map, this->pos_x, this->pos_y)) {
    runned_order = "ROBO "+std::to_string(id)+": RECURSOS COLETADOS EM ("+std::to_string(this->pos_x)+","+std::to_string(this->pos_y)+")";
  }
  else {
    runned_order = "ROBO "+std::to_string(id)+": IMPOSSIVEL COLETAR RECURSOS EM ("+std::to_string(this->pos_x)+","+std::to_string(this->pos_y)+")";
  }
  executedOrders->insert(runned_order);
}

void Robot::destroy_order(Map& map) {
  std::string runned_order;
  if(this->destroy_alien(map, this->pos_x, this->pos_y)) {
    runned_order = "ROBO "+std::to_string(id)+": ALIEN ELIMINADO EM ("+std::to_string(this->pos_x)+","+std::to_string(this->pos_y)+")";
  }
  else {
    runned_order = "ROBO "+std::to_string(id)+": IMPOSSIVEL ELIMINAR ALIEN EM ("+std::to_string(this->pos_x)+","+std::to_string(this->pos_y)+")";
  }
  executedOrders->insert(runned_order);
}
