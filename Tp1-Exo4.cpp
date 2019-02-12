#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <string>

using namespace std;

const int buffer = 1024;
using Tab = array<int,buffer>;

//a

void  gen_Tab_aleat (Tab &t,int n, int min, int max) {
  if (n==0) return;
  else {
    t[n-1] = rand()%(max-min)+min;
    return gen_Tab_aleat(t, n-1, min, max);
  }
}

//b

void affich (Tab t, int n) {
  if (n >= 0) {
    cout << t[n] << ' ';
    return affich (t, n-1);
  }
}

//c
/*
int l (Tab t) {
    int p = 0;
      while (t[p]!=0) {
        p++;
      }
      return p;
      
}
*/

int indexof (Tab &t, int n, int p, int cmpt) {
  if (cmpt==n) {
    return cmpt;
  }
  if (t[cmpt] == p) {
    return n-cmpt;
  }
  else {
    return indexof (t, n, p, cmpt+1);
  }
  
}
// Absolument pas ce qu'il faut faire :/
/*
void separate (Tab t, int n, Tab &t1, Tab &t2, int idxmid, int nT1, int cmpt, int cmpt1) {
  if (n==0) {
    return;
  }
  if (cmpt == n) {
    return;
  }
  if (cmpt <= nT1) {
    t1[cmpt] = t[cmpt];
    return separate (t, n, t1, t2, idxmid, nT1, cmpt+1,cmpt1);
  }
  if (cmpt > nT1 && cmpt < n) {
    t2[cmpt1] = t[cmpt];
    return separate (t, n, t1, t2, idxmid, nT1, cmpt+1,cmpt1+1); 
  }
  
}
*/

// d


int main () {
  srand(time(NULL));
  
  Tab t, t1, t2;
  int n, min, max, p, cmptidx=0, cmptsep=0, cmptsep1=0;
  
  cout << "Choisir le nombre de valeur à générer dans le Tableau : " << endl;
  cin >> n;
  cout << endl;
  cout << "Choisir la valeur minimale et maximale du rand : " << endl;
  cin >> min >> max;
  cout << endl;
  
  gen_Tab_aleat(t,n,min,max);
  affich(t,(n-1));
  cout  << endl;
  
  cout << "Choisir le nombre pour lequel le tableau sera coupé : " << endl;
  cin >> p;
  
  int idxmid = indexof(t, n, p, cmptidx);
  cout << indexof(t, n, p, cmptidx) << endl;
  
  int nT1 = n - idxmid;
  int nT2 = n-nT1-2;
  separate(t, n, t1, t2, idxmid, nT1, cmptsep, cmptsep1);
  affich(t2,nT2);
  cout << endl;
  affich(t1,nT1);
  cout << endl;
  
  return 0;
}