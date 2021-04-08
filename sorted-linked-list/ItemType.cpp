//ItemType.cpp
#include "ItemType.h"
using namespace std;

ItemType::ItemType() {
  
} //constructor

Comparison ItemType::compareTo(ItemType item) {
  if(item.getValue() > value) {
    return Comparison::GREATER;
  } else if(item.getValue() < value) {
    return Comparison::LESS;
  } else {
    return Comparison::EQUAL;
  }
} //compareTo

int ItemType::getValue() const {
  return value;
} //getValue

void ItemType::initialize(int num) {
  value = num;
} //initialize

