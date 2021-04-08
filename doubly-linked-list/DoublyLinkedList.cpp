//DoublyLinkedList.cpp
#include "DoublyLinkedList.h"
#include <iostream>
#define NULL nullptr
using namespace std;

//Constructor
DoublyLinkedList::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
 
}

//Deconstructor
DoublyLinkedList::~DoublyLinkedList() {

}

//length
int DoublyLinkedList::lengthIs() const {
  int length = 0;
  NodeType *location = head;
  bool moreToSearch = (location != NULL);
  while (moreToSearch) {
    length ++;
    location = location->next;
    moreToSearch = (location != NULL);
  }
  return length;
}

//find item
bool DoublyLinkedList::findItem(ItemType item, NodeType* &location) {
  bool found = false;
  location = head;
  bool moreToSearch = (location !=NULL);

  while (moreToSearch && !found) {
    if (item.compareTo(location->data) == Comparison::LESS) {
      moreToSearch = false;
    } else if (item.compareTo(location->data) == Comparison::EQUAL) {
      found = true;
    } else {
      location = location->next;
      moreToSearch = (location != NULL);
    }
  }
  return found;
}

//insert item
void DoublyLinkedList::insertItem(ItemType &item) {
  NodeType *newNode = new NodeType;
  NodeType *location = head;
  NodeType *predLoc = head;
  newNode->data = item;

  if (head != NULL) {
    findItem(item, location);
    if(location == NULL) { //last node
      newNode->back = tail;
      tail->next = newNode;
      tail = newNode;
    } else if (location->back == NULL) { //first node
      newNode->next = head;
      head = newNode;
    } else { //middle node
      predLoc = location->back;
      newNode->back = location->back;
      newNode->next = location;
      predLoc->next = newNode;
      location->back = newNode;
    }
  } else { //special case: empty list
    head = newNode;
    tail = newNode;
  }
  
}

//delete item
void DoublyLinkedList::deleteItem(ItemType &item) {
  NodeType *location = head;
  NodeType *predLoc = head;
  
  if (head == NULL) { //check if list is empty
    cout << "You cannot delete from an empty list" << endl;
    return;
  }
  if(!findItem(item, location)) { //check if item was found
    cout << "Item not in list!" << endl;
    return;
  } else { 
    predLoc = location->back;
    if ((location->back == NULL) && (location->next == NULL)) { //one node
      head = NULL;
      tail = NULL;
      return;
    }
    if (location->back == NULL) { //deleting first node
      head = location->next;
      head->back = NULL;
    } else if (location->next == NULL) { //deleting last node
      tail = location->back;
      tail->next = NULL;
    } else { //middle node
      predLoc->next = location->next;
      location = location->next;
      location->back = predLoc;
    } 
  }

}

//print
void DoublyLinkedList::print() {
  NodeType *location = head;
  bool moreToSearch = (location != NULL);
  while (moreToSearch) {
    location->data.print();
    location = location->next;
    moreToSearch = (location != NULL);
  }
  cout << endl;
}

//print reverse
void DoublyLinkedList::printReverse() {
  bool moreToSearch = true;
  NodeType *location = tail;
  while (moreToSearch) {
    location->data.print();
    location = location->back;
    moreToSearch = (location != NULL);
  }
  cout << endl;
}

//swap alternate
void DoublyLinkedList::swapAlternate() {
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }
  NodeType *temp1 = head;
  NodeType *temp2 = head->next;
  head = head->next;
  bool moreToSearch = true;

  while (moreToSearch) {
    //swap
    temp2->back = temp1->back;
    temp1->next = temp2->next;
    temp2->next = temp1;
    temp1->back = temp2;
    //set temp1 and temp2
    if (temp1->next == NULL) {
      moreToSearch = false;
      tail = temp1;
    } else {
      temp2 = temp1->next;
      temp2->back = temp1;
      temp1 = temp1->next;;
      if (temp1->next == NULL) {
	moreToSearch = false;
	tail = temp1;
      } else {
	temp2 = temp1->next;
      }
    }
  }

}
