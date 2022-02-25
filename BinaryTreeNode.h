#include <iostream>

using namespace std;

class BinaryTreeNode{
 public:
  BinaryTreeNode(char valueIn);
  BinaryTreeNode* getLeft();
  void setLeft(BinaryTreeNode* newNode);
  BinaryTreeNode* getRight();
  void setRight(BinaryTreeNode* newNode);
  char getValue();
  void setValue(char value);
  char value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  BinaryTreeNode* next;
};
