#include <iostream>
#include <string>

using namespace std;

struct personne {
	std::string nom, prenom, tel;
};

struct element {
	personne pers;
	element *suiv;
};
using repertoire = element*;

void initRep (repertoire & R) {
	R = NULL;
	/*if (R !=NULL) {
		// (*R).pers.nom = "" same R -> pers.nom = ""
		R -> pers.nom = "";
		R -> pers.prenom = "";
		R -> pers.tel = "";
	}*/

}

void addHead (string nom, string prenom, string tel, repertoire & R) {
	repertoire a = new element;
	a -> pers.nom = nom;
	a -> pers.prenom = prenom;
	a -> pers.tel = tel;
	a -> suiv = R;
	R = a;
	
}

void addTail (string nom, string prenom, string tel, repertoire & R) {
	if (R==NULL) {
		addHead (nom, prenom, tel, R);
	}

	else addTail(nom, prenom, tel, R -> suiv);
}

void affichPersonne (personne P) {
	cout << "Prenom : " << P.prenom << endl;
	cout << "Nom : " << P.nom << endl;
	cout << "Tel : " << P.tel << endl;
}

void affichRep (repertoire R) {
	if(R!=NULL) {
		affichPersonne(R -> pers);
		affichRep(R -> suiv);
	}
}

string telephone (string nom, string prenom, repertoire R) {
	if (R==NULL) return "";
	if (R -> pers.nom == nom and R -> pers.prenom == prenom) return R -> pers.tel;
	return telephone (nom, prenom, R -> suiv); 
}

int searchPos (string nom, string prenom, repertoire R, int & pos) { 
  if (R==NULL) return 0;
  if (R -> pers.nom == nom and R -> pers.prenom == prenom) {
    return pos;
  }
  pos++;
  return searchPos (nom, prenom, R -> suiv, pos); 
}

/*void add (int pos, string nom, string prenom, string tel, repertoire & R) {
  if (pos > R) {
    repertoire a = new element;
    a -> pers.nom = nom;
    a -> pers.prenom = prenom;
    a -> pers.tel = tel;
  }
  
}
*/
void del (int pos, repertoire & R) { 
  if (R == NULL) {
    
  }
  else { 
    int n = 0;
    if (pos == searchPos ("aze", "rty", R, n)) {
      b = R;
      R = R -> suiv;
      delete b;
    }
  }

}


int main () {
  int pos=0;
	repertoire A;
	initRep(A);
	addHead("Bayart", "Valentin", "0657465212", A);
	addTail("Coyle", "Matthew", "6666666666", A);
	addTail("aze", "rty", "1685749685", A);
	addTail("qsd", "fgh", "0563254185", A);
	addTail("wxc", "vbn", "1247896530", A);
	affichPersonne (A->pers);
	affichRep (A);
	cout << "Telephone :" << telephone("Coyle", "Matthew", A) << endl;
	searchPos ("aze", "rty", A, pos);
	cout << pos << endl;
	del (int pos, A);
	affichRep (A);
	return 0;
}
