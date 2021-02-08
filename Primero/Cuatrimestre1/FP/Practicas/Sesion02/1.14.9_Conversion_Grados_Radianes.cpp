// Diego Santiago Ortiz

// Conversión de grados a radianes 

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	const double PI = 6 * asin(0.5);
	const double FACT_CONVERSION = PI / 180;
	double grados1;
	double grados2;
	
	cout << "Introduzca el primer angulo: ";
	cin >> grados1;
	cout << "Introduzca el segundo angulo: ";
	cin >> grados2;
	
	grados1 = grados1 * FACT_CONVERSION;
	grados2 = grados2 * FACT_CONVERSION;
	
	cout << "Los grados en radianes son: " << grados1 << " y " << grados2 << " respectivamente.";
	
}

