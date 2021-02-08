// Diego Santiago Ortiz

//Conversión de grados a radianes

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double grados1;
	double grados2;
	const double GRAD_TO_RAD = ( (6 * asin(0.5)) / 180 );
	
	cout << "Introduzca el primer angulo: ";
	cin >> grados1;
	cout << "Introduzca el segundo angulo: ";
	cin >> grados2;
	
	grados1 = grados1 * GRAD_TO_RAD;
	grados2 = grados2 * GRAD_TO_RAD;
	
	cout << "Los grados en radianes son: " << grados1 << " y " << grados2 << " respectivamente.";
	
}

