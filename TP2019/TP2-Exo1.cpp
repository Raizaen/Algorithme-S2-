#include <iostream>
#include <string>
#include <array>

using namespace std;

const int nMax = 32;

//------------------------------------------------------- DECLARATIONS DE TYPES

struct date_of_birth {
  int day, month, year;
};

struct person {
  string firstname, lastname;
  date_of_birth date;
  //person * suivant;
};

//using ensperson = person *;

using tabperson = array<person, nMax>;
using tabp = array<person*, nMax>;

struct ensperson {
  int n;
  tabperson a;
  
};

struct enspersonref {
  tabp ref_person;
  int nbr_person;

};

//------------------------------------------------------- AFFICHAGE

void affich (person p) {
  cout << "Nom : " << p.lastname << ", Prénom : " << p.firstname << ", Date de naissance : " << p.date.day << "/" << p.date.month << "/" << p.date.year << endl;
}

void affichfull (ensperson p, int n) {
  for(int i=0;i<n;i++){
    affich(p.a[i]);
  }
}
/*
void affichref (person* p) {
  cout << "Nom : " << p->lastname << ", Prénom : " << p->firstname << ", Date de naissance : " << p->date.day << "/" << p->date.month << "/" << p->date.year << endl;
}

void affichfullref (enspersonref p, int n) {
  for(int i=0;i<n;i++){
    affichref(p.ref_person[i]);
  }
}
*/

//------------------------------------------------------- SAISIE

void saisie (person & p) {
  cout << "Nom : ";
    cin >> p.lastname;
  cout << "Prénom : ";
    cin >> p.firstname;
  cout << "Date de naissance (jour mois année) : ";
    cin >> p.date.day >> p.date.month >> p.date.year;
  cout << endl;
}

void saisiefull (ensperson & p, int & n) {
  cout << "Combien de personnes a saisir: "; cin >> n;
  for (int i=0; i<n; i++) {
    saisie(p.a[i]);
  }
}

void init_ensref (tabperson p, int n , tabp &m) {
  for (int i=0; i < n; i++) {
    m[i] = &p[i];
  }
}

void affichref (tabp m, int n) {
  for (int i=0; i<n; i++) {
    cout << "Nom : " << m[i]->lastname << ", Prénom : " << m[i]->firstname << ", Date de naissance : " << m[i]->date.day << "/" << m[i]->date.month << "/" << m[i]->date.year << endl;
  }
}

void init_ensref_date (tabperson p, int n , tabp &m, int date) {
  for (int i=0; i < n; i++) {
    if (date == p[i].date.year) {
      m[i] = &p[i];
    }
  }
}

int main () {
  person a;
  ensperson p;
  enspersonref m,o;
  
  int n = 0;
  //cout << "Combien de personne voulez vous rentrer ? : ";
  //cin >> n;
  //cout <<  endl;
  
  saisiefull(p,n);
  init_ensref(p.a,n,m.ref_person);
  //affich(a, n);
  affichfull(p,n);
  cout << endl;
  affichref(m.ref_person,n);
  cout<< endl;
  init_ensref_date(p.a,n,o.ref_person,1999);
  affichref(o.ref_person,n);
  
  return 0;  
}
