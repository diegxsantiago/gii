// Diego Santiago Ortiz

// Elasticidad Precio-Demanda

#include <iostream>  
#include <cmath> 
using namespace std; 

// Calcula el valor porcentual de dos valores
double ValorPorcentual(double inicial, double final){
	
	double v_porcentual;

	v_porcentual = abs(100 * ( (final - inicial) / inicial) );
		
   return v_porcentual;
}
                             
int main(){
   double precio_ini, precio_fin;
   double demanda_ini, demanda_fin;
   double elast_pd;
   
   cout << "Cálculo de la Elasticidad Precio-Demanda.\n\n"
        << "Introduzca cuaternas de valores:"
        << "El precio inicial, el precio final, la demanda inicial y la demanda final.\n"
        << "Introduzca cualquier negativo en el precio inicial para terminar\n\n";
   
   cin >> precio_ini;
   
   while (precio_ini >= 0){
      cin >> precio_fin;       
      cin >> demanda_ini;
      cin >> demanda_fin;
      
      elast_pd = ValorPorcentual(demanda_ini,demanda_fin) / ValorPorcentual(precio_ini,precio_fin);

      cout << "Elasticidad Precio-Demanda: " << elast_pd << "\n";      
      cin >> precio_ini;
   }
}

