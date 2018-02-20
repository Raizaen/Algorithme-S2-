#include <iostream>
#include <string>
using namespace std;

void saisie (string & a) {
  cout << "Veuillez saisir une chaine de caractère :";
  cin >> a; 
}

void affich (string a) {
  cout << "votre chaine de caractere est : " << a << endl;
}

/*std::string extrait(std::string a, int pos, int lon) {
  if (lon > a) {

  }
}
*/





int main () { 
	string a;
	saisie(a);
	affich(a);
	return 0;	
}
