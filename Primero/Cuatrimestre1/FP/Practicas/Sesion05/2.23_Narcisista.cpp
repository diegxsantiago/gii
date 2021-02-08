// Diego Santiago Ortiz

// Narcisisita

#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    
	int candidato,
		 copia_candidato,
		 digitos = 0,
		 contador_digit = 0,
		 orden = 1,
		 narcisista = 0,
		 cifra;
	
	cout << "Introduce el numero candidato: \n";
	cin >> candidato;
	
	copia_candidato = candidato;	/* Copia sobre la que trabajar
												en los cómputos sin perder el valor inicial */
	
	while(candidato > orden){	// Calcula el número de digitos
		digitos ++;
		orden = orden * 10;
	};
	
	while(contador_digit < digitos){
		cifra = copia_candidato % 10;
		narcisista = narcisista + pow(cifra, digitos);
		copia_candidato = copia_candidato / 10;
		contador_digit++;
	}
	
	if (candidato == narcisista)
		cout << "\nEl numero " << candidato << " es narcisista.";
	else
		cout << "\nEl numero " << candidato << " no es narcisista.";
}
