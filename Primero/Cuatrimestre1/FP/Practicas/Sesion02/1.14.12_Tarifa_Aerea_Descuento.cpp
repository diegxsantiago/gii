// Diego Santiago Ortiz

// Tarifas aéreas con descuentos

#include <iostream>
using namespace std;

int main(){
	
	double tarifa, tarifa_puntos, tarifa_trayecto_largo;
	const double descuento_puntos = 1 - 0.2, descuento_trayecto_largo = 1 - 0.4;
	
	cout << "Introduzca el precio inicial: ";
	cin >> tarifa;
	
	tarifa_puntos         = tarifa * descuento_puntos;
	tarifa_trayecto_largo = tarifa * descuento_trayecto_largo;
	
	cout << "Precios finales: " << tarifa_puntos << " " << tarifa_trayecto_largo;
	
}
