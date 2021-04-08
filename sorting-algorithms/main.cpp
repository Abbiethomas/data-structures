//main.cpp
#include <iostream>
#include <fstream>
#include <istream>
#include "Sorting.h"
#include "ItemType.h"
using namespace std;

int main(int argc, char* argv[]) {
  int length = 1;

  //read input to determine length
  ifstream len(argv[1], ifstream::in);
  char m;
  while (len >> m) {
    len.unget();
    string s;
    getline(len, s, ' ');
    length++;
  }

  length--;
  ItemType* array = new ItemType[length];
  Sorting sort(length);

  //read input to fill array
  ifstream data(argv[1], ifstream::in);
  char n;
  int index = 0;
  while(data >> n) {
    data.unget();
    string num;
    getline(data, num, ' ');
    int numInt = stoi(num);
    ItemType newItem;
    newItem.initialize(numInt);
    array[index] = newItem;
    index++;
  }

  //commands
  cout << "selection-sort (s), merge-sort (m), heap-sort (h), quick-sort-fp (q) quick-sort-rp (r)" << endl;
  cout << "Enter the algorithm: ";
  char command;
  cin >> command;
  
  switch(command) {
  case 's':
    {
      sort.selectionSort(array);
      for(int i = 0; i < length; i++) {
	cout << array[i].getValue() << " ";
      }
      cout << endl;
      cout << "       #Selection-sort comparisons: ";
      cout << sort.getComparisons() << endl;
      break;
    }
  case 'm':
    {
      sort.mergeSort(array, 0, length - 1);
      for(int i = 0; i < length; i++) {
	cout << array[i].getValue() << " ";
      }
      cout << endl;
      cout << "       #Merge-sort comparisons: ";
      cout << sort.getComparisons() << endl;
      break;
    }
  case 'h':
    {
      sort.heapSort(array);
      for(int i = 0; i < length; i++) {
	cout << array[i].getValue() << " ";
      }
      cout << endl;
      cout << "       #Heap-sort comparisons: ";
      cout << sort.getComparisons() << endl;
      break;
    }
  case 'q':
    {
      sort.quickSortFirst(array, 0 , length - 1);
      for(int i = 0; i < length; i++) {
	cout << array[i].getValue() << " ";
      }
      cout << endl;
      cout << "       #Quick-sort-fp comparisons: ";
      cout << sort.getComparisons() << endl;
      break;
    }
  case 'r':
    {
      sort.quickSortRandom(array, 0 , length - 1);      
      for(int i = 0; i < length; i++) {
	cout << array[i].getValue() << " ";
      }
      cout << endl;
      cout << "       #Quick-sort-rp comparisons: ";
      cout << sort.getComparisons() << endl;
      break;
    }
  default:
    cout << "Command not recognized" << endl;
    break;
  } //switch
  delete[] array;
} //main
