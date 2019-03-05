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

/*struct enspersonref {
    tabp ref_person;
    int nbr_person;
  
};
*/

//------------------------------------------------------- AFFICHAGE

void affich (person p) {
    cout << "Nom : " << p.lastname << ", Prénom : " << p.firstname << ", Date de naissance : " << p.date.day << "/" << p.date.month << "/" << p.date.year << endl;
}

void affichfull (ensperson p, int n) {
  for(int i=0;i<n;i++){
    affich(p.a[i]);
  }
}

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

int main () {
  person a;
  ensperson p;
  
  int n = 0;
  //cout << "Combien de personne voulez vous rentrer ? : ";
  //cin >> n;
  //cout <<  endl;
  
  saisiefull(p,n);
  //affich(a, n);
  affichfull(p,n);
  return 0;  
}