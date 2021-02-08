// Diego Santiago Ortiz

// Tarifa aérea con descuentos

#include <iostream>
using namespace std;

int main(){
	
	double tarifa = 150, descuento = 1;
	int puntos, dist_destino;
	const int LIMITE_PUNTOS_1 = 100;
	const int LIMITE_PUNTOS_2 = 200;
	const int LIMITE_TRAYECTO_1 = 300;
	const int LIMITE_TRAYECTO_2 = 700;
	
	cout << "Introduzca la distancia al destino: ";
	cin >> dist_destino;
	cout << "Introduzca los puntos: ";
	cin >> puntos;
	
	if (dist_destino > LIMITE_TRAYECTO_1)
		tarifa = tarifa + ((dist_destino - LIMITE_TRAYECTO_1) * 0.1);
			
	if (dist_destino > LIMITE_TRAYECTO_2)
		descuento = descuento - 0.02;
	
	if (puntos > LIMITE_PUNTOS_2)
		descuento = descuento - 0.04;
	else if (puntos > LIMITE_PUNTOS_1)
		descuento = descuento - 0.03;

	tarifa = tarifa * descuento;
	
	cout << "Tarifa final: " << tarifa;

}
