#include <fstream>
#include <string>
#include <iostream>
#include "../include/order.hpp"

Orders::Orders(std::ifstream &file) {

  orderQueue = new PriorityQueue<std::string>;

  std::string t;
  while(getline(file, t)){
    this->receive_order(t);
  }

  orderQueue->print();

}

Orders::~Orders() {

}

void Orders::receive_order(std::string order) {

  if(order[0] == '*') {
    this->add_order_with_priority(order);
  }

  else {
    this->add_normal_order(order);
  }

}

void Orders::add_normal_order(std::string order) {
  orderQueue->insert(order);
}

void Orders::add_order_with_priority(std::string order) {
  orderQueue->insert_with_priority(order);
}
