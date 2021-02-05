#include <fstream>
#include <string>
#include <iostream>
#include "../include/order.hpp"
#include "../include/queue.hpp"

Orders::Orders(std::ifstream &file, Base &base) {

  orderQueue = new PriorityQueue<std::string>;

  std::string t;
  while(getline(file, t)){
    this->receive_order(t, base);
  }

  // orderQueue->print();

}

Orders::~Orders() {

}

void Orders::receive_order(std::string order, Base &base) {

  if(order[0] == '*') {
    this->add_order_with_priority(order);
  }

  else {

    if (this->is_direct_order(order)) {

      this->execute_direct_order(order, base);

    }
    else{
      this->add_normal_order(order);
    }

  }

}

void Orders::add_normal_order(std::string order) {
  orderQueue->insert(order);
}

void Orders::add_order_with_priority(std::string order) {
  orderQueue->insert_with_priority(order);
}

void Orders::execute_direct_order(std::string order, Base &base) {
  if(order.find("ATIVAR") != std::string::npos) {
    this->activation_order(order, base);
  }
  else if(order.find("EXECUTAR") != std::string::npos) {

  }
  else if(order.find("RELATORIO") != std::string::npos) {

  }
  else if(order.find("RETORNAR") != std::string::npos) {
    this->return_order(order, base);
  }
}

void Orders::activation_order(std::string order, Base &base) {
  int id = std::stoi(order.substr(7, order.length()));
  base.activate_robot(id);
}

void Orders::relatory_order(std::string order, Base &base) {
  int id = std::stoi(order.substr(10, order.length()));
  base.activate_robot(id);
}

void Orders::return_order(std::string order, Base &base) {
  int id = std::stoi(order.substr(9, order.length()));
  base.return_robot(id);
}

bool Orders::is_direct_order(std::string order) {
  return (order.find("ATIVAR") != std::string::npos) || (order.find("EXECUTAR") != std::string::npos)
    || (order.find("RELATORIO") != std::string::npos) || (order.find("RETORNAR") != std::string::npos);
}
