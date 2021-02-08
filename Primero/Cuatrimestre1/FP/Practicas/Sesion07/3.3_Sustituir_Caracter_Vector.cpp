// Diego Santiago Ortiz

// Sustituir carácter por vector (con vector auxiliar)

#include <iostream>
using namespace std;

int main(){
   
   const int TAM_MAX = 1000;
      
   char v[TAM_MAX],
        sustituido[TAM_MAX],
        a_insertar[TAM_MAX];
   char caracter,
        a_borrar;
   int util = 0,
       util_sust = 0,
       util_insert = 0;
   bool terminador = false;

   // Entrada del vector V
   for (int i=0 ; i < TAM_MAX && !terminador ; i++){
      caracter = cin.get();
      if (caracter != '#'){
         v[i] = caracter;
         util++;
      }
      else
         terminador = true;
   }
   terminador = false;
   
   // Entrada el vector A INSERTAR
   for (int i=0 ; i < TAM_MAX && !terminador ; i++){
      caracter = cin.get();
      if (caracter != '#'){
         a_insertar[i] = caracter;
         util_insert++;
      }
      else
         terminador = true;
   }
   terminador = false;
   
   // Entrada del caracter A SUSTITUIR
   a_borrar = cin.get();
   
   // Cómputos
   for (int i=0, j=0 ; i < util ; i++, j++){
      if (v[i] == a_borrar){
         for (int k=0 ; k < util_insert ; k++){
            sustituido[j+k] = a_insertar[k];
            util_sust++;
         }
         j += util_insert - 1;
      }
      else{
         sustituido[j] = v[i];
         util_sust++;
      }
         
   }
   
   // Salida
   for(int i=0 ; i < util_sust ; i++){
      cout << sustituido[i];
   }
   
}
