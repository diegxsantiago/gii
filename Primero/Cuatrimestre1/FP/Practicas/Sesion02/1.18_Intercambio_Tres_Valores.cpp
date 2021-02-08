// Diego Santiago Ortiz

// Intercambio de tres variables

#include <iostream>
using namespace std;

int main(){
	
	double x, y, z;
	double intercambio;				/* Es necesaria una variable auxiliar que almacena el valor
									de una de las variables mientras se les asigna el valor de las otras
									para así no perder ese valor */
	
	cout << "Introduzca x: ";
	cin >> x;
	cout << "Introduzca y: ";
	cin >> y;
	cout << "Introduzca z: ";
	cin >> z;
	
	intercambio = z;
	z           = y;
	y           = x;
	x           = intercambio;
	 
	cout << x << " " << y << " " << z;
}
