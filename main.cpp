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
    Node* newNode = new Node;
    newNode->value = temp;
    cout << "HERE" << endl;
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^' || temp == ')'){
      newNode->next = stackHead;
      stackHead = newNode;
    }
    else{
      cout << "Here1" << endl;
      if(queueHead == NULL){
	cout << "Here2" << endl;
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
