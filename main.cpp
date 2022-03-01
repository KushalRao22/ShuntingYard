/*
This is Shunting yard with a binary tree to print infix, postfix and prefix

Last Modified: 3/1/22

By: Kushal Ro
*/
//Imports
#include <iostream>
#include <cstring>
#include "BinaryTreeNode.h"

using namespace std;

struct Node{//Create a student struct
  char value;
  struct Node *prev;
  struct Node *next;
};
//Methods
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
  //Create all important variables
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  Node* queueEnd = NULL;
  BinaryTreeNode* BTStackHead = NULL;
  BinaryTreeNode* treeHead = NULL;
  //Ask for a expression
  cout << "Input your expression" << endl;
  char input[256];
  cin.get(input, 256);
  char infix[256];
  //Remove all the spaces
  for(int i = 0; i < strlen(input); i++){
    if(i%2 == 0){
      infix[i/2] = input[i];
    }
  }
  infix[strlen(input)/2 + 1] = '\0';
  for(int i = 0; i < strlen(infix); i++){
    char temp = infix[i];
    Node* newNode = new Node;//Create Node for each character
    newNode->value = temp;
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == '('){//If current is a opperator it gets added to stack
      push(newNode, stackHead);
    }
    else if(temp == ')'){//If it is a right parentessis go remove from stack into queue until a left parenthesis is on top of stack
      Node* nodeTemp;
      bool run = true;
      while(run){
	if(peep(stackHead) != '('){
	  pop(nodeTemp, stackHead);
	  enqueue(nodeTemp, queueHead, queueEnd);
	}
	else
	  pop(nodeTemp, stackHead);
	  run = false;
	}
      }
    }
  else{//Other wise add it to queue
      enqueue(newNode, queueHead, queueEnd);
    }
  }
  bool run = true;
  Node* nodeTemp;
  while(run){//While stack is not empty remove into queue
    if(stackHead != NULL){
      pop(nodeTemp, stackHead);
      enqueue(nodeTemp, queueHead, queueEnd);
    }
    else{
      run = false;
    }
  }
  makeTree(queueHead, queueEnd, treeHead, BTStackHead);//Make the tree
  cout << "What do you want print? Infix/Postfix/Prefix" << endl;
  cin.clear();
  cin >> input;
  if(strcmp(input, "prefix") == 0){
    pre(treeHead);//print prefix
  }
  if(strcmp(input, "postfix") == 0){
    pos(treeHead);//print postfix
  }
  if(strcmp(input, "infix") == 0){
    inf(treeHead);//print prefix
  }
  return 0;
}


void pre(BinaryTreeNode* current){//Print prefix reccursively
  cout << current->value;
  if(current->left != NULL) {
    pre(current->left);
  }
  if(current->right != NULL) {
    pre(current->right);
  }
}

void pos(BinaryTreeNode* current){//Print postfix reccursively
  if(current->left != NULL) {
    pos(current->left);
  }
  if (current->right != NULL) {
    pos(current->right);
  }
  cout << current->value;
}

void inf(BinaryTreeNode* current){//Print infix reccursively
  if(current->left != NULL) {
    inf(current->left);
  }
  cout << current->value;
  if(current->right != NULL) {
    inf(current->right);
  }
}

void push(Node* newNode, Node* &stackHead){//Add new node to stack
  newNode->next = stackHead;
  stackHead = newNode;
}

void pop(Node* &current, Node* &stackHead){//Remove the top most node of the stack
  current = stackHead;
  stackHead = stackHead->next;
}

char peep(Node* &stackHead){//Check value of the top most node on the stack
  return stackHead->value;
}

void BTpush(BinaryTreeNode* &newNode1, BinaryTreeNode* &BTStackHead){//Push a binary tree node onto the binary tree stack
  newNode1->next = BTStackHead;
  BTStackHead = newNode1;
}

void BTPop(BinaryTreeNode* &current, BinaryTreeNode* &BTStackHead){//Remove the top most binary tree node on the stack
  current = BTStackHead;
  BTStackHead = BTStackHead->next;
}

void makeTree(Node* &queueHead, Node* &queueEnd, BinaryTreeNode* &treeHead, BinaryTreeNode* &BTStackHead){//Build the Binary tree
  bool run = true;
  Node* current;
  while(run){//While there is stuff in queue
    if(queueHead->value != '+' && queueHead->value != '-' && queueHead->value != '*' && queueHead->value != '/' && queueHead->value != '^'){
      //remove the next thing in queue and add it to binary stack
      dequeue(current, queueHead, queueEnd);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BTpush(BTcurrent, BTStackHead);
    }
    else{//If it is a opperator
      //Set the opperator to point to the two newest nodes in the binary tree stack
      dequeue(current, queueHead, queueEnd);
      BinaryTreeNode* BTcurrent = new BinaryTreeNode(current->value);
      BinaryTreeNode* point;
      BTPop(point, BTStackHead);
      BTcurrent->setRight(point);
      BTPop(point, BTStackHead);
      BTcurrent->setLeft(point);
      BTpush(BTcurrent, BTStackHead);
      //Treehead is the new opperator
      treeHead = BTcurrent;
    }
    if(queueHead == NULL){
      //Stop the while loop
      run = false;
    }
  }
}

void dequeue(Node* &current, Node* &queueHead, Node* &queueEnd){//Remove from the queue
  current = queueHead;
  queueHead = queueHead->next;
}

void enqueue(Node* newNode, Node* &queueHead, Node* &queueEnd){//Add new node to the queue
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
