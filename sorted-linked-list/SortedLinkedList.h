//SortedLinkedList.h
#include "ItemType.h"
#include "ListNode.h"
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList {
 public:
  SortedLinkedList(); //constructor
  ~SortedLinkedList(); 
  int getLength() const;
  ListNode* getHead();
  bool isEnd();
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType item);
  ItemType getNextItem();
  void resetList();
  void mergeList(SortedLinkedList* list);
  void printList(SortedLinkedList* list);
  bool isDuplicate(ItemType item);
  void deleteAlternate();
  void findCommonElements(SortedLinkedList* list);
 private:
  ListNode *head;
  ListNode *currentPos;
  int length;
};
#endif
