#include <iostream>
#include <cstring>

using namespace std;

int main(){
  char input[256];
  cin.get(input, 256);
  char rInput[256];
  for(int i = 0; i < strlen(input); i++){
    if(i%2 == 0){
      rInput[i/2] = input[i];
    }
  }
  //  rInput[strlen(rInput) + 1] = "\0";
  cout << rInput << endl;
  cout << input << endl;
  return 0;
}
