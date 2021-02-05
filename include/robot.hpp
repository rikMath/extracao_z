#include <iostream>
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


public:
  // Construtor
  Robot (int, int=-1, int=-1);

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

  // Ordens referentes ao mapa
  bool move_to(const Map& map, int x, int y);
  bool destroy_alien(Map& map, int x, int y);
  bool collect_resource(Map& map, int x, int y);

  // Ordens de Recursos/Aliens coletados
  int return_resources_to_base();
  int return_aliens_to_base();

};

#endif
