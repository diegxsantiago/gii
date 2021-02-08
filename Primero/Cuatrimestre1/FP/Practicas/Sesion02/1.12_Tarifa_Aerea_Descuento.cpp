// Diego Santiago Ortiz

// Tarifas aéreas con descuentos

#include <iostream>

using namespace std;

int main(){
	
	double tarifa;
	double tarifa_puntos;
	double tarifa_trayecto_largo;
	const double DCTO_PTOS = 1 - 0.2;
	const double DCTO_TRAY = 1 - 0.4;
	
	cout << "Introduzca el precio inicial: ";
	cin >> tarifa;
	
	tarifa_puntos = tarifa * DCTO_PTOS;
	tarifa_trayecto_largo = tarifa * DCTO_TRAY;
	
	cout << "Precios finales: " << tarifa_puntos << " " << tarifa_trayecto_largo;
	
}
