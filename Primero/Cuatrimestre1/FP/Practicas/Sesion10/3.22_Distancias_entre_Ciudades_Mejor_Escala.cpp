// Diego Santiago Ortiz

// Distancias entre ciudades (mejor escala)

#include <iostream>
#include <cmath>

using namespace std;

int main(){
   const int MAX_NUM_CIUDADES = 50;
   double mapa[MAX_NUM_CIUDADES][MAX_NUM_CIUDADES];
   int num_ciudades,
       ciudad1,
       ciudad2,
       escala = MAX_NUM_CIUDADES;
   double distancia_min = INFINITY;
   
   // Lectura
   
   cin >> num_ciudades;
      
   for (int i = 0; i < num_ciudades; i++)
      for (int j = 0; j < num_ciudades; j++)
         mapa[i][j] = 0;
         
   for (int i = 0; i < num_ciudades - 1; i++){
      
      for (int j = i+1; j < num_ciudades; j++){
         double dist;
         
         cin >> dist;
         mapa[i][j] = mapa[j][i] = dist;
      }
   }
   
   cin >> ciudad1 >> ciudad2;
   
   // Cómputos
   
   if (mapa[ciudad1][ciudad2] == 0){
      
      for (int i=0 ; i < num_ciudades ; i++){
         
         if (mapa[ciudad1][i] != 0 && mapa[i][ciudad2]){
            
            if ( (mapa[ciudad1][i] + mapa[i][ciudad2]) < distancia_min ){

               distancia_min = mapa[ciudad1][i] + mapa[i][ciudad2];
               escala = i;
            }
         }
         
      }
      
      cout << "La mejor escala entre las ciudades " << ciudad1 << " y " << ciudad2 << " es la ciudad " << escala;
   }
   else
      cout << "Hay trayecto directo";
   
   
}

