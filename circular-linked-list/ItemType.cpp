//ItemType.cpp
#include "ItemType.h"
#include <iostream>
using namespace std;

//constructor
ItemType::ItemType() {

}

/*print. Question: when the empty constructor is called,
  what value do int member variables take on? NULL? 0? 
 */
void ItemType::print() {
  cout << value << " ";
}

//initialize
void ItemType::initialize(int number) {
  value = number;
}

/*compareTo returns GREATER if the calling object is
  greater than the argument passed. Returns LESS if the 
  calling object is less than the argument passed and EQUAL
  if they are the same
 */
Comparison ItemType:: compareTo(ItemType item) {
  if(value > item.getValue()) {
    return Comparison::GREATER;
  } else if (value < item.getValue()) {
    return Comparison::LESS;
  } else {
    return Comparison::EQUAL;
  }
}

//getValue
int ItemType::getValue() const {
  return value;
}
