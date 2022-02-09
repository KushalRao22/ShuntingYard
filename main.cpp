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

void push(char value);
void enqueue(char value);

int main(){
  char input[256];
  cin.get(input, 256);
  char infix[256];
  for(int i = 0; i < strlen(input); i++){
    if(i%2 == 0){
      infix[i/2] = input[i];
    }
  }
  for(int i = 0; i < strlen(infix); i++){
    char temp = infix[i];
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == '('){
      push(temp);
    }
    else{
      enqueue(temp);
    }
  }
  
  bool run = true;
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
  
  run = true;
  while(run){
    cout << queueHead->value;
    if(queueHead->next != NULL){
      queueHead = queueHead->next;
    }
    else{
      run = false;
    }
  }
  return 0;
}

void push(char value){
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = stackHead;
  stackHead = newNode;
}

void enqueue(char value){
  Node* newNode = new Node;
  newNode->value = value;
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
