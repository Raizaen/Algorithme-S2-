#include <iostream>

using namespace std;

void repet (int n, string mot ) {
  if (n > 0) {
    cout << mot << endl;
    repet (n-1, mot);
  }
}

int carre (int n) {
  if (n > 0) {
    return carre (n-1) + n*n;
  }
  else {
    return 0;
  }
}

int main () {
  std::string test = "bonjour";
  repet(4, test);
  cout << carre(5) << endl;
  return 0;
}