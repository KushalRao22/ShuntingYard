#include <iostream>

using namespace std;

class BinaryTreeNode{
 public:
  BinaryTreeNode();
  BinaryTreeNode* getLeft();
  void setLeft(BinaryTreeNode* newNode);
  BinaryTreeNode* getRight();
  void setRight(BinaryTreeNode* newNode);
  char getValue();
  void setValue(char value);
 private:
  char value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};
