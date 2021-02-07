#include <iostream>

#ifndef QUEUE_H
#define QUEUE_H

template <class TValue> class Queue;
template <class TValue> class PriorityQueue;
template <class TValue> class QueueElement;

template <class TValue>
class QueueElement {

protected:
  TValue item;
  QueueElement* next;

public:
  QueueElement<TValue> (){};
  QueueElement<TValue> (TValue);
  inline void print(){std::cout << item << std::endl;};

  friend class Queue<TValue>;
  friend class PriorityQueue<TValue>;

};

template <class TValue>
QueueElement<TValue>::QueueElement(TValue item){
  this->item = item;
  next = NULL;
}


template <class TValue>
class Queue {
protected:
  int length;
  QueueElement<TValue>* front;
  QueueElement<TValue>* back;

public:
  Queue<TValue> ();
  void insert(TValue element);
  TValue delete_element();
  int get_element_number();
  void clear();
  void print();
};



template <class TValue>
Queue<TValue>::Queue():length(0){front=NULL;back=NULL;}

template <class TValue>
void Queue<TValue>::insert(TValue element){

  QueueElement<TValue>* newCell;
  newCell = new QueueElement<TValue>;
  newCell->item = element;

  if (length++ != 0){
    back->next = newCell;
    back = newCell;
  }
  else{
    // Não Existem Elementos na Fila (Fila Vazia)

    front = newCell;
    back = newCell;
  }

}

template <class TValue>
TValue Queue<TValue>::delete_element(){

  length--;

  if(front != NULL){
    TValue returnItem = front->item;
    QueueElement<TValue>* toDeleteElement = front;

    front = front->next;

    delete toDeleteElement;

    return returnItem;
  }

  return "";

}

template <class TValue>
void Queue<TValue>::clear(){
  QueueElement<TValue>* current_element;
  current_element = front;

  while (current_element != NULL){
    this->delete_element();
    current_element = current_element->next;
  }
  length = 0;
}

template <class TValue>
int Queue<TValue>::get_element_number(){
  return this->length;
}

template <class TValue>
void Queue<TValue>::print(){
  QueueElement<TValue>* current_element = front;

  int size = this->get_element_number();
  // std::cout << " Relatório tamanho: " << size << std::endl;
  std::string current_order;
  for(int i = 0; i < size; i++) {
    current_order = current_element->item;

    std::cout << current_order << std::endl;

    current_element = current_element->next;

  }
}



template <class TValue>
class PriorityQueue : public Queue<TValue> {

public:
  PriorityQueue();
  void insert_with_priority(TValue);
};

template <class TValue>
PriorityQueue<TValue>::PriorityQueue(){}

template <class TValue>
void PriorityQueue<TValue>::insert_with_priority(TValue element){

  QueueElement<TValue>* newCell;
  newCell = new QueueElement<TValue>;
  newCell->item = element;

  newCell->next = this->front;
  this->front = newCell;

  this->length++;
}

#endif
