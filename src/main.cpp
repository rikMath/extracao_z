#include <iostream>
#include <string>
#include <fstream>
#include "../include/queue.hpp"
#include "../include/matrix.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  PriorityQueue<double> q;
  cout << q.get_element_number() << endl;
  q.insert(2.2);
  q.insert(2.3);
  q.insert_with_priority(1);
  q.print();
  cout << "..........." << endl;
  q.delete_element();
  q.print();

  ifstream in("mapa.txt");
  Matrix m(in);
  return 0;
}
