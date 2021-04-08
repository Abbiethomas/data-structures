//CircularLinkedList.cpp
#include "CircularLinkedList.h"
#define NULL nullptr
using namespace std;

//constructor
CircularLinkedList::CircularLinkedList() {
  length = 0;
}

//deconstructor
CircularLinkedList::~CircularLinkedList() {

}

//find item
bool CircularLinkedList::findItem(ItemType item, NodeType* &location, NodeType* &predLoc) {
  bool moreToSearch = true;
  bool found = false;
  
  location = head->next;
  predLoc = head;
  
  while (moreToSearch && !found) {
    if (item.compareTo(location->data) == Comparison::LESS) {
      moreToSearch = false;
    } else if (item.compareTo(location->data) == Comparison::EQUAL) {
      found = true;
    } else {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != head->next);
    }
  }
  return found;
}

//insert item
void CircularLinkedList::insertItem(ItemType &item) {
  NodeType *newNode = new NodeType;
  newNode->data = item;
  if (head != NULL) {
    NodeType *location = head->next;
    NodeType *predLoc = head;
    findItem(item, location, predLoc);
    newNode->next = predLoc->next;
    predLoc->next = newNode;

    if (head->data.compareTo(item) == Comparison::LESS) { //special case: last item in list
      head = newNode;
    }
  } else { //special case: empty list
    head = newNode;
    newNode->next = newNode;
  }
  length++;
}

//delete item
void CircularLinkedList::deleteItem(ItemType &item) {
  NodeType *location;
  NodeType *predLoc;
  
  if (head == NULL) {
    cout << "You cannot delete from an empty list." << endl;
    return;
  }
  if (!findItem(item, location, predLoc)) {
    cout << "Item not in list!" << endl;
    return;
  }
  if (predLoc == location) { //only node in list
    head = NULL;
  } else if (head == NULL) {
    cout << "You cannot delete from an empty list" << endl;
  } else {
    predLoc->next = location->next;
    if (location == head) {
      head = predLoc;
    }
  }
  length--;
}

//length
int CircularLinkedList::lengthIs() const {
  return length;
}

//print
void CircularLinkedList::print() {
  if (head == NULL) {
    cout << "" << endl;
    return;
  }
  NodeType *location = head->next;
  for(int i = 0; i < length; i++) {
    location->data.print();
    location = location->next;
  }
  cout << endl;
}

//delete subsection
void CircularLinkedList::deleteSubsection(int start, int end) {
  bool moreToSearch = true;
  NodeType *location = head->next;
  NodeType *predLoc = head;
  while(moreToSearch) {
    if (((location->data.getValue() > start) &&
	 (location->data.getValue() < end)) ||
	(location->data.getValue() == start)) {
      predLoc = location;
      location = location->next;
      deleteItem(predLoc->data);
    } else if (location->data.getValue() == end){
      deleteItem(location->data);
      moreToSearch = false;
    } else if (location->data.getValue() > end) {
      moreToSearch = false;
    } else {
      moreToSearch = false;
    }
  }
}

//mode
int CircularLinkedList::mode() {
  NodeType *location = head->next;
  int num = location->data.getValue();
  int count = 1;
  int highestNum = num;
  int highestCount = count;
  for(int i; i < length; i++) {
    location = location->next;
    if (location->data.getValue() == num) {
      count++;
    } else {
      if (count > highestCount) {
	highestCount = count;
	highestNum = num;
      }
      num = location->data.getValue();
      count = 1;
    }
  }
  return highestNum;
}
