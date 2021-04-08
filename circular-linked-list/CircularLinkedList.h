//CircularLinkedList.h
#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "ItemType.h"

struct NodeType {
  ItemType data;
  NodeType *next;
};

class CircularLinkedList {
 public:
  CircularLinkedList();
  ~CircularLinkedList();
  bool findItem(ItemType item, NodeType* &location, NodeType* &predLoc);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  int lengthIs() const;
  void print();
  void deleteSubsection(int start, int end);
  int mode();

 private:
  int length;
  NodeType *head;
};

#endif

