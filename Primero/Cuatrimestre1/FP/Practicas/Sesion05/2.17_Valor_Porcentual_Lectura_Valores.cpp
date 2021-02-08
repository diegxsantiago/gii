// Diego Santiago Ortiz

// Valor porcentual: lectura de valores propios

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double valor1;
	double valor2;
	double v_porcentual;
	
	cout << "Introduzca el valor inicial: ";
	cin >> valor1;
		
	while(valor1 != -1){									/* Suponemos que una vez introducido
																	el primer valor CORRECTO, el segundo también lo es */				
		cout << "Introduzca el valor final: ";
		cin >> valor2;
		
		v_porcentual = abs(100 * ( (valor2 - valor1) / valor1) );
		
		cout << "El valor porcentual es del " << v_porcentual << "%";
		
		cout << "Introduzca el valor inicial: ";
		cin >> valor1;
	};
	
}
