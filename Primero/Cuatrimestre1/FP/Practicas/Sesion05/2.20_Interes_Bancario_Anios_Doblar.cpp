// Diego Santiago Ortiz

// Inter�s bancario reinvertido

#include <iostream>
using namespace std;

int main(){
	
	double capital, capital_objetivo;
	double interes;
	int anios = 0;
	
	cout << "Introduzca el capital inicial: ";
	cin >> capital;
	cout << "Introduzca el interes: ";
	cin >> interes;
	
	capital_objetivo = 2 * capital;
	
	while(capital < capital_objetivo){
		capital = capital * interes;
		anios++;
	};
	
	cout << "Para doblar la cantidad inicial han de pasar " << anios << " anios.";
	cout << "\nAl finalizar, se obtendr� un total de " << capital << " euros.";

}

