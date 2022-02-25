#include <iostream>
#include <cstring>
#include "BinaryTreeNode.h"

using namespace std;

struct Node{//Create a student struct
  char value;
  struct Node *prev;
  struct Node *next;
};

Node* stackHead = NULL;
Node* queueHead = NULL;
Node* queueEnd = NULL;
BinaryTreeNode* BTStackHead = NULL;
BinaryTreeNode* treeHead = NULL;

void printTree();
void push(Node* newNode);
void enqueue(Node* newNode);
void printQueue();
void pop(Node* &current);
void dequeue(Node* &current);
void printStack();
char peep();
void makeTree();
void printBTStack();
void BTPush(BinaryTreeNode* newNode1);
void BTPop(Node* &current);

int main(){
  char input[256];
  cin.get(input, 256);
  char infix[256];
  for(int i = 0; i < strlen(input); i++){
    if(i%2 == 0){
      infix[i/2] = input[i];
    }
  }
  infix[strlen(input)/2 + 1] = '\0';
  for(int i = 0; i < strlen(infix); i++){
    char temp = infix[i];
    Node* newNode = new Node;
    newNode->value = temp;
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == '('){
      push(newNode);
    }
    else if(temp == ')'){
      Node* nodeTemp;
      bool run = true;
      while(run){
	if(peep() != '('){
	  pop(nodeTemp);
	  enqueue(nodeTemp);
	}
	else{
	  pop(nodeTemp);
	  run = false;
	}
      }
    }
    else{
      enqueue(newNode);
    }
  }
  bool run = true;
  Node* nodeTemp;
  while(run){
    if(stackHead != NULL){
      pop(nodeTemp);
      enqueue(nodeTemp);
    }
    else{
      run = false;
    }
  }
  printQueue();

  makeTree();

  printTree();
  cout << "end" << endl;
  return 0;
}

void printTree(){
  bool run = true;
  BinaryTreeNode* current = treeHead;
  while(run){
    cout << "Here" << endl;
    cout << current->value << endl;
    if(current->left  == NULL){
      run = false;
    }
    else{
      cout << "Left: " << current->getLeft()->value << "Right: " << current->getRight()->value << endl;
      current = current->getRight();
    }


  }


}

void push(Node* newNode){
  newNode->next = stackHead;
  stackHead = newNode;
}

void pop(Node* &current){
  current = stackHead;
  stackHead = stackHead->next;
}


char peep(){
  return stackHead->value;
}

void BTpush(BinaryTreeNode* newNode1){
  newNode1->next = BTStackHead;
  BTStackHead = newNode1;
}

void BTPop(BinaryTreeNode* &current){
  current = BTStackHead;
  BTStackHead = BTStackHead->next;
}

void makeTree(){
  bool run = true;
  Node* current;
  while(run){
    if(queueHead->value != '+' && queueHead->value != '-' && queueHead->value != '*' && queueHead->value != '/' && queueHead->value != '^'){
      dequeue(current);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BTpush(BTcurrent);
    }
    else{
      dequeue(current);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BinaryTreeNode* point;
      BTPop(point);
      BTcurrent->setRight(point);
      BTPop(point);
      BTcurrent->setLeft(point);
      BTpush(BTcurrent);
      treeHead = BTcurrent;
    }
    if(queueHead == NULL){
      run = false;
    }
  }
}

void dequeue(Node* &current){
  current = queueHead;
  queueHead = queueHead->next;
}

void enqueue(Node* newNode){
  if(queueHead == NULL){
    newNode->prev = NULL;
    newNode->next = NULL;
    queueHead = newNode;
    queueEnd = newNode;
  }
  else{
    newNode->prev = queueEnd;
    queueEnd->next = newNode;
    newNode->next = NULL;
    queueEnd = newNode;
  } 
}

void printBTStack(){
  bool run = true;
  BinaryTreeNode* current = BTStackHead;
  if(current == NULL){
    run = false;
  }
  while(run){
    cout << current->value;
    if(current->right != NULL){
      current = current->right;
    }
    else{
      run = false;
    }
  }
  cout << endl;
}

void printQueue(){
  bool run = true;
  Node* current = queueHead;
  while(run){
    cout << current->value;
    if(current->next != NULL){
      current = current->next;
    }
    else{
      run = false;
    }
  }
  cout << endl;
}

void printStack(){
  bool run = true;
  if(stackHead == NULL){
    run = false;
  }
  while(run){
    cout << stackHead->value;
    if(stackHead->next != NULL){
      stackHead = stackHead->next;
    }
    else{
      run = false;
    }
  }
  cout << endl;
}
