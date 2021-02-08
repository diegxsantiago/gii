// Diego Santiago Ortiz

// Intervalo

#include <iostream>
using namespace std;

int main(){
		
  	double cota_izda, cota_dcha, real;
   char car_izda, car_dcha, car_coma;
  	bool cerrado, cerr_inf = false, cerr_sup = false;
  	bool pertenece = false;
   
   cout << "Intervalo.\n\n" 
        << "Introduzca el intervalo.\n";
        
   cin >> car_izda; 
	cin >> cota_izda;
  	cin >> car_coma; 
   cin >> cota_dcha;
  	cin >> car_dcha;
   	
  	cout << "\nIntroduzca un valor real: ";
  	cin >> real;

	if (car_izda == '[')
		cerr_inf = true;
	
	if(car_dcha == ']')
		cerr_sup = true;
		
	cerrado = cerr_inf && cerr_sup;
	
   cout << "\nIntervalo:"  << car_izda << " " << cota_izda << " " 
                           << car_coma << " " << cota_dcha << " " << car_dcha;
    
   pertenece = (cota_izda < real && real < cota_dcha)
					|| (cerr_inf && cota_izda <= real && real < cota_dcha)
					|| (cerr_sup && cota_izda < real && real <= cota_dcha )
					|| (cerrado && cota_izda <= real && real <= cota_dcha );
   
	if(pertenece)
		cout << "\nEl valor real " << real << " pertence al intervalo.";
	else
		cout << "\nEl valor real " << real << " no pertenece al intervalo";
}


