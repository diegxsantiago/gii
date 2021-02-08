// Diego Santiago Ortiz

// Expresiones logicas

#include <iostream>
using namespace std;

int main(){
	
	bool es_minus = false;
	bool no_es_adulto = false;
	bool primeros_cien = false;
	bool es_bisiesto = false;
	bool vel_mayor_cien = false;
	bool es_vocal = false;
	
	char letra, vocal;
	int adivine, edad, anio, velocidad;
		
	cout << "Introduzca los datos: ";
	cin >> letra >> edad >> adivine >> anio >> velocidad >> vocal;
	
	es_minus       = letra >= 'a' && letra <= 'z';
	no_es_adulto   = edad < 18 || edad > 65;
	primeros_cien  = adivine >= 1 && adivine <= 100;
	es_bisiesto    = (anio%4 == 0 && anio%100 != 0) || anio%400 == 0;
	vel_mayor_cien = velocidad >= 100;
	es_vocal       = vocal == 'a'|| vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u';
	
	cout << "Resultado: " << es_minus << " " << no_es_adulto << " " << primeros_cien << " " << es_bisiesto << " " << vel_mayor_cien << " " << es_vocal;

}
