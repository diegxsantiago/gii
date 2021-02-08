// Diego Santiago Ortiz

// Mayúscula a minúscula

#include <iostream>
using namespace std;

int main(){
	
	char mayus, minus;
	const int DIFERENCIA_MINUS_MAYUS = 'a' - 'A';
	
	cout << "Introduzca la mayuscula: ";
	cin >> mayus;
	
	minus = mayus + DIFERENCIA_MINUS_MAYUS;
	
	cout << "La letra minuscula es: " << minus;
	 
}
