// Diego Santiago Ortiz

// Gaussiana

#include <iostream>
#include <cmath>
using namespace std;

int main(){

	// Declaración de variables
	const double PI = 6 * asin(0.5);
	double esperanza, desviacion;
	double gaussiana;
	double minimo, incremento, maximo;
	double denominador;
	
	// Entrada
	cout << "Introduzca la ESPERANZA: ";
	cin >> esperanza;
	
	cout << "Introduzca la DESVIACION TIPICA: ";
	do{
		cin >> desviacion;		
	}while(desviacion < 0);

	cout << "Introduzca el MINIMO: ";
	cin >> minimo;
	
	cout << "Introduzca el MAXIMO: ";
	do{
		cin >> maximo;
	}while(maximo < minimo);
	
	cout << "Introduzca el INCREMENTO: ";
	do{
		cin >> incremento;
	}while(incremento <= 0);
	
	// Cómputos y salida
	denominador = (desviacion * sqrt(2 * PI));
	
	for (double i=minimo ; i <= maximo ; i += incremento){

		gaussiana =  exp(-0.5 * pow((i - esperanza) / desviacion , 2)) / denominador;
		cout << i << " ---- " << gaussiana << "\n";
	}
	

}
