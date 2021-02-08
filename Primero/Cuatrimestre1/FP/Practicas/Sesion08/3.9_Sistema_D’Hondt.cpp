// Diego Santiago Ortiz

// Sistema de D'Hont

#include <iostream>
using namespace std;

int main(){

   const int TAM_MAX = 100;
   int sistema[TAM_MAX][TAM_MAX],
       escanios[TAM_MAX];
   int util_filas,
       util_columnas,
       maximo = 0,
       partido_ganador;
   
   // Inicialización
   escanios[0] = {0};
   
   // Lectura
   cin >> util_filas >> util_columnas;
   
   for (int j=0 ; j < util_columnas ; j++){
      cin >> sistema[0][j];
      
      for (int i=0 ; i < util_filas ; i++)
         sistema[i][j] = sistema[0][j];
   }
   
   // Cómputos
   for (int i=0 ; i < util_filas ; i++){
      
      for (int j=0 ; j < util_columnas ; j++){
         sistema[i][j] /= (escanios[j] + 1);
         
         if (sistema[i][j] > maximo){
            maximo = sistema[i][j];
            partido_ganador = j;
         }
      }

      escanios[partido_ganador]++;
      maximo = 0;
   }
   
   // Salida
   for (int i=0 ; i < util_columnas ; i++)
      cout << escanios[i] << " ";

}
