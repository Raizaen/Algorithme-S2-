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

std::string telephone (std::string nom, std::string prenom, repertoire R)
{
	if (R==NULL)
	{
		return " ";
	}
	else if ((nom==(*R).val.nom)and(prenom==(*R).val.prenom))
	{
		return (*R).val.tel;
	}
	else
	{
		return telephone (nom,prenom,(*R).suiv);
	}
}

int recherchepos (std::string nom, std::string prenom, repertoire R)
{
	int x=1;
	do
	{
		if ((nom==(*R).val.nom)and(prenom==(*R).val.prenom))
		{
			return x;
		}
		else
		{
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

void ajouter (int pos,std::string nom,std::string prenom,std::string tel,repertoire &R)	
{
	if ((R==NULL)or(pos>taille (R)))
	{
		ajouterenqueue (nom,prenom,tel,R);
	}
	else
	{
		ajouterentete (nom,prenom,tel,R);
	}
}

void supprime_premier (repertoire &R)
{
	if (R!=NULL)
	{
		repertoire p=R;
		R=(*R).suiv;
		delete p;
	}
}

void supprimer (int pos, repertoire &R)
{
	if(pos<=taille(R))
	{
		if (pos==recherchepos((*R).val.nom,(*R).val.prenom,R))
		{
			supprime_premier (R);
		}
		else 
		{
			supprimer (pos,(*R).suiv);
		}
	}
}

int main ()
{
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

return 0;
}

