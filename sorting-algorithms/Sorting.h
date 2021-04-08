//Sorting.h
#ifndef SORTING_H
#define SORTING_H
#include "ItemType.h"

class Sorting {
 public:
  Sorting(int len);
  long getComparisons();
  void selectionSort(ItemType* values);
  int minIndex(ItemType values[], int start, int end);
  void mergeSort(ItemType *values, int first, int last);
  void merge(ItemType *values, int leftFirst, int leftLast, int rightFirst, int rightLast);
  void heapSort(ItemType *values);
  void reheapDown(ItemType *values, int root, int bottom);
  void quickSortFirst(ItemType *values, int first, int last);
  void quickSortRandom(ItemType *values, int first, int last);
  int split(ItemType *values, int first, int last, int splitPoint);
 private:
  long comparisons = 0;
  int length;
};

#endif
