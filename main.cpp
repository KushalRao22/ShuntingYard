#include <iostream>
#include <cstring>
#include "BinaryTreeNode.h"

using namespace std;

struct Node{//Create a student struct
  char value;
  struct Node *prev;
  struct Node *next;
};

void push(Node* newNode, Node* &stackHead);
void enqueue(Node* newNode, Node* &queueHead, Node* &queueEnd);
void pop(Node* &current, Node* &stackHead);
void dequeue(Node* &current, Node* &queueHead, Node* &queueEnd);
char peep(Node* &stackHead);
void makeTree(Node* &queueHead, Node* &queueEnd, BinaryTreeNode* &treeHead, BinaryTreeNode* &BTStackHead);
void BTPush(BinaryTreeNode* newNode1, BinaryTreeNode* &BTStackHead);
void BTPop(Node* &current, BinaryTreeNode* &BTStackHead);
void pre(BinaryTreeNode* current);
void pos(BinaryTreeNode* current);
void inf(BinaryTreeNode* current);

int main(){
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  Node* queueEnd = NULL;
  BinaryTreeNode* BTStackHead = NULL;
  BinaryTreeNode* treeHead = NULL;
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
      push(newNode, stackHead);
    }
    else if(temp == ')'){
      Node* nodeTemp;
      bool run = true;
      while(run){
	if(peep(stackHead) != '('){
	  pop(nodeTemp, stackHead);
	  enqueue(nodeTemp, queueHead, queueEnd);
	}
	else{
	  pop(nodeTemp, stackHead);
	  run = false;
	}
      }
    }
    else{
      enqueue(newNode, queueHead, queueEnd);
    }
  }
  bool run = true;
  Node* nodeTemp;
  while(run){
    if(stackHead != NULL){
      pop(nodeTemp, stackHead);
      enqueue(nodeTemp, queueHead, queueEnd);
    }
    else{
      run = false;
    }
  }
  makeTree(queueHead, queueEnd, treeHead, BTStackHead);
  cout << "What do you want print? Infix/Postfix/Prefix" << endl;
  cin.clear();
  cin >> input;
  if(strcmp(input, "pre") == 0){
    pre(treeHead);
  }
  if(strcmp(input, "pos") == 0){
    pos(treeHead);
  }
  if(strcmp(input, "inf") == 0){
    inf(treeHead);
  }
  return 0;
}


void pre(BinaryTreeNode* current){
  cout << current->value;
  if(current->left != NULL) {
    pre(current->left);//Recurcive call
  }
  if(current->right != NULL) {
    pre(current->right);//Recurcive call
  }
}

void pos(BinaryTreeNode* current){
  if(current->left != NULL) {
    pos(current->left);//Recurcive call
  }
  if (current->right != NULL) {
    pos(current->right);//Recurcive call
  }
  cout << current->value;
}

void inf(BinaryTreeNode* current){
  if(current->left != NULL) {
    inf(current->left);//Recurcive call
  }
  cout << current->value;
  if(current->right != NULL) {
    inf(current->right);//Recurcive call
  }
}

void push(Node* newNode, Node* &stackHead){
  newNode->next = stackHead;
  stackHead = newNode;
}

void pop(Node* &current, Node* &stackHead){
  current = stackHead;
  stackHead = stackHead->next;
}

char peep(Node* &stackHead){
  return stackHead->value;
}

void BTpush(BinaryTreeNode* &newNode1, BinaryTreeNode* &BTStackHead){
  newNode1->next = BTStackHead;
  BTStackHead = newNode1;
}

void BTPop(BinaryTreeNode* &current, BinaryTreeNode* &BTStackHead){
  current = BTStackHead;
  BTStackHead = BTStackHead->next;
}

void makeTree(Node* &queueHead, Node* &queueEnd, BinaryTreeNode* &treeHead, BinaryTreeNode* &BTStackHead){
  bool run = true;
  Node* current;
  while(run){
    if(queueHead->value != '+' && queueHead->value != '-' && queueHead->value != '*' && queueHead->value != '/' && queueHead->value != '^'){
      dequeue(current, queueHead, queueEnd);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BTpush(BTcurrent, BTStackHead);
    }
    else{
      dequeue(current, queueHead, queueEnd);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BinaryTreeNode* point;
      BTPop(point, BTStackHead);
      BTcurrent->setRight(point);
      BTPop(point, BTStackHead);
      BTcurrent->setLeft(point);
      BTpush(BTcurrent, BTStackHead);
      treeHead = BTcurrent;
    }
    if(queueHead == NULL){
      run = false;
    }
  }
}

void dequeue(Node* &current, Node* &queueHead, Node* &queueEnd){
  current = queueHead;
  queueHead = queueHead->next;
}

void enqueue(Node* newNode, Node* &queueHead, Node* &queueEnd){
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
