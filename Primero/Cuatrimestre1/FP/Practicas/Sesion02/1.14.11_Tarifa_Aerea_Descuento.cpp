// Diego Santiago Ortiz

// Tarifa Aérea según KM

#include <iostream>
using namespace std;

int main(){
	
	const double tarifa = 150;
	double tarifa_final, kilometros;
	
	cout << "Introduzca la distancia en km del trayecto: ";
	cin >> kilometros;
	
	tarifa_final = tarifa + 0.2*kilometros;
	
	cout << "El precio final del billete sería de: " << tarifa;
	
}
