//Queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include "Customer.h"

class Queue {
 public:
  Queue(int max);
  ~Queue();
  void makeEmpty();
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(Customer customer);
  void dequeue(Customer& customer);

 private:
  int front;
  int rear;
  Customer* customers;
  int maxQue;
};

#endif
