// Diego Santiago Ortiz

// Tarifa aérea

#include <iostream>
using namespace std;

int main(){
	
	double tarifa = 150, dist_destino;
	const int LIMITE = 300;
	
	cout << "Introduzca la distancia al destino: ";
	cin >> dist_destino;
	
	if (dist_destino > LIMITE)
		tarifa = tarifa + ((dist_destino - LIMITE) * 0.1);
		
	cout << "Tarifa final: " << tarifa;

}
