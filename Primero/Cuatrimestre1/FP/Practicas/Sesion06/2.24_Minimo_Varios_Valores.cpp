//Diego Santiago Ortiz

// Mínimo de varios valores

#include <iostream>
using namespace std;

int main(){
	
	int dato,
		 num_datos = 0,
		 minimo;

	cin >> dato;
	minimo = dato;
		 
	while (dato != 0){
		num_datos++;
		
		if (dato < minimo)
			minimo = dato;
		
		cin >> dato;
	}
	
	cout << "Introducidos: " << num_datos << ". Minimo: " << minimo;


}
