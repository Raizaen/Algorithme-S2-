#include <iostream>

 using namespace std;


void Syracuse (int n) {
  cout <<  n << ' ';
  if (n > 1)
  {
    if (n % 2 == 0) {
       Syracuse (n/2);
    }
    else {
      Syracuse (n*3 +1);
    }
  }
}
  
int main () {
  Syracuse(4589654);
  return 0;
}