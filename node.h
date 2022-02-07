#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>


using namespace std;

class Node{
 public:
  Node(char newChar);
  ~Node();
  void setNext(Node* newNext);
  Node* getNext();

 private:
  Student* value;
  Node* next;
};
#endif