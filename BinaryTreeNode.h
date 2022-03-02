/*
This is the .h file for the node that has a left and right pointer
Last Modified: 3/2/22
By: Kushal Rao
*/
//Imports
#include <iostream>

using namespace std;

class BinaryTreeNode{
 public:
 //Methods
  BinaryTreeNode(char valueIn);
  BinaryTreeNode* getLeft();
  void setLeft(BinaryTreeNode* newNode);
  BinaryTreeNode* getRight();
  void setRight(BinaryTreeNode* newNode);
  char getValue();
 //Variables
  char value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  BinaryTreeNode* next;
};
