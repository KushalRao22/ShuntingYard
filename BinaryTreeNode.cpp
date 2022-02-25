#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode::BinaryTreeNode(char valueIn){
  value = valueIn;
  left = NULL;
  right = NULL;
}

BinaryTreeNode* BinaryTreeNode::getLeft(){
  return left;
}

void BinaryTreeNode::setLeft(BinaryTreeNode* newNode){
  left = newNode;
}

BinaryTreeNode* BinaryTreeNode::getRight(){
  return right;
}

void BinaryTreeNode::setRight(BinaryTreeNode* newNode){
  right = newNode;
}

char BinaryTreeNode::getValue(){
  return value;
}

void BinaryTreeNode::setValue(char valueIn){
  value = valueIn;
}
