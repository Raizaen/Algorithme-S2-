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

int main () {
	repertoire A;
	initRep(A);
	addHead("Bayart","Valentin","0657465212",A);
	addTail("Coyle","Matthew","6666666666",A);
	affichPersonne (A->pers);
	affichRep (A);
	cout << "Telephone :" << telephone("Coyle","Matthew",A) << endl;

	return 0;
}
