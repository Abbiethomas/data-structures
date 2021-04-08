//BinaryTree.h
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "ItemType.h"

struct Node {
  ItemType key;
  Node *left = NULL;
  Node *right = NULL;
};

class BinaryTree {
 public:
  BinaryTree();
  ~BinaryTree();
  void deleteRecursive(Node *tree);
  void insert(ItemType key);
  void insertNode(Node *&tree, ItemType item);
  void deleteItem(ItemType key);
  void findNode(Node *tree, ItemType item, bool &found);
  void deleteLeaf(Node *tree, ItemType item);
  void deleteNode(Node *&tree);
  void getPredecessor(Node *tree, ItemType &item);
  void retrieve(ItemType &item, bool &found) const;
  void getItem(Node *tree, ItemType &item, bool &found) const;
  void preOrder() const;
  void printPre(Node *tree) const;
  void inOrder() const;
  void printIn(Node *tree) const;
  void postOrder() const;
  void printPost(Node *tree) const;
  int getLength() const;
  int countNodes(Node *tree) const;
  int getNumSingleParent() const;
  void isSingle(Node *tree, int &total) const;
  int getNumLeafNodes() const;
  void isLeaf(Node *tree, int &leaf) const;
  int getSumOfSubtrees(ItemType item);
  void find(Node *&tree, ItemType item, bool &found);
  void sumSub(Node* tree, int &sum);

 private:
  Node *root = NULL;

};

#endif
