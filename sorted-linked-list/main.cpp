
//main.cpp
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "ItemType.h"
#include "SortedLinkedList.h"
using namespace std;

int main(int argc, char* argv[]) {
  ifstream listData(argv[1], ifstream::in);
  SortedLinkedList* list = new SortedLinkedList();
  
  char n;
  while(listData >> n) {
    listData.unget();
    string node;
    getline(listData, node, ' ');
    int insert = stoi(node);
    ItemType item;
    item.initialize(insert);
    list->insertItem(item);
  }
  
  cout << "Commands: " << endl;
  cout << "(i) -  Insert value" << endl;
  cout << "(d) -  Delete value" << endl;
  cout << "(s) -  Search value" << endl;
  cout << "(n) -  Print next iterator value" << endl;
  cout << "(r) -  Reset iterator" << endl;
  cout << "(a) -  Delete alternate nodes" << endl;
  cout << "(m) -  Merge two lists" << endl;
  cout << "(t) -  Intersection" << endl;
  cout << "(p) -  Print list" << endl;
  cout << "(l) -  Print length" << endl;
  cout << "(q) -  Quit Program" << endl;

  bool cont = true;
  while (cont) {
    char command;
    cout << "Enter a command: ";
    cin >> command;
    
    switch(command) {
    case 'i':
      {
	list->printList(list);
	int num;
	cout << "Enter number: ";
	cin >> num;
	ItemType i;
	i.initialize(num);
	list->insertItem(i);
	list->printList(list);
	break;
      }
    case 'd':
      {
	list->printList(list);
	int num;
	cout << "Enter value to delete: ";
	cin >> num;
	ItemType i;
	i.initialize(num);
	list->deleteItem(i);
	list->printList(list);
	break;
      }
    case 's':
      {
	int num;
	cout << "Enter a value to search: ";
	cin >> num;
	ItemType i;
	i.initialize(num);
	int index = list->searchItem(i);
	if (index == -1) {
	  cout << "Item not found" << endl;
	} else {
	  cout << "Index: " << index << endl;
	}
	break;
      }
    case 'n': 
      {
	if(list->isEnd()) {
	  cout << "The end of the list has been reached" << endl;
	} else if (list->getLength() == 0) {
	  cout << "List is empty" << endl;
	} else {
	  ItemType i = list->getNextItem();
	  cout << i.getValue() << endl;
	}
	break;
      }
    case 'r':
      list->resetList();
      cout << "Iterator reset." << endl;
      break;
    case 'a':
      list->deleteAlternate();
      break;
    case 'm':
      {
	int len;
	string nums;
	cout << "Length of list to merge: ";
	cin >> len;
	cout << "List elements separated by spaces in order: ";
	cin.ignore();
	getline(cin, nums);

	SortedLinkedList* list2 = new SortedLinkedList();
	string delimiter = " ";
	for (int i = 0; i < len; i++) {
	  string num;
	  num = nums.substr(0, nums.find(delimiter));
	  nums.erase(0, 1 + nums.find(delimiter));
	  int enter = stoi(num);
	  ItemType item;
	  item.initialize(enter);
	  list2->insertItem(item);
	}
	list->mergeList(list2);
	break;
      }
    case 't':
      {
	int len;
	string nums;
	cout << "Length of list to find intersection: ";
	cin >> len;
	cout << "List elements separated by spaces in order: ";
	cin.ignore();
	getline(cin, nums);

	SortedLinkedList* list2 = new SortedLinkedList();
	string delimiter = " ";
	for (int i = 0; i < len; i++) {
	  string num;
	  num = nums.substr(0, nums.find(delimiter));
	  nums.erase(0, 1 + nums.find(delimiter));
	  int enter = stoi(num);
	  ItemType item;
	  item.initialize(enter);
	  list2->insertItem(item);
	}
	list->findCommonElements(list2);
	break;
      }
    case 'p':
      list->printList(list);
      break;
    case 'l':
      cout << "List length is ";
      cout << list->getLength() << endl;
      break;
    case 'q':
      cont = false;
      break;
    default:
      cout << "Invalid command, try again!" << endl;
      break;
      }

  }

} //main
