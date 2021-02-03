#include <iostream>
#include <string>
#include <fstream>
#include "../include/queue.hpp"
#include "../include/matrix.hpp"
#include "../include/map.hpp"
#include "../include/robot.hpp"
#include "../include/base.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  PriorityQueue<double> q;
  q.print();
  cout << "..........." << endl;
  q.insert(2.2);
  q.insert(2.3);
  q.insert_with_priority(1);
  q.print();
  cout << "..........." << endl;
  q.delete_element();
  q.print();

  string tt;

  ifstream in("src/mapa.txt");
  // Matrix mm(in);
  // mm.print();
  // Map l(in);
  // l.print();
  // l.destroy_alien(1,1);
  // cout << "\n\n\n";
  // l.print();
  // cout << l.destroy_alien(5,2) << endl;
  // std::cout<<mm.getRows()<<"\n";
  // std::cout<<mm.getCols();

  // Robot r(1);
  // cout << r.move_to(l, 2, 3) << endl;

  Base* b = new Base(in);
  // b->print_map();
  return 0;
}
