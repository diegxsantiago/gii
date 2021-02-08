//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Mapa de distancias entre ciudades

#include <iostream>
#include <cmath>
using namespace std;

int main(){
   const int MAX_NUM_CIUDADES = 50;
   double mapa[MAX_NUM_CIUDADES][MAX_NUM_CIUDADES];
   int num_ciudades;
   int origen, destino;

   cout << "Mapa de distancias"
        << "\n\nIntroduzca los datos en el siguiente orden:"
        << "\n- Número de ciudades"
        << "\n- Distancias entre ellas en forma de matriz diagonal superior"
        << "\n- Índices de dos ciudades (para ver la mejor escala entre ellas)"
        << "\n\n";

   cin >> num_ciudades;

   for (int i = 0; i < num_ciudades; i++)
      for (int j = 0; j < num_ciudades; j++)
         mapa[i][j] = 0;
         
   for (int i = 0; i < num_ciudades - 1; i++)        
      for (int j = i+1; j < num_ciudades; j++){
         double dist;
         
         cin >> dist;
         mapa[i][j] = mapa[j][i] = dist;
      }
  
   cin >> origen;
   cin >> destino;
          
   // -----------------------------------------------------------------------
   // Ciudad más conectada
   
   int ciudad_mas_conectada;
   int max_conex, num_conex;

   ciudad_mas_conectada = -1;
   max_conex = -1;
   
   for (int origen = 0; origen < num_ciudades; origen++){
      num_conex = 0;

      for (int destino = 0; destino < num_ciudades; destino++)
         if (mapa[origen][destino] != 0)
            num_conex++;
            
      if (num_conex > max_conex){
         max_conex = num_conex;
         ciudad_mas_conectada = origen;
      }
   }
     
   cout << "\nCiudad más conectada: " << ciudad_mas_conectada
        << " con un total de " << max_conex
        << " conexiones";

   // -----------------------------------------------------------------------
   // Mejor escala entre origen y destino

   double distancia_con_escala;
   int escala_min_distancia;
   double min_distancia;
   
   escala_min_distancia = -1;   
   min_distancia = INFINITY ;
   
   for (int escala = 0; escala < num_ciudades; escala++){
      distancia_con_escala = 0;
      
      if (mapa[origen][escala] != 0 && mapa[escala][destino] != 0)
         distancia_con_escala = mapa[origen][escala] +
                                mapa[escala][destino];

      if (distancia_con_escala != 0){               
         if (distancia_con_escala < min_distancia){
            escala_min_distancia = escala;
            min_distancia = distancia_con_escala;
         }
      }
   }      
         
   cout << "\nMejor escala entre " << origen << " y " << destino
        << ": " << escala_min_distancia;
}

/*
   5    
   50  100   0    150     
       70    0    0      
             60   80      
                  90
   0 3                            
*/      
/*
Salida:

Ciudad más conectada: 2 con un total de 4 conexiones
Mejor escala entre 0 y 3: 2
*/


