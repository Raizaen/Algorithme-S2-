#include <iostream>
using namespace std;

//1
string subChain (string a, int i, int size) {
  if(size == 0) return "";
  return a[i]+subChain(a,i+1,size-1);
}

//2 Correct
bool palindrome (string a) {
  if(a.length()<=1) return 1;
  return (a[0]==a[a.length()-1]) && palindrome(subChain(a,1,a.length()-2));
}

//3
int occurance_lettre (string a, char b) {
  if(a.length()==0) return 0;
  return (a[0]==b) + occurance_lettre(subChain(a,1,a.length()-1),b);
}

int main () {
  std::string a;
  char b;
  cout << "Choisissez un mot" << endl;
  cin >> a;
  cout << "Choisissez une lettre" << endl;
  cin >> b;
  
  if (palindrome(a)==1) { 
    cout << a << " est un palindrome" << endl;
  }
  else {
    cout << a << " n'est pas un palindrome" << endl;
  }
  
  cout << "il y a " << occurance_lettre(a, b) << " occurence de " << b <<  endl;
  
  return 0;
}