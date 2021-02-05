#include <fstream>
#include "../include/base.hpp"
#include "../include/map.hpp"
#include "../include/order.hpp"
#include "../include/queue.hpp"

Base::Base(std::ifstream &mapFile, std::ifstream &orderFile) {
  resources = 0;
  aliens = 0;
  map = new Map(mapFile);
  orders = new Orders(orderFile);
  robots = new RobotArray;
}

Base::~Base() {
  delete map;
  delete orders;
  delete robots;
}
