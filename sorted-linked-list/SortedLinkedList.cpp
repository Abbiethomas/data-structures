//SortedLinkedList.cpp
#include <cstddef>
#include "SortedLinkedList.h"
#include <iostream>
#include "ItemType.h"
using namespace std;

SortedLinkedList::SortedLinkedList() {
  length = 0;
  head = NULL;
  currentPos = NULL;
} //constructor

SortedLinkedList::~SortedLinkedList() {

} //deconstructor

int SortedLinkedList::getLength() const {
  return length;
} //length

ListNode* SortedLinkedList::getHead() {
  return head;
} //getHead

bool SortedLinkedList::isEnd() {
  if (currentPos == NULL) {
    return false;
  } else if (currentPos->next == NULL) {
    return true;
  } else {
    return false;
  }
} //getCurrentPos
void SortedLinkedList::insertItem(ItemType item) {
  if (length == 0) {
    ListNode* newNode = new ListNode();
    newNode->item = item;
    newNode->next = NULL;
    head = newNode;;
    length++;
    return;
  }
  ListNode* newNode;
  ListNode* predLoc;
  ListNode* location;
  bool moreToSearch;

  location = head;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  //find where node should be inserted
  while(moreToSearch) {
    if (location->item.compareTo(item) == Comparison::GREATER) {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    } else if (location->item.compareTo(item) == Comparison::EQUAL) {
      cout << "You cannot insert the duplicate item" << endl;
      return;
    } else {
      moreToSearch = false;
    }
  }
  
  //initialize Node
  newNode = new ListNode();
  newNode->item = item;

  //insert Node
  if (predLoc == NULL) {
    newNode->next = head;
    head = newNode;
  } else {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
} //insertItem

void SortedLinkedList::deleteItem(ItemType item) {
  if (length == 0) {
    cout << "You cannot delete from an empty list" << endl;
    return;
  }
  ListNode* predLoc;
  ListNode* location;
  predLoc = NULL;
  location = head;
  bool found = false;
  bool moreToSearch = (location != NULL);

  //find node to be deleted
  while (moreToSearch && !found) {
    switch(location->item.compareTo(item)) {
    case Comparison::GREATER: 
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
      break;
    case Comparison::EQUAL:
      found = true;
      break;
    case Comparison::LESS:
      moreToSearch = false;
      break;
    }
  }

  //delete node
  ListNode* temp = location;
  if (moreToSearch == false) {
    cout << "Item not found" << endl;
    return;
  } else if ((found == true) && (predLoc = NULL)) {
    head = temp->next;
    delete temp;
  } else if (found == true) {
    predLoc->next = (predLoc->next)->next;
    delete temp;
  }

  length--;
} //deleteItem

int SortedLinkedList::searchItem(ItemType item) {
  int index = 0;
  ListNode* location = head;
  bool found = false;
  bool moreToSearch = (location != NULL);
  while (moreToSearch && !found) {
    switch(location->item.compareTo(item)) {
    case Comparison::GREATER: 
      location = location->next;
      moreToSearch = (location != NULL);
      index++;
      break;
    case Comparison::EQUAL:
      found = true;
      break;
    case Comparison::LESS:
      moreToSearch = false;
      break;
    }
  }
  if (moreToSearch == false) {
    cout << "Item not found" << endl;
    return -1;
  } else {
    return index;
  }
} //searchItem

//check that list isn't empty and end of list isn't reached in main
ItemType SortedLinkedList::getNextItem() {
  if (currentPos == NULL) {
    currentPos = head;
  } else {
    currentPos = currentPos->next;
  }
  ItemType nextItem = currentPos->item;
  return (nextItem);
} //getNextItem

void SortedLinkedList::resetList() {
  currentPos = NULL;
} //resetList


void SortedLinkedList::mergeList(SortedLinkedList* list) {
  ListNode* position = list->head;
  bool moreToSearch = (position != NULL);
  cout << "List 1: ";
  printList(this);
  cout << "List 2: ";
  printList(list);
  while (moreToSearch) {
    if(isDuplicate(position->item)) {
      cout << "Sorry, you cannot insert a duplicate item" << endl;
      return;
    }
    insertItem(position->item);
    position = position->next;
    moreToSearch = (position !=NULL);
  }
  printList(this);
} //mergeList

void SortedLinkedList::printList(SortedLinkedList* list) {
  ListNode* position = list->getHead();
  bool moreToSearch = (position != NULL);
  while (moreToSearch) {
    cout << position->item.getValue() << " ";
    position = position->next;
    moreToSearch = (position != NULL);
  }
  cout << "\n";
} //printList

bool SortedLinkedList::isDuplicate(ItemType item) {
  ListNode* location = head;
  bool found = false;
  bool moreToSearch = (location != NULL);
  while (moreToSearch && !found) {
    switch(location->item.compareTo(item)) {
    case Comparison::GREATER: 
      location = location->next;
      moreToSearch = (location != NULL);
      break;
    case Comparison::EQUAL:
      found = true;
      break;
    case Comparison::LESS:
      moreToSearch = false;
      break;
    }
  }
  return found;
} //isDuplicate

void SortedLinkedList::deleteAlternate() {
  cout << "List before alternate delete: ";
  printList(this);
  ListNode* position;
  position = head;
  bool moreToSearch = (position != NULL);

  while (moreToSearch) {
    if (position->next == NULL) {
	moreToSearch = false;
    } else if ((position->next)->next == NULL) {
      position->next = NULL;
    } else {
      position->next = (position->next)->next;
    }
    position = position->next;
    moreToSearch = (position != NULL);
  }
  cout << "List after alternate delete: ";
  printList(this);
} //deleteAlternate

void SortedLinkedList::findCommonElements(SortedLinkedList* list) {
  cout << "List 1: ";
  printList(this);
  cout << "List 2: ";
  printList(list);

  ListNode* position = head;
  bool moreToSearch = (position != NULL);
  while (moreToSearch) {
    ListNode* location = list->head;
    bool more = (location != NULL);
    bool common = false;
    while (more) {
      switch (position->item.compareTo(location->item)) {
      case Comparison::GREATER:
	location = location->next;
	more = (location != NULL);
	break;
      case Comparison::EQUAL:
	common = true;
	more = false;
	break;
      case Comparison:: LESS:
	more = false;
	break;
      }
    }
    if (common == false) {
      deleteItem(position->item);
    }
    position = position->next;
    moreToSearch = (position != NULL);
  }

  cout << "Intersection";
  printList(this);
} //findCommonElements
