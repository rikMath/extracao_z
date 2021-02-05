#include <fstream>
#include <string>
#include "./queue.hpp"
#include "./robot.hpp"

#ifndef ORDERS_H
#define ORDERS_H

class Orders{
private:
   PriorityQueue<std::string>* orderQueue;

   void executeOrders();
   void receive_order(std::string);
   void add_order_with_priority(std::string);
   void add_normal_order(std::string);

public:
  Orders (std::ifstream &file);
  virtual ~Orders ();
};

#endif
