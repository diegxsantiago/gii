// Diego Santiago Ortiz

// Intercambio de variables

#include <iostream>
using namespace std;

int main(){
	
	double caja_izda, caja_dcha;
	double intercambio;				/* Es necesaria una variable auxiliar que almacena el valor
									de una de las variables mientras se le asigna el valor de la otra
									para así no perder ese valor */
	
	cout << "Introduzca el valor de la caja izquierda: ";
	cin >> caja_izda;
	cout << "Introduzca el valor de la caja derecha: ";
	cin >> caja_dcha;
	
	intercambio = caja_izda;
	caja_izda   = caja_dcha;
	caja_dcha   = intercambio;
	
	cout << "La caja izquierda vale " << caja_dcha;
	cout << "\nLa caja derecha vale " << caja_izda;
}
