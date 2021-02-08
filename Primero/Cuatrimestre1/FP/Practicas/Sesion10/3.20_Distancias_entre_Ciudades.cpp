// Diego Santiago Ortiz

// Mapa de distancias entre ciudades

#include <iostream>
#include <cmath>
using namespace std;

int main(){
   const int MAX_NUM_CIUDADES = 50;
   double mapa[MAX_NUM_CIUDADES][MAX_NUM_CIUDADES];
   int num_ciudades;

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
   
   int ciudad_mas_conectada;
   int max_conex = 0,
       num_conex = 0;
   
   for (int i = 0; i < num_ciudades - 1; i++){
      for (int j = 0; j < num_ciudades; j++){
         if (mapa[i][j] != 0)
            num_conex++;
      }
      
      if(num_conex > max_conex)
         ciudad_mas_conectada = i;
      
      num_conex = 0;
   }
     
   cout << "\nCiudad más conectada: " << ciudad_mas_conectada
        << " con un total de " << max_conex
        << " conexiones";
}

