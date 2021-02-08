// Diego Santiago Ortiz

// Aproximación de PI por Madhava sin usar 'pow'

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	const double TANGENTE = 1 / sqrt(3);
	const int MIN_TOPE = 1,
				 MAX_TOPE = 100000;
	int tope,
		 signo = -1;
	double pi_sextos,
			 pi,
			 denominador = -1,
			 numerador = 1 / TANGENTE;
	
	cout << "Introduzca el tope: ";
	do{
		cin >> tope;
	}while(tope < MIN_TOPE || tope > MAX_TOPE);
	
	for (int i=0 ; i < tope ; i++){
		
		signo *= -1;
		numerador *= TANGENTE*TANGENTE;
		denominador += 2;
		pi_sextos += signo * (numerador / denominador);
		
	}
	
	pi = 6 * pi_sextos;
	
	cout.precision(15);
	cout << "PI: " << pi;
}
