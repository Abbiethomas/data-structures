//Sorting.cpp
#include "Sorting.h"
#include "ItemType.h"
#include <cstdlib>

/* Constructor, sets length
 */
Sorting::Sorting(int len) {
  length = len;
} 

/* Get comparisons value
 */
long Sorting::getComparisons() {
  return comparisons;
}

/* Selection Sort
 */
void Sorting::selectionSort(ItemType *values) {
  int endIndex = length - 1;
  for(int i = 0; i < endIndex; i++) {
    //swap
    ItemType temp;
    int min = minIndex(values, i, endIndex);
    temp.initialize(values[i].getValue());
    values[i] = values[min];
    values[min] = temp;
  }
}  

/* Find Minimum Index 
   Used in selection sort
 */
int Sorting::minIndex(ItemType values[], int start, int end) {
  int indexOfMin = start;
  for(int i = start + 1; i <= end; i++) {
    if(values[i].compareTo(values[indexOfMin]) == Comparison::LESS) {
      indexOfMin = i;
    }
    comparisons++;
  }
  return indexOfMin;
}

/* Merge Sort
 */
void Sorting::mergeSort(ItemType *values, int first, int last) {
  if(first < last) { //general case 
    int middle = (first + last) / 2;
    mergeSort(values, first, middle);
    mergeSort(values, middle + 1, last);
    merge(values, first, middle, middle + 1, last);
  }
}

/* Merge
   Used in merge sort
 */
void Sorting::merge(ItemType *values, int leftFirst, int leftLast, int rightFirst, int rightLast) {
  ItemType *tempArray = new ItemType[length];
  int index = leftFirst;
  int saveFirst = leftFirst;
  //Compare and merge items
  while((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
    if(values[leftFirst].compareTo(values[rightFirst]) == Comparison::LESS) {
      tempArray[index] = values[leftFirst];
      leftFirst++;
    } else {
      tempArray[index] = values[rightFirst];
      rightFirst++;
    }
    index++;
    comparisons++;
  }
  while(leftFirst <= leftLast) {
    //copy remaining items from left
    tempArray[index] = values[leftFirst];
    leftFirst++;
    index++;
  }
  while(rightFirst <= rightLast) {
    //copy remaining items from right
    tempArray[index] = values[rightFirst];
    rightFirst++;
    index++;
  }
  for(index = saveFirst; index <= rightLast; index++) {
    //copy temp array to actual array
    values[index] = tempArray[index];
  }
  delete[] tempArray;
}

/* Heap Sort
 */
void Sorting::heapSort(ItemType *values) {
  int index;
  //convert array into a heap
  for(index = length/2 - 1; index >= 0; index--) {
    reheapDown(values, index, length - 1);
  }
  //sort the array
  for(index = length - 1; index >= 1; index--) {
    //swap
    ItemType temp;
    temp.initialize(values[0].getValue());
    values[0] = values[index];
    values[index] = temp;
    //reheap
    reheapDown(values, 0, index - 1);
  }
}

/* Reheap Down
   Used in heap sort
 */
void Sorting::reheapDown(ItemType *values, int root, int bottom) {
  int maxChild;
  int rightChild = root * 2 + 2;
  int leftChild = root * 2 + 1;
  if (leftChild <= bottom) {
    if(leftChild == bottom) {
      maxChild = leftChild;
    } else {
      if((values[leftChild].compareTo(values[rightChild]) == Comparison::LESS) ||
	(values[leftChild].compareTo(values[rightChild]) == Comparison::EQUAL)) {
	maxChild = rightChild;
      } else {
	maxChild = leftChild;
      }
    }
    
    if(values[root].compareTo(values[maxChild]) == Comparison::LESS) {
      //swap
      ItemType temp;
      temp.initialize(values[root].getValue());
      values[root] = values[maxChild];
      values[maxChild] = temp;

      reheapDown(values, maxChild, bottom);
    }
    comparisons++;
  }


}

/* Quick Sort using first value
 */
void Sorting::quickSortFirst(ItemType *values, int first, int last) {
  if(first < last) {
    int splitPoint = split(values, first, last, first); //first is used as split point
    quickSortFirst(values, first, splitPoint - 1);
    quickSortFirst(values, splitPoint + 1, last);
  }
}

/* Quick Sort using random value
 */
void Sorting::quickSortRandom(ItemType *values, int first, int last) {
  if(first < last) {
    int random = (rand() % (last - first)) + first; //random used as split point
    int splitPoint = split(values, first, last, random);
    quickSortRandom(values, first, splitPoint - 1);
    quickSortRandom(values, splitPoint + 1, last);
  }
}

/* Split
   Used in Quick Sort (First and Random)
 */
int Sorting::split(ItemType *values, int first, int last, int splitPoint) {
  int fromFirst = 0; 
  int fromLast = 0;
  ItemType *tempArray = new ItemType[length];
  //Place values in temp array
  for(int i = first; i <= last; i++) {
    if (values[i].compareTo(values[splitPoint]) == Comparison::LESS) {
      tempArray[first + fromFirst] = values[i];
      fromFirst++;
    } 
    if (values[i].compareTo(values[splitPoint]) == Comparison::GREATER) {
      tempArray[last - fromLast] = values[i];
      fromLast++;
    }
    comparisons++;
  }
  //determine split point
  tempArray[first + fromFirst] = values[splitPoint];
  splitPoint = first + fromFirst;
  //copy temp array to values
  for(int i = first; i <= last; i++) {
    values[i] = tempArray[i];
  }
  delete[] tempArray;
  return splitPoint;
}



