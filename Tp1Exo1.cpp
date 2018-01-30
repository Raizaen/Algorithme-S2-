#include <iostream>

using namespace std;

struct fraction {
  int num;
  int den;
};

void saisie (fraction& a) {
    cout << "Entrez le numérateur de la fraction : ";
    cin >> a.num;
    cout << "Entrer le denominateur de la fraction :";
    cin >> a.den;
    cout << endl;
}

void affich (fraction a) {
  cout << "votre fraction est : " << a.num << "/" << a.den << endl;
} 

void affichadd (fraction a) {
  cout << "votre addition est : " << a.num << "/" << a.den << endl;
} 

void affichsoustr (fraction a) {
  cout << "votre soustraction est : " << a.num << "/" << a.den << endl;
} 

void affichmult (fraction a) {
  cout << "votre multiplication est : " << a.num << "/" << a.den << endl;
} 

void affichdiv (fraction a) {
  cout << "votre division est : " << a.num << "/" << a.den << endl;
} 

void affichopp (fraction a) {
  cout << "l'opposé de Votre fraction est : " << a.num << "/" << a.den << endl;
}  

void affichinv (fraction a) {
  cout << "l'inverse de Votre fraction est : " << a.num << "/" << a.den << endl;
}  

void affichsimpl (fraction a) {
  cout << "la simplification de Votre fraction est : " << a.num << "/" << a.den << endl;
}  

fraction add (fraction a, fraction b) {
  fraction res;
  res.num = ((a.num * b.den)+(b.num * a.den));
  res.den = a.den * b.den;
  return res;
  }

fraction soustr (fraction a, fraction b) {
  fraction res;
  res.num = ((a.num * b.den)-(b.num * a.den));
  res.den = a.den * b.den;
  return res;
}

fraction mult (fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.num;
  res.den = a.den * b.den;
  return res;
}

fraction inv (fraction a) {
  fraction res;
  res.num = a.den;
  res.den = a.num;
  return res;
}

fraction div (fraction a, fraction b) {
  fraction res;
  res.num = a.num * b.den;
  res.den = a.den * b.num;
  return res;
}

fraction opp (fraction a) {
  fraction res;
  res.num = (a.num * -1);
  res.den = (a.den * -1);
  return res;
}

int pgcd (int a , int b ) {
  int n = 0;
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  if ((n = a%b) == 0) { 
    return b;
  } 
  else { 
      return pgcd(b, n);
    }
}

fraction simpl (fraction a) {
  fraction res;
  int n;
  n = pgcd(a.num, a.den);
  res.num = a.num/n;
  res.den = a.den/n;
  if (a.den<0) {
    a.num = (-1 * a.num);
    a.den = (-1 * a.den);
  }
  return res;
}

int main () {
  fraction A,B;
  int a=0, b=0;
  
  saisie(A);
  saisie(B);
  affich(A);
  affich(B);
  affichadd(add(A,B));
  affichsoustr(soustr(A,B));
  affichmult(mult(A,B));
  affichdiv(div(A,B));
  affichopp(opp(A));
  affichopp(opp(B));
  affichinv(inv(A));
  affichinv(inv(B));
  cout << endl;
  cout << "Entrez deux entiers : ";
  cin >> a >> b;
  cout << "Le PGCD de vos deux entiers est : " << pgcd(a,b) << endl;
  
  affichsimpl(simpl(mult(A,B)));
  return 0;
}