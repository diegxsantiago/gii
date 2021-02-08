// Diego Santiago Ortiz

// Topk: Versión eficiente

#include <iostream>
using namespace std;

int main(){

   const int TAM_MAX = 10000;
   long v[TAM_MAX],
       topk[TAM_MAX];
   long util,
       i = 0,
       k,
       num,
       a_desplazar;
   
   // Lectura
   
   cin >> num;
   while (num >= 0){
      v[i] = num;
      cin >> num;
      i++;
   }
   util = i;
   
   cin >> k;
   
   // Copia de v en topk
   
   for (int i=0 ; i < util ; i++)
      topk[i] = v[i];
   
   // Cómputos
   
   for (int izda = 1 ; izda < util ; izda++){
      a_desplazar = v[izda];
      
      for (i = izda ; i > 0 && a_desplazar > v[i-1] ; i--)
         v[i] = v[i-1];
      
      v[i] = a_desplazar;
   }
   
   // Salida
   
   for (int i=0 ; i < k ; i++)
      cout << v[i] << " ";

}
