// Diego Santiago Ortiz

//Distancia euclídea

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double x1;
	double y1;
	double x2;
	double y2;
	double distancia;
	
	cout << "Introduzca x1: ";
	cin >> x1;
	cout << "Introduzca y1: ";
	cin >> y1;
	cout << "Introduzca x2: ";
	cin >> x2;
	cout << "Introduzca y2: ";
	cin >> y2;
	
	distancia = sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
	
	cout << "La distancia entre los puntos es: " << distancia;
	
}

