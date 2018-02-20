#include <iostream>

using namespace std;

//Racine Dicho

double racine_dicho_impl(double x, double bi, double bs, double e) {
	double med = ((bs - bi)/2);	
	if ((bs -bi) <= (2 * e)) {
		return med;	
	}
	else if ((med*med) <= x) {
	return racine_dicho_impl(x,med,bi,e);
	}
	else {
	return racine_dicho_impl(x,bi,med,e);
	}
}

//Racine Heron 

double racine_dicho(double x, double e) {
	return racine_dicho_impl(x,0,x+1,e);
}


double carre (double x) {
	return x*x
}
bool entre (double x, double bi, double bs) {
	return (x >= bi) and (x <= bs);
}
double racine_heron(double x, double u, double e) {
	if (entre(x,carre(u-e),carre(u+e))
	return x;
	}
	else {
	return racine_heron(x,(u+x/u)/2,e);
	}
}





int main () {
	
	cout << racine_dicho(10456,0.0002);
	return 0;
}
