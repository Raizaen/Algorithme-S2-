#include <iostream>
#include <string>

struct personne
{
  std::string nom,prenom,tel;
};

struct element
{
  personne val;
  element *suiv;
};
using repertoire=element*;

void initR (repertoire &R)
{
  R=NULL;
}

void ajouterentete (std::string nom, std::string prenom, std::string tel, repertoire &R)
{
  repertoire p;
  p=new element;
  (*p).val.nom=nom;
  (*p).val.prenom=prenom;
  (*p).val.tel=tel;
  (*p).suiv=R;
  R=p;
}

void ajouterenqueue (std::string nom, std::string prenom, std::string tel, repertoire &R)
{
  if (R==NULL)
  {
    ajouterentete (nom,prenom,tel,R);
  }
  else
  {
    ajouterenqueue (nom,prenom,tel,(*R).suiv);
  }
}

void afficherP (personne P)
{
  std::cout<<"nom: "<< P.nom<< std::endl;
  std::cout<<"prénom: "<< P.prenom<< std::endl;
  std::cout<<"téléphone: "<< P.tel<< std::endl;
}

void afficherR (repertoire R)
{
  if (R!=NULL)
  {
    afficherP ((*R).val);
    afficherR ((*R).suiv);
  }
}

std::string telephone (std::string nom, std::string prenom, repertoire R) {
  if (R==NULL) {
    return " ";
  }
  else if ((nom==(*R).val.nom)and(prenom==(*R).val.prenom)) {
    return (*R).val.tel;
  }
  else {
    return telephone (nom,prenom,(*R).suiv);
  }
}

int recherchepos (std::string nom, std::string prenom, repertoire R) {
  int x=1;
  do
  {
    if ((nom==(*R).val.nom)and(prenom==(*R).val.prenom)) {
      return x;
    }
    else {
      x=x+1;
      R=(*R).suiv;
    }
  }
  while (R!=NULL);
  return 0;
}

int taille (repertoire R)
{
  if (R!=NULL)
  {
    return 1+taille((*R).suiv);
  }
}

void ajouter (int pos,std::string nom,std::string prenom,std::string tel,repertoire &R)	{
  /*if ((R==NULL) or (pos>taille (R))) {
    ajouterenqueue (nom,prenom,tel,R);
  }
  if (R==NULL or pos==1) {
    ajouterentete(nom,prenom,tel,R);
  }*/
  if (R!=NULL and pos>1) {
    ajouter(pos-1,nom,prenom,tel,R->suiv);
  }
  else {
    ajouterentete(nom,prenom,tel,R);
  }
}

void supprime_premier(repertoire &R)
{
  if (R!=NULL)
  {
    repertoire p=R;
    R=(*R).suiv;
    delete p;
  }
}

void supprimer (int pos, repertoire &R) {
  /*if(pos<=taille(R)) {
    if (pos==recherchepos((*R).val.nom,(*R).val.prenom,R)) {
      supprime_premier (R);
    }
    else {
      supprimer (pos,(*R).suiv);
    }
  }*/
  if(pos==1){
    supprime_premier(R);
  }
  else if (pos>1) supprimer(pos-1,R->suiv);
}

void supprimern (std::string nom, repertoire &R) {
  if(R!=NULL){
    if(R->val.nom==nom){
      supprimer(1,R);
      supprimern(nom,R);
    }
    supprimern(nom,R->suiv);
  }
}



int main () {
  std::string nom="Chausse",prenom="Baptiste",nom1="Manceau",prenom1="Clement";
  
  repertoire A;
  initR(A);
  ajouterenqueue("Bayart","Valentin","0769818442",A);
  ajouterenqueue("Bayart","Val","0769818442",A);
  ajouterenqueue("Bayart","Vale","0769818442",A);
  ajouterenqueue("Manceau","Clement","0598485695",A);
  ajouterenqueue("Chausse","Baptiste","5684259712",A);
  ajouterentete("Aschard","Erwan","1245789865",A);
  
  afficherR(A);
  
  std::cout << "Baptiste se trouve en position " << recherchepos(nom,prenom,A) << " du répertoire" << std::endl;
  std::cout << "Clément se trouve en position " << recherchepos(nom1,prenom1,A) << " du répertoire"  << std::endl;
  std::cout << std::endl << std::endl;
  ajouter(1,"Coyle","Matthew","2565478695",A);
  afficherR(A);
  std::cout << std::endl << std::endl;
  ajouter(12,"Thomazeau","Alexandre","4575369582",A);
  afficherR(A);
  std::cout << std::endl << std::endl;
  ajouter(3,"Fontaine","Héloïse","1248635975",A);
  afficherR(A);
  std::cout << std::endl << std::endl;
  
  supprimer(3,A);
  afficherR(A);
  std::cout << std::endl << std::endl;
  
  supprimern("Bayart",A);
  afficherR(A);
  std::cout << std::endl << std::endl;
  
  /*
  std::string nom,prenom,tel,nom2,prenom2,tel2,t,nom3,prenom3,tel3;
  int r,T,pos,pos2;
  repertoire R;
  initR (R);
  
  
  
  std::cout<< "Entrer le nom: ";
  std::cin>> nom;
  std::cout<< "Entrer le prenom: ";
  std::cin>> prenom;
  std::cout<< "Entrer le tel: ";
  std::cin>> tel;
  
  ajouterentete (nom,prenom,tel,R);
  afficherR (R);
  
  std::cout<< "Entrer le nom: ";
  std::cin>> nom2;
  std::cout<< "Entrer le prenom: ";
  std::cin>> prenom2;
  
  t=telephone (nom2,prenom2,R);
  std::cout<< "Le numéro de téléphone est "<<t<< std::endl;
  
  r=recherchepos (nom2,prenom2,R);
  std::cout<< "La position de la première occurrence est: "<<r << std::endl;
  
  T=taille (R);
  
  std::cout<<"Entrer une position: ";
  std::cin>>pos;
  
  std::cout<< "Entrer le nom: ";
  std::cin>> nom3;
  std::cout<< "Entrer le prenom: ";
  std::cin>> prenom3;
  std::cout<< "Entrer le tel: ";
  std::cin>> tel3;
  
  ajouter (pos,nom3,prenom3,tel3,R);
  afficherR (R);
  
  std::cout<<"Entrer une position: ";
  std::cin>>pos2;
  
  supprimer (pos2,R);
  afficherR (R);
  */
  return 0;
}