#include <iostream>
#include <string>
#include <fstream>
#include "../include/queue.hpp"
#include "../include/matrix.hpp"
#include "../include/map.hpp"
#include "../include/robot.hpp"
#include "../include/base.hpp"
#include "../include/order.hpp"
#include "../include/robotArray.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream mapFile (argv[1]);
  ifstream orderFile(argv[2]);

  Base base(mapFile, orderFile);
  base.print_map();
  return 0;
}
