#include <fstream>
#include "../include/base.hpp"
#include "../include/map.hpp"

Base::Base(std::ifstream &myFile) {
  resources = 0;
  aliens = 0;
  map = new Map(myFile);
}

Base::~Base() {
  delete map;
}
