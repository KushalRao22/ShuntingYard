#include "node.h"
#include <iostream>
#include <cstring>


using namespace std;

Node::Node(char newChar) {
  value = newChar;
  next = NULL;
}

Node::~Node() {
  next = NULL;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
