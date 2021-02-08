// Diego Santiago Ortiz

// Valor porcentual

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double valor1;
	double valor2;
	double vp;
	
	cout << "Introduzca el valor inicial: ";
	cin >> valor1;
	cout << "Introduzca el valor final: ";
	cin >> valor2;
	
	vp = abs(100 * ( (valor2 - valor1) / valor1) );
	
	cout << "El valor porcentual es del " << vp << "%";
	
}

