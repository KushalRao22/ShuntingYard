#include <iostream>
#include <cstring>

using namespace std;

Node* stackHead = NULL;

int main(){
  char input[256];
  cin.get(input, 256);
  char rInput[256];
  for(int i = 0; i < strlen(input); i++){
    if(i%2 == 0){
      rInput[i/2] = input[i];
    }
  }
  return 0;
}
