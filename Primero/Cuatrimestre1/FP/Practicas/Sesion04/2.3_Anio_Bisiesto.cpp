// Diego Santiago Ortiz

// Año bisesto

#include <iostream>
using namespace std;

int main(){
	
	int anio;
	bool bisiesto;
	
	cout << "Introduzca el anio: ";
	cin >> anio;
	
	bisiesto = (anio%4 == 0 && anio%100 != 0) || anio%400 == 0;
	
	if (bisiesto)
		cout << "Es bisiesto";
	else
		cout << "No es bisiesto";

}
