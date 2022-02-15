#include <iostream>
#include <cstring>

using namespace std;

struct Node{//Create a student struct
  char value;
  struct Node *prev;
  struct Node *next;
};

Node* stackHead = NULL;
Node* queueHead = NULL;
Node* queueEnd = NULL;

void push(Node* newNode);
void enqueue(Node* newNode);
void printQueue();
void pop(Node* &current);
void dequeue(Node* &current);
void printStack();
char peep();

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
  
  printStack();

  printQueue();

  return 0;
}

void push(Node* newNode){
  newNode->next = stackHead;
  stackHead = newNode;
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

void pop(Node* &current){
  current = stackHead;
  stackHead = stackHead->next;
}

void dequeue(Node* &current){
  current = queueHead;
  if(queueHead->next != NULL){
    queueHead = queueHead->next;
  }
}

char peep(){
  return stackHead->value;
}
