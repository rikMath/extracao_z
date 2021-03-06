#include <iostream>
#include <string>
#include "./map.hpp"
#include "./queue.hpp"

#ifndef ROBOT_H
#define ROBOT_H


class Robot {
private:
  const int id;
  int pos_x, pos_y;
  int resources, aliens;
  bool active;
  PriorityQueue<std::string>* toExecuteOrders;
  PriorityQueue<std::string>* executedOrders;

  void process_order(std::string, Map&);


public:
  // Construtor
  Robot (int, int=0, int=0);

  // Destrutor
  virtual ~Robot ();

  // Getters
  inline int get_id() const {return id;};
  inline int get_pos_x() const {return pos_x;};
  inline int get_pos_y() const {return pos_y;};
  inline int get_resources() const {return resources;}
  inline int get_aliens() const {return aliens;}
  inline bool is_active() const {return active;}

  // Setters
  bool activate();
  void return_to_base();

  // Ordens referentes ao mapa
  bool move_to(const Map& map, int x, int y);
  bool destroy_alien(Map& map, int x, int y);
  bool collect_resource(Map& map, int x, int y);

  // Ordens de Recursos/Aliens coletados
  int return_resources_to_base();
  int return_aliens_to_base();

  // Outras ordens
  void print_relatory();
  void execute_order(Map& map);
  void add_normal_order(std::string);
  void add_order_with_priority(std::string);
  void move_order(std::string, Map&);
  void collect_order(Map&);
  void destroy_order(Map&);
};

#endif
