#include <iostream>

using namespace std;
void hello (int n, std::string a) {
  if(n>0){
    cout << a << "\n";
    hello(n-1, a);
  }
}

int sum_squares_upto (int a) {
  if(a==1) return 1;
  return a*a + sum_squares_upto(a-1);
}

int main () {
  int x;
  std::string a;
  cout << "Entre un mots" << endl;
  cin >> a;
  cout << "Entre un nombre" << endl;
  cin >> x;
  hello(x,a);
  cout << endl;
  cout << sum_squares_upto(x) << endl;
}