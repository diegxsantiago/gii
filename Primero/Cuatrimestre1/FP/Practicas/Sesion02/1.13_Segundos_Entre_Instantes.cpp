// Diego Santiago Ortiz

// Segundos entre dos instantes

#include <iostream>
using namespace std;

int main(){
	
	int horas1, horas2, minutos1, minutos2, segundos1, segundos2;
	int tiempo1, tiempo2, dif_segundos;
	
	cout << "Introduzca las horas del primer tiempo: ";
	cin >> horas1;
	cout << "Introduzca los minutos del primer tiempo: ";
	cin >> minutos1;
	cout << "Introduzca los segundos del primer tiempo: ";
	cin >> segundos1;
	cout << "Introduzca las horas del segundo tiempo: ";
	cin >> horas2;
	cout << "Introduzca los minutos del primer tiempo: ";
	cin >> minutos2;
	cout << "Introduzca los segundos del primer tiempo: ";
	cin >> segundos2;
	
	tiempo1 = horas1*3600 + minutos1*60 + segundos1;
	tiempo2 = horas2*3600 + minutos2*60 + segundos2;
	
	dif_segundos = tiempo2 - tiempo1;
	
	cout << "Hay " << dif_segundos << " segundos entre el primer tiempo y el segundo.";
	
}
