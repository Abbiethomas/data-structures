#include "BinaryTree.h"
#include "ItemType.h"
#include <iostream>

using namespace std;

//constructor
BinaryTree::BinaryTree() {

}

//delete recursive
void BinaryTree::deleteRecursive(Node *tree) {
  if (tree !=NULL) {
    deleteRecursive(tree->left);
    deleteRecursive(tree->right);
    delete tree;
  }
}

//deconstructor
BinaryTree::~BinaryTree() {
  deleteRecursive(root);
}


//insert
void BinaryTree::insert(ItemType key) {
  insertNode(root, key);
}

//insertNode 
void BinaryTree::insertNode(Node *&tree, ItemType item) {
  if(tree == NULL) { 
    tree = new Node;
    tree->key = item;
  } else if (item.compareTo(tree->key) == Comparison::GREATER) {
    insertNode(tree->right, item);
  } else if (item.compareTo(tree->key) == Comparison::LESS) {
    insertNode(tree->left, item);
  } else { //if item is found in tree
    cout << "Item already in tree" << endl;
  }
}

//delete
void BinaryTree::deleteItem(ItemType key) {
  bool found = false;
  Node *tempNode = root;
  find(tempNode, key, found);
  if (found == false) {
    cout << "Item not in tree." << endl;
  } else {
    deleteNode(tempNode);
  } 
}

/*finds node to be deleted
void BinaryTree::findNode(Node *tree, ItemType item, bool &found) {
  if (tree == NULL) { //item not found
    found = false;
  } else if (item.compareTo(tree->key) == Comparison::GREATER) {
    findNode(tree->right, item, found);
  } else if (item.compareTo(tree->key) == Comparison::LESS) {
    findNode(tree->left, item, found);
  } else { //found
    found = true;
    deleteNode(tree);
  }
  }*/

//deletes node
void BinaryTree::deleteNode(Node *&tree) {
  //  Node *tempPtr = tree;
  ItemType item;
  if (tree->left == NULL && tree->right == NULL) {
    item = tree->key;
    deleteLeaf(root, item);
  } else if (tree->left == NULL) {
    *tree = *tree->right;
    //delete tempPtr;
  } else if (tree->right == NULL) {
    *tree = *tree->left;
    //delete tempPtr;
  } else  {
    getPredecessor(tree->right, item);
    deleteItem(item);
    tree->key = item;
    //bool found = false;
    //findNode(tree->right, item, found);
  }
}

//delete leaf node
void BinaryTree::deleteLeaf(Node *tree, ItemType item) {
  if(item.compareTo(tree->right->key) == Comparison::EQUAL) {
    tree->right = NULL;
  } else if (item.compareTo(tree->left->key) == Comparison::EQUAL) {
    tree->left = NULL;
  } else if (item.compareTo(tree->key) == Comparison::GREATER) {
    deleteLeaf(tree->right, item);
  } else if (item.compareTo(tree->key) == Comparison::LESS) {
    deleteLeaf(tree->left, item);
  }
}

//get predecessor
void BinaryTree::getPredecessor(Node *tree, ItemType &item) {
  while (tree->right != NULL) {
    tree = tree->right;
  }
  item = tree->key;
}

//get Item
void BinaryTree::retrieve(ItemType &item, bool &found) const {
  getItem(root, item, found);
}

//get Item
void BinaryTree::getItem(Node *tree, ItemType &item, bool &found) const {
  if (tree == NULL) { //not found
    found = false;
  } else if (item.compareTo(tree->key) == Comparison::GREATER) {
    getItem(tree->right, item, found);
  } else if (item.compareTo(tree->key) == Comparison::LESS) {
    getItem(tree->left, item, found);
  } else { //found
    item = tree->key;
    found = true;
  }
}

//preOrder
void BinaryTree::preOrder() const {
  printPre(root);
  cout << endl;
}

//print PreOrder
void BinaryTree::printPre(Node *tree) const {
  if (tree != NULL) {
    cout << tree->key.getValue() << " ";
    printPre(tree->left);
    printPre(tree->right);
  }
}

//inOrder
void BinaryTree::inOrder() const {
  printIn(root);
  cout << endl;
}

//print in order
void BinaryTree::printIn(Node *tree) const {
  if (tree != NULL) {
    printIn(tree->left);
    cout << tree->key.getValue() << " ";
    printIn(tree->right);
  }
}

//postOrder
void BinaryTree::postOrder() const {
  printPost(root);
  cout << endl;
}

//print post order
void BinaryTree::printPost(Node *tree) const {
  if (tree != NULL) {
    printPost(tree->left);
    printPost(tree->right);
    cout << tree->key.getValue() << " ";
  }
}

//length
int BinaryTree::getLength() const {
  return countNodes(root);
}

//count nodes
int BinaryTree::countNodes(Node *tree) const {
  if(tree == NULL) {
    return 0;
  } else {
    return (countNodes(tree->left) +
	    countNodes(tree->right) + 1);
  }
} 

//get number of single parents
int BinaryTree::getNumSingleParent() const {
  int total = 0;
  isSingle(root, total);
  return total;
}

//checks if node is single
void BinaryTree::isSingle(Node *tree, int &total)  const{
  if (tree != NULL) {
    if ((tree->left == NULL && tree->right != NULL) ||
	(tree->right == NULL && tree->left !=NULL)) {
      total++;
    }
    isSingle(tree->left, total);
    isSingle(tree->right, total);
  }
}

//get number of leaf nodes 
int BinaryTree::getNumLeafNodes() const {
  int leaf = 0;
  isLeaf(root, leaf);
  return leaf;
}

//checks if node is a leaf
void BinaryTree::isLeaf(Node *tree, int &leaf) const {
  if (tree != NULL) {
    if (tree->left == NULL && tree->right == NULL) {
      leaf++;
    }
    isLeaf(tree->left, leaf);
    isLeaf(tree->right, leaf);
  }
}

//get sum of values in subtree
int BinaryTree::getSumOfSubtrees(ItemType item) {
  int sum = 0;
  Node *tempNode = root;
  bool found = false;
  find(tempNode, item, found);
  if(found) {
    sumSub(tempNode->right, sum);
    sumSub(tempNode->left, sum);
  } else {
    sum = -1;
  }

  return sum;
}

//find
void BinaryTree::find(Node *&tree, ItemType item, bool &found) {
  if(tree == NULL) {
    found = false;
  } else if (item.compareTo(tree->key) == Comparison::GREATER) {
    tree = tree->right;
    find(tree, item, found);
  } else if (item.compareTo(tree->key) == Comparison::LESS) {
    tree = tree->left;
    find(tree, item, found);
  } else { //equal
    found = true;
  }
}

//recursive function to sum up subtrees
void BinaryTree::sumSub(Node *tree, int &sum) {
  if (tree != NULL) {
    sumSub(tree->right, sum);
    sumSub(tree->left, sum);
    sum += tree->key.getValue();
  }
}
