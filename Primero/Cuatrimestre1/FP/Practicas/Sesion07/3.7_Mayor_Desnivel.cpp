// Diego Santiago Ortiz

// Mayor desnivel

#include <iostream>
using namespace std;

int main(){
   
   const int TAM_MAX = 1000;
   
   int n_alturas,
       desnivel,
       max_desnivel = 0,
       desnivel_pos_acumulado = 0;
   int alturas[TAM_MAX], desniveles[TAM_MAX];

   // Entrada
   cout << "Introduzca el numero de alturas a introducir, y a continuacion las propias alturas: ";
   do{
      cin >> n_alturas;
   }while(n_alturas <= 0);

   for (int i=0 ; i < n_alturas ; i++)
      cin >> alturas[i];
   
   // Cómputos
   for (int i=0 ; i < n_alturas - 1 ; i++){
      desniveles[i] = alturas[i+1] - alturas[i];
      
      if (desniveles[i] > 0)
         desnivel_pos_acumulado += desniveles[i];
         
      if (abs(desniveles[i]) > max_desnivel)
         max_desnivel = desniveles[i];
   }
   
   // Salida
   if (n_alturas <= 1)
      cout << "No hay datos suficientes";
   else
      cout << "Maximo desnivel: " << max_desnivel 
           << "\nDesnivel positivo acumulado: " << desnivel_pos_acumulado;


}

