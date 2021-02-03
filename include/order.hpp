#include <fstream>
#include <string>
#include "./queue.hpp"

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

class Orders : public PriorityQueue<std::string>{
private:


public:
  Orders (std::ifstream &myFile);
  // virtual ~OrderQueue ();
};

#endif
