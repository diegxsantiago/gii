//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Moda

#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '#';
   const int NUM_MAX_CARACT = 1e6;    // Compile con un tama�o adecuado de pila. Por ejemplo: --stack,21000000
   const int NUM_CARACT_ASCII = 256;
   
   char texto[NUM_MAX_CARACT];
   char procesados[NUM_CARACT_ASCII];
   int util_texto, util_procesados;
   char car;
   char moda;
   int frecuencia_moda;

   util_texto = 0;
   car = cin.get();

   while (car != TERMINADOR && util_texto < NUM_MAX_CARACT){
      texto[util_texto] = car;
      util_texto++;
      car = cin.get();
   }
   
   frecuencia_moda = 0;

   /*
   Algoritmo:
   
      Recorrer -i- el vector texto
         actual = texto[i]
         
         Si actual no est� en el vector procesados:
            - A�adir actual a procesados
            - Contar el n�mero de ocurrencias de actual
              en el vector texto -a partir de la posici�n i+1-                                    
   */
   
   for (int i = 0 ; i < util_texto ; i++){
      char car_actual = texto[i];
      bool encontrado = false;
      int frecuencia;

      for (int j = 0; j < util_procesados && !encontrado; j++){
         if (car_actual == procesados[j])
            encontrado = true;
      }

      if (! encontrado){
         procesados[util_procesados] = car_actual;
         util_procesados++;
         frecuencia = 0;

         for (int k = i; k < util_texto ; k++)
            if (car_actual == texto[k])
               frecuencia++;

         if (frecuencia > frecuencia_moda) {
            frecuencia_moda = frecuencia;
            moda = car_actual;
         }
      }
   }
  
   cout << "\n\nModa :     " << moda
        << "\nFrecuencia: "  << frecuencia_moda;


   // Entrada:
   // JuanCarlosCubero#

   // Salida:
   // u 2
}

