//main.cpp
#include <fstream>
#include <istream>
#include <iostream>
#include "ItemType.h"
#include "BinaryTree.h"
using namespace std;

int main(int argc, char* argv[]) {
  BinaryTree tree;
  ifstream info(argv[1], ifstream::in);

  //read input
  char m;
  while(info >> m) {
    info.unget();
    string s;
    getline(info, s, ' ');
    int num = stoi(s);
    ItemType newItem;
    newItem.initialize(num);
    tree.insert(newItem);
  }
  
  cout << "Commands" << endl;
  cout << "insert (i), delete (d), retrieve (r), length (l), ";
  cout << "in-order (n), pre-order (p), post-order (o), ";
  cout << "getNumSingleParent (s), getNumLeafNodes (f), ";
  cout << "getSumOfSubtrees (t), quit (q)" << endl;

  //Commands
  bool cont = true;
  while(cont) {
    char command;
    cout << "Enter a command: ";
    cin >> command;

    switch(command) {
    case 'i':
      {
	int n;
	cout << "Item to insert: ";
	cin >> n;
	ItemType newItem;
	newItem.initialize(n);
	tree.insert(newItem);
	cout << "In-Order: ";
	tree.inOrder();
	break;
      }
    case 'd':
      {
	int n;
	cout << "Item to delete: ";
	cin >> n;
	ItemType newItem;
	newItem.initialize(n);
	tree.deleteItem(newItem);
	cout << "In-Order: ";
	tree.inOrder();
	break;
      }
    case 'r':
      {
	bool found = false;
	int n;
	cout << "Item to be retrieved: ";
	cin >> n;
	ItemType newItem;
	newItem.initialize(n);
	tree.retrieve(newItem, found);
	if (found) {
	  cout << "Item found in tree." << endl;
	} else {
	  cout << "Item not in tree." << endl;
	}
	break;
      }
    case 'l':
      {
	cout << "List Length: " << tree.getLength() << endl;
	break;
      }
    case 'n':
      {
	cout << "In-Order: ";
	tree.inOrder();
	break;
      }
    case 'p':
      {
	cout << "Pre-Order: ";
	tree.preOrder();
	break;
      }
    case 'o':
      {
	cout << "Post-Order: ";
	tree.postOrder();
	break;
      }
    case 's':
      {
	cout << "Number of Single Parents: ";
	cout << tree.getNumSingleParent() << endl;
	break;
      }
    case 'f':
      {
	cout << "Number of Leaf Nodes: ";
	cout << tree.getNumLeafNodes() << endl;
	break;
      }
    case 't':
      {
	int n;
	cout << "Item to get sum of subtrees: ";
	cin >> n;
	ItemType newItem;
	newItem.initialize(n);
	int sum = tree.getSumOfSubtrees(newItem);
	if (sum >= 0) {
	  cout << "Sum of subtrees: " << sum << endl;
	} else {
	  cout << "Item not in tree." << endl;
	}
	break;
      }
    case 'q':
      cont = false;
      break;
    default:
      cout << "Command not recognized. Try again" << endl;
      break;
    } //switch
  } //while
} //main
