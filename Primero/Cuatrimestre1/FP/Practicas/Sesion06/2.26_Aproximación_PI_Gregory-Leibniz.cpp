// Diego Santiago Ortiz

// Aproximación de PI por Gregory-Leibniz

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	const int MIN_TOPE = 1,
				 MAX_TOPE = 100000;
	int tope;
	double pi_cuartos,
			 pi,
			 numerador = -1;
	
	cout << "Introduzca el tope: ";
	do{
		cin >> tope;
	}while(tope < MIN_TOPE || tope > MAX_TOPE);
	
	/* PRIMER MÉTODO
	
	for (int i=0 ; i < tope ; i++){
		
		pi_cuartos += ( pow(-1,i) / (2*i - 1) );
	}
	
	pi = 4 * pi_cuartos;
	
	cout.precision(15);
	cout << "PI: " << pi;
	*/
	
	/* SEGUNDO MÉTODO
	
	for (int i=0 ; i < tope ; i++){
		
	numerador *= -1; 
		
		pi_cuartos += numerador / (2*i + 1);
	}
	
	pi = 4 * pi_cuartos;
	
	cout.precision(15);
	cout << "PI: " << pi;
	*/
	
	// TERCER MÉTODO
	
	for (int i=0 ; i < tope ; i++){
		
		if(i % 2 == 0)
			numerador = 1;
		else
			numerador = -1;
		
		pi_cuartos += numerador / (2*i + 1);
	}
	
	pi = 4 * pi_cuartos;
	
	cout.precision(15);
	cout << "PI: " << pi;
			 
}
