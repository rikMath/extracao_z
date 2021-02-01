#include <iostream>

template <class TValue> class Queue;
template <class TValue> class PriorityQueue;
template <class TValue> class QueueElement;

template <class TValue>
class QueueElement {

protected:
  TValue item;
  QueueElement* next;

public:
  QueueElement<TValue> (){item=NULL;next=NULL;};
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
  void print();
};



template <class TValue>
Queue<TValue>::Queue():length(0){}

template <class TValue>
void Queue<TValue>::insert(TValue element){

  QueueElement<TValue>* newCell;
  newCell = new QueueElement<TValue>;
  newCell->item = element;

  if (length != 0){
    back->next = newCell;
    back = newCell;
  }
  else{
    // Não Existem Elementos na Fila (Fila Vazia)

    front = newCell;
    back = newCell;
  }

  length++;
}

template <class TValue>
TValue Queue<TValue>::delete_element(){
  TValue returnItem = front->item;
  QueueElement<TValue>* toDeleteElement = front;

  front = front->next;

  delete toDeleteElement;

  return returnItem;
}

template <class TValue>
int Queue<TValue>::get_element_number(){
  return this->length;
}

template <class TValue>
void Queue<TValue>::print(){
  QueueElement<TValue>* current_element;
  current_element = front;

  while (current_element != NULL){
    current_element->print();
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
