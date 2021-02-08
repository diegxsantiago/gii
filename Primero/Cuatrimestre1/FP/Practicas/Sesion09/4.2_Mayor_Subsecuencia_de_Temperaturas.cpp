// Diego Santiago Ortiz

// Secuencia de temperaturas

#include <iostream>
using namespace std;

// Comprueba si un número está dentro de un intervalo cerrado [x,y]
bool PerteneceIntervalo(double temperatura, double cota_inf, double cota_sup){
   return cota_inf <= temperatura && temperatura <= cota_sup;
}

int main(){
   
	const int MIN_TEMP = -90,
				 MAX_TEMP = 60;
	double anterior,
			 actual;
	int longitud = 1,
		 longitud_max = 0,
		 pos_actual = 1,
		 pos_min = 1,
		 inicio = 1;
	bool final_entrada_datos;
			
	cin >> anterior;
	final_entrada_datos = PerteneceIntervalo(anterior,MIN_TEMP,MAX_TEMP);
   
	while (! final_entrada_datos){
   	cin >> actual;
		pos_actual++;
   	final_entrada_datos = PerteneceIntervalo(actual,MIN_TEMP,MAX_TEMP);
   	
   	if (final_entrada_datos || actual < anterior){
   		if (longitud > longitud_max){
   			longitud_max = longitud;
   			inicio = pos_min;
   		}
   		
   		longitud = 1;
   		pos_min = pos_actual;
		}
		else{
			longitud++;
		}
		
		anterior = actual;
	};
	
	cout << "Inicio: " << inicio << " Longitud: " << longitud_max; 
}
