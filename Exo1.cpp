#include <iostream>
#include <array>
#include <cmath>

using namespace std;
cont int nMax = 64;

using points = std::array <point, nMax>;

struct point {
	float x, y;
};

struct enspoint {
	points p;
	int nombre;
};

bool confondus (point a, point b) {
	return (a.x == b.x && a.y == b.y);
}

float distance (point &c, point a, point b) {
	float x = (a.x - b.x);
	float y = (a.y - b.y);
	return sqrt((x*x)+(y*y));
}

point milieu (point a, point b) {
	point c;
	c.x = (b.x + a.x)/2;
	c.y = (b.y + a.y)/2
	return c;
}

point centre (enspoint a) {
	point g;
	float gx=0, gy=0;
	for(int=0; i < a.nombre; i++){
		gx += a.p[i].x;
		gy += a.p[i].y;
	}
	g.x=gx/a.nombre; g.y=gy/a.nombre;
	return g;
}

void saisiePoint (point &a) {
	cout << "Veuillez saisir la coordonnèes X du point : "
	cin >> a.x;

	cout << "\nVeuillez saisir la coordonnèes Y du point : "  
	cin >> a.y
}


void saisieEnsemble (enspoint &a) {
	cout << "Nombre de points à saisir ? : "; 
	cin>>a.nombre;
	for(int i=0; i < a.nombre; i++){
		saisiePoint(a.p[i]);
	}
}

int main () {
	point A,B;
	saisiePoint(A); saisiePoint(B); 
	point C = milieu(A,B);
	cout <<"distance: " <<distance(A,B) <<" milieu ("<<C.x<<","<<C.y<<")"<<endl;
	return 0;
}