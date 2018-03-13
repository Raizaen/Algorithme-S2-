#include <iostream> 
#include <array>

using namespace std; 

const int BufferSize = 10;
	using Tab = std::array<int,BufferSize>;
	Tab t;
	int arraysize;

int pos (Tab t,int x, int n) {
	if (n < t[0]) {

	}
	else if (x <= t[n-1]) {
		if (x < n-1) {
			return pos(t, x, n-1);
		}	
		
	}
}
/*
void insert () {

}


void saisie (Tab t, int a) {
	if (a <= BufferSize) {
	}
}
*/
void genalea () {

}


void affich (Tab t, int n) {
	if (n >= 0) {
		cout << t[n] << ' ';
		return affich (t, n-1);
	}
}


int main () {
	
	cout << "Nombre d'entiers dans le tableau : ";
	cin >> arraysize;
	cout << endl;

	for (int i=0; i < arraysize; i++) {
		cin >> t[i];
	}

	affich(t,5);

	pos(t,3,5);

}
