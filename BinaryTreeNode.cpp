/*
This is Node class with left and right pointers and holds a character 
Last Modified: 3/2/22
By: Kushal Ro
*/
//Imports
#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;
//Create node with value and set pointers to null
BinaryTreeNode::BinaryTreeNode(char valueIn){
  value = valueIn;
  left = NULL;
  right = NULL;
}
//Return left
BinaryTreeNode* BinaryTreeNode::getLeft(){
  return left;
}
//Set left
void BinaryTreeNode::setLeft(BinaryTreeNode* newNode){
  left = newNode;
}
//Return right
BinaryTreeNode* BinaryTreeNode::getRight(){
  return right;
}
//Set right
void BinaryTreeNode::setRight(BinaryTreeNode* newNode){
  right = newNode;
}
//Return value
char BinaryTreeNode::getValue(){
  return value;
}
