// Diego Santiago Ortiz

// Inter�s bancario reinvertido

#include <iostream>
using namespace std;

int main(){
	
	double capital;
	double interes;
	int anio = 0, plazo;
	
	cout << "Introduzca el capital inicial: ";
	cin >> capital;
	cout << "Introduzca el interes: ";
	cin >> interes;
	cout << "Introduzca los anios durante los cuales desea reinvertir el capital: ";
	cin >> plazo;
	
	while(anio < plazo){
		capital = capital * interes;
		anio++;
	
		cout << "Capital obtenido transcurrido el a�o n�mero " << anio << ": " << capital;	
	};
	
}

