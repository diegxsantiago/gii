// Diego Santiago Ortiz

// Topk Versión Eficiente

#include <iostream>
using namespace std;

int main(){
   
   const int TAM_MAX = 1e5;
   long v[TAM_MAX],
       topk[TAM_MAX];
   long util,
       i = 0,
       k,
       num,
       intercambio,
       pos_maximo;
   
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
   
   for (int izda = 0 ; izda < k ; izda++){
      
      pos_maximo = izda;
      
      for (int i = izda + 1 ; i < util ; i++){
         if (topk[i] > topk[pos_maximo])
            pos_maximo = i;
      }
      
      intercambio = topk[izda];
      topk[izda] = topk[pos_maximo];
      topk[pos_maximo] = intercambio;
        
   }
   
   // Salida
   
   for (int i=0 ; i < k ; i++)
      cout << topk[i] << " ";
}
