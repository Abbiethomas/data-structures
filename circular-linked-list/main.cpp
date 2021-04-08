//main.cpp
#include <fstream>
#include <istream>
#include <iostream>
#include "ItemType.h"
#include "CircularLinkedList.h"
using namespace std;

int main(int argc, char* argv[]) {
  CircularLinkedList list;
  ifstream fs(argv[1], ifstream::in);

  //read input
  char m;
  while(fs >> m) {
    fs.unget();
    string s;
    getline(fs, s, ' ');
    int num = stoi(s);
    ItemType newItem;
    newItem.initialize(num);
    list.insertItem(newItem);
  }

  cout << "insert (i), delete (d), length (l), print (p), ";
  cout << "deleteSub (b), mode (m), quit (q)" << endl;
  
  //Commands
  bool cont = true;
  while (cont) {
    char command;
    cout << "Enter a command: ";
    cin >> command;

    switch(command) {
    case 'i':
      {
	int num;
	cout << "Number to insert: ";
	cin >> num;
	ItemType newItem;
	newItem.initialize(num);
	list.insertItem(newItem);
	list.print();
	break;
      }
    case 'd':
      {
	int num;
	cout << "Number to delete: ";
	cin >> num;
	ItemType deleteItem;
	deleteItem.initialize(num);
	list.deleteItem(deleteItem);
	list.print();
	break;
      }
    case 'l':
      {
	cout << "The length is: ";
	cout << list.lengthIs() << endl;
	break;
      }
    case 'p':
      {
	list.print();
	break;
      }
    case 'b':
      {
	int low;
	int high;
	cout << "Enter lower bound: ";
	cin >> low;
	cout << "Enter upper bound: ";
	cin >> high;
	cout << "Original list: ";
	list.print();
	list.deleteSubsection(low, high);
	cout << "Modified list: ";
	list.print();
	break;
      }
    case 'm':
      {
	list.print();
	cout << "Mode: ";
	cout << list.mode() << endl;
	break;
      }
    case 'q':
      cont = false;
      break;
    default:
      cout << "Invalid command, try again!" << endl;
      break;
    }
  }
}//main
