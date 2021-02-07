#include <fstream>
#include <string>
#include <iostream>
#include "../include/order.hpp"
#include "../include/queue.hpp"

Orders::Orders(std::ifstream &file, Base &base) {

  // orderQueue = new PriorityQueue<std::string>;

  std::string t;
  while(getline(file, t)){
    this->receive_order(t, base);
  }

  // orderQueue->print();

}

Orders::~Orders() {
  // std::cout << "entrando destrutor orders" << std::endl;
  // delete orderQueue;
  // std::cout << "saindo destrutor orders" << std::endl;
}

void Orders::receive_order(std::string order, Base &base) {

  if(order[0] == '*') {
    this->add_order_with_priority(order, base);
  }

  else {

    if (this->is_direct_order(order)) {

      this->execute_direct_order(order, base);

    }
    else{
      this->add_normal_order(order, base);
    }

  }

}

void Orders::add_normal_order(std::string order, Base &base) {
  int id;
  if (order.find("MOVER") != std::string::npos){
    id = std::stoi(order.substr(6, 8));
    // std::cout << order << " " << id << std::endl;
  }
  else if (order.find("COLETAR") != std::string::npos){
    id = std::stoi(order.substr(8, order.length()));
    // std::cout << order << " " << id << std::endl;
  }
  else if (order.find("ELIMINAR") != std::string::npos){
    id = std::stoi(order.substr(9, order.length()));
    // std::cout << order << " " << id << std::endl;
  }
  base.add_normal_order(order, id);
}

void Orders::add_order_with_priority(std::string order, Base &base) {
  int id;
  if (order.find("MOVER") != std::string::npos){
    id = std::stoi(order.substr(7, 9));
    // std::cout << order << " " << id << std::endl;
  }
  else if (order.find("COLETAR") != std::string::npos){
    id = std::stoi(order.substr(9, order.length()));
    // std::cout << order << " " << id << std::endl;
  }
  else if (order.find("ELIMINAR") != std::string::npos){
    id = std::stoi(order.substr(10, order.length()));
    // std::cout << order << " " << id << std::endl;
  }
  base.add_order_with_priority(order, id);
}

void Orders::execute_direct_order(std::string order, Base &base) {
  if(order.find("ATIVAR") != std::string::npos) {
    this->activation_order(order, base);
  }
  else if(order.find("EXECUTAR") != std::string::npos) {
    this->execute_order(order, base);
  }
  else if(order.find("RELATORIO") != std::string::npos) {
    this->relatory_order(order, base);
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
  base.print_relatory(id);
}

void Orders::return_order(std::string order, Base &base) {
  int id = std::stoi(order.substr(9, order.length()));
  base.return_robot(id);
}

void Orders::execute_order(std::string order, Base &base) {
  int id = std::stoi(order.substr(9, order.length()));
  base.execute_order(id);
}

bool Orders::is_direct_order(std::string order) {
  return (order.find("ATIVAR") != std::string::npos) || (order.find("EXECUTAR") != std::string::npos)
    || (order.find("RELATORIO") != std::string::npos) || (order.find("RETORNAR") != std::string::npos);
}
