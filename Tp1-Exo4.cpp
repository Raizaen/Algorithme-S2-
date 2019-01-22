#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

const int buffer = 1024;
using tab = array<int,buffer>;

void  gen_tab (tab &t,int n, int min, int max) {
  if (n==0) return;
  else {
    t[n-1] = rand()%(max-min)+min;
    return gen_tab(t, n-1, min, max);
  }
}

void affich (tab t, int n) {
  if (n >= 0) {
    cout << t[n] << ' ';
    return affich (t, n-1);
  }
}



int main () {
  srand(time(NULL));
  tab t;
  gen_tab(t,20,5,25);
  affich(t,20);
}
