#include <fstream>
#include <string>
#include <iostream>
#include "../include/order.hpp"

Orders::Orders(std::ifstream &myFile) {
  std::string t;
  while(getline(myFile, t)){
    std::cout << t << std::endl;
  }

}
