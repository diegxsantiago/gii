// Diego Santiago Ortiz

// Aproximación de PI por Wallis

#include <iostream>
using namespace std;

int main(){
	
	const int MIN_TOPE = 1,
				 MAX_TOPE = 100000;
	int tope;
	double pi_medios = 1,
			 pi,
			 numerador = 0,
			 denominador = 1;
	
	cout << "Introduzca el tope: ";
	do{
		cin >> tope;
	}while(tope < MIN_TOPE || tope > MAX_TOPE);
	
	for (int i=0 ; i < tope ; i++){
		
		if(i % 2 == 0)
			numerador += 2;
		else
			denominador += 2;
		
		pi_medios *= numerador / denominador;
	}
	
	pi = 2 * pi_medios;
	
	cout.precision(15);
	cout << "PI: " << pi;
			 
}
