// Diego Santiago Ortiz

// Secuencia de temperaturas

#include <iostream>
using namespace std;

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
	final_entrada_datos = anterior < MIN_TEMP
								 ||
                         anterior > MAX_TEMP;
   
	while (! final_entrada_datos){
   	cin >> actual;
		pos_actual++;
   	final_entrada_datos = actual < MIN_TEMP
									 ||
                            actual > MAX_TEMP;
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
