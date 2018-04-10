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

int searchPos (string nom, string prenom, repertoire R) { 
  if (R==NULL) return 0;
  if (R -> pers.nom == nom and R -> pers.prenom == prenom) {
    return 1;
  }
  else {
	  int n = searchPos (nom, prenom, R -> suiv);
	  if (n == 0) return 0;
	  else return n + 1;  
  }
}

int taille (repertoire R) {
	if (R!=NULL) {
		return 1+taille(R -> suiv);
	}
}

void add (int pos, string nom, string prenom, string tel, repertoire & R) {
	if ((R == NULL) || (pos > taille(R))) {
		addTail(nom, prenom, tel, R);
	}
	if (pos == 1) {
		repertoire a = new element;
		a -> pers.nom = nom;
		a -> pers.prenom = prenom;
		a -> pers.tel = tel;
		a -> suiv = R;
		R = a;
	}
	else {
		add (pos - 1, nom, prenom, tel, R -> suiv);
	}
		
}

void delFirst (repertoire &R)
{
	if (R!=NULL)
	{
		repertoire p=R;
		R = R -> suiv;
		delete p;
	}
}

void del (int pos, repertoire & R) { 
  if (R == NULL) {
    
  } 
    if (pos == 1) {
		repertoire b = R;
		R = R -> suiv;
		delete b;
    }
    else {
		del (pos - 1, R -> suiv);
	}
}

void delName (string nom, repertoire & R) {
	if (R!=NULL) {	
		if (R -> pers.nom == nom) {
			delFirst (R);
			delName (nom, R);
		}
		delName (nom, R -> suiv);
	}
}

void sort (repertoire & R) {
		
}

int main () {
	repertoire A;
	initRep(A);
	addHead("Bayart", "Valentin", "0657465212", A);
	addTail("Bayart", "Val", "0678465265", A);
	addTail("Bayart", "qsf", "0654565265", A);
	addTail("Coyle", "Matthew", "6666666666", A);
	addTail("aze", "rty", "1685749685", A);
	addTail("qsd", "fgh", "0563254185", A);
	addTail("wxc", "vbn", "1247896530", A);
	affichPersonne (A -> pers);
	cout << endl;
	affichRep (A);
	cout << "Telephone :" << telephone("Coyle", "Matthew", A) << endl;
	
	cout << endl;	
	cout << searchPos("qsd", "fgh", A) << endl;
	
	int pos;
	cout << "Donnez une position : ";
	cin >> pos ;
	cout << endl;
	
	del (pos, A);
	cout << endl;
	affichRep (A);
	cout << endl;
	
	add (pos,"aze", "rty", "1685749685", A);
	affichRep (A);
	cout << endl;
	
	delName ("Bayart", A);
	affichRep (A);
	cout << endl;
	
	return 0;
}
