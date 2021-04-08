//Queue.cpp
#include "Queue.h"
#include <iostream>
using namespace std;

/* Constructor. Initializes queue object with
   paramenter max, representing maximum size of
   the queue.
 */
Queue::Queue(int max) {
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  customers = new Customer[maxQue];
}

/* Deconstructor. Free up user allocated memory.
 */
Queue::~Queue() {
  delete [] customers;
}

/* Removes all customers from the queue and 
   resets front and rear variables
 */
void Queue::makeEmpty() {
  front = maxQue - 1;
  rear = maxQue - 1;
}

/* Returns whether the list is empty or not
 */
bool Queue::isEmpty() const {
  return (rear == front);
}

/* Returns whether the list is full or not
 */
bool Queue::isFull() const {
  return ((rear + 1) % maxQue == front);
}

/* Customer object added to rear of queue
 */
void Queue::enqueue(Customer customer) {
  if (isFull()) {
    return;
  } else { 
    rear = (rear + 1) % maxQue;
    customers[rear] = customer;
  }
}

/* Customer object removed from front of queue
 */
void Queue::dequeue(Customer& customer) {
  if (isEmpty()) {
    return;
  } else {
    front = (front + 1) % maxQue;
    customer = customers[front];
  }
}
