#include <iostream>

using namespace std;

struct fraction {
  int num;
  int den;
};

void saisie (fraction& a) {
  /*int n;
  cout << "Nombre de fraction désiré ? :";
  cin >> n;
  for (int  i=0; i <= n; i++) {*/
    cout << "Entrez le numérateur de la fraction : ";
    cin >> a.num;
    cout << "Entrer le denominateur de la fraction :";
    cin >> a.den;
    cout << endl;
  //}
}

void affichage (fraction a) {
  cout << "votre fraction est : " << a.num << "/" << a.den << endl;
} 

void affichagemult (fraction a) {
  cout << "votre multiplication est : " << a.num << "/" << a.den << endl;
} 

void affichageadd (fraction a) {
  cout << "votre addition est : " << a.num << "/" << a.den << endl;
} 

fraction mult (fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.num;
  res.den = a.den * b.den;
  return res;
  //cout << a.num << "/" << a.den << "*" << b.num << "/" << b.den << " = " << num << "/" << den << endl;
}

fraction add (fraction a, fraction b) {
  fraction res;
 /* int numA = a.num * b.den;
  int numB = b.num * a.den;
  int num = (numA + numB);
  int den = a.den * b.den;*/
  res.num = ((a.num * b.den)+(b.num * a.den));
  res.den = a.den * b.den;
  return res;
  //cout << a.num << "/" << a.den << "+" << b.num << "/" << b.den << " = " << num << "/" << den << endl;
}

fraction soustr (fraction a, fraction b) {
  fraction res;
  /*int numA = a.num * b.den;
  int numB = b.num * a.den;
  int num = (numA - numB);
  int den = a.den * b.den;*/
  res.num = ((a.num * b.den)-(b.num * a.den));
  res.den = a.den * b.den;
  return res;
  //cout << a.num << "/" << a.den << "-" << b.num << "/" << b.den << " = " << num << "/" << den << endl;
}

/*fraction opp (fraction a) {
    
}

fraction inv (fraction a) {
  int numA = a.den
  int denA = a.num
  
}
*/
int main () {
  fraction A,B,somme;
  saisie(A);
  saisie(B);
  affichage(A);
  affichage(B);
  //mult(A,B);
  somme = add(A,B);
  affichageadd(somme);
  affichagemult(mult(A,B));
  soustr(A,B);
}