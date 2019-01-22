#include <iostream>

using namespace std;

int Fibonacci(int n) {
  if(n==0) return 0;
  else if (n==1) return 1;
  else return Fibonacci(n-1)+Fibonacci(n-2);
}

int Fibonacci2(int n) {
  int i = 0;
  int j = 1;
  int temp;
    for (int k =0; k < n; k++) {
      temp = i + j;
      i = j;
      j = temp;
      
    }
  return i;
}

int main () {
  
  cout << Fibonacci(40) << std::endl;
  cout << Fibonacci2(40) << endl;
  return 0;
}
