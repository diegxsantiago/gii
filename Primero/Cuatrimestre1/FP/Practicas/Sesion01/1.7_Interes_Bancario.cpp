// Diego Santiago Ortiz

// Interés bancario

#include <iostream>
using namespace std;

int main(){
	
	double capital;
	double interes;
	
	cout << "Introduzca el capital: ";
	cin >> capital;
	cout << "Introduzca el interes: ";
	cin >> interes;
	
	capital = capital + capital * (interes / 100);
	
	cout << "El capital final es: " << capital;
	
}

