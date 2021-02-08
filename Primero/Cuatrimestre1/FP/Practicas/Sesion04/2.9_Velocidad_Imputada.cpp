// Diego Santiago Ortiz

// Velocidad imputada

#include <iostream>
using namespace std;

int main(){
	
	const int LIMITE_VELOCIDAD = 100;
	double margen, indice;
	char radar;
	bool radar_fijo;
	double vel_captada, vel_imputada;
	
	cout << "Introduzca 'F' para indicar que es un radar fijo y cualquier otra cosa para un radar movil: ";
	cin >> radar;
	cout << "Introduzca la velocidad captada por el radar: ";
	cin >> vel_captada;
	
	radar_fijo = (radar == 'F' || radar == 'f');
	
	if (vel_captada <= LIMITE_VELOCIDAD){
		
		if (radar_fijo)
			margen = 5;
		else
			margen = 7;
		
		vel_imputada = vel_captada - margen;
	}
	else{
		
		if (radar_fijo)
			indice = 0.95;
		else
			indice = 0.93;
	
		vel_imputada = vel_captada * indice;	
	}
	
	
	cout << "Velocidad imputada: " << vel_imputada;

}
