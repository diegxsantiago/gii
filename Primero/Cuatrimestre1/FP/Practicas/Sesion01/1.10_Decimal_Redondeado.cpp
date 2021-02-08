// Diego Santiago Ortiz

// Decimal redondeado

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	double num;
	double cifra;
	double orden;
	
	cout << "Introduzca el numero a redondear: ";
	cin >> num;
	cout << "Introduzca la cifra a la que redondear: ";
	cin >> cifra;
	
	orden = pow(10 , cifra);
	num = num * orden;
	num = round(num);
	num = num / orden;
	
	cout << "El numero redondeado a la " << cifra << " cifra es: " << num;
	
}

