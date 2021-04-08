//DoublyLinkedLink.h
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "ItemType.h"

struct NodeType {
  ItemType data;
  NodeType *next;
  NodeType *back;
};


class DoublyLinkedList {
 public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  int lengthIs() const;
  bool findItem(ItemType item, NodeType* &location);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void print();
  void printReverse();
  void swapAlternate();

 private:
  NodeType *head;
  NodeType *tail;
  int length;
};

#endif
