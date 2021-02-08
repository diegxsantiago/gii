// Diego Santiago Ortiz

// Eliminar ocurrencias de una componente: Versión eficiente

#include <iostream>
using namespace std;

int main(){

   const int TAM_MAX = 3e6;
   const char TERMINADOR = '#';
   char car,
        a_borrar = 'a';
   char v[TAM_MAX];
   int util,
       i,
       pos_escritura = 0,
       decremento_util = 0;
   
   // Lectura
   
   car = cin.get();
   i = 0;

   while (car != TERMINADOR){
      v[i] = car;
      car = cin.get();
      i++;
   }
   
   util = i;
   a_borrar = cin.get();

   // Cómputos
   
   for (int pos_lectura=0 ; pos_lectura < util ; pos_lectura++){
      if (v[pos_lectura] != a_borrar){
         v[pos_escritura] = v[pos_lectura];
         pos_escritura++;
      }
      else
         decremento_util++;
   }
   
   util -= decremento_util;
   
   // Salida
   
   for (int i=0 ; i < util ; i++)
      cout << v[i];

}
