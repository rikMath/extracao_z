#include <fstream>
#include <string>
#include "./queue.hpp"
#include "./robot.hpp"
#include "./base.hpp"

#ifndef ORDERS_H
#define ORDERS_H

class Orders{
private:
   PriorityQueue<std::string>* orderQueue;

   void executeOrders();

   void receive_order(std::string, Base &base);
   void add_order_with_priority(std::string);
   void add_normal_order(std::string);

   void execute_direct_order(std::string, Base &base);
   void activation_order(std::string, Base &base);
   void relatory_order(std::string, Base &base);
   void return_order(std::string, Base &base);

   bool is_direct_order(std::string);

public:
  Orders (std::ifstream &file, Base &base);
  virtual ~Orders ();
};

#endif
