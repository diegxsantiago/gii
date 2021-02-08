// Diego Santiago Ortiz

// Frecuencias

#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '@';
   const int NUM_CARACT_ASCII = 256;
   const int MAX_NUM_CARACT = 1e4;  // diez mil
   
   char a_buscar[NUM_CARACT_ASCII];
   int frecuencias[NUM_CARACT_ASCII];
   char texto[MAX_NUM_CARACT], aux_salida;

   char car;
   int util_a_buscar, util_texto;

   cout << "Frecuencias\n"
        << "Introduzca los caracteres del vector a buscar, con terminador "
        << TERMINADOR << "\n"
        << "A continuación introduzca  los caracteres del texto,"
        << " usando el mismo terminador.\n\n";

   // Lectura

   car = cin.get();
   util_a_buscar = 0;

   while (car != TERMINADOR && util_a_buscar < NUM_CARACT_ASCII){
      a_buscar[util_a_buscar] = car;
      car = cin.get();
      util_a_buscar++;
   }

   car = cin.get();
   util_texto = 0;

   while (car != TERMINADOR && util_texto < MAX_NUM_CARACT){
      texto[util_texto] = car;
      car = cin.get();
      util_texto++;
   }

   /* Primer método
   // Inicialización
      frecuencias[0] = 0;
   
   for (int i=0 ; i < util_texto ; i++)
      frecuencias[texto[i]]++;
   
   // Salida primer método
   
   for (int i=0 ; i < util_a_buscar ; i++)
      cout << a_buscar[i] << " - " << frecuencias[a_buscar[i]] << "\n";
   */
   
   // Segundo método 
   
   // Cómputos
   for (int i=0 ; i < util_a_buscar ; i++){
      frecuencias[i] = 0;
      for (int j=0 ; j < util_texto ; j++){
         if(texto[j] == a_buscar[i])
            frecuencias[i]++;
      }
   }
   
   // Salida
   for (int i=0 ; i < util_a_buscar ; i++){
      cout << a_buscar[i] << ": " << frecuencias[i] << "\n";
   }


}

