#include <iostream>

using namespace std;

void Syracuse (int a) {
  cout << a << " "; 
  if(a==1) cout << "et c'est fini\n"; 
  else if(a%2) Syracuse(a*3+1); 
  else Syracuse(a/2);
}

int main () {
  int x;
  cout << "Entre un nombre" << endl;
  cin >> x;
  Syracuse(x);
}
