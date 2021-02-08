// Diego Santiago Ortiz

// Número muy divisible

#include <iostream>
using namespace std;

int main(){

   int min,
       max,
       k,
       num_divisores = 0;
   
   // Entrada
   do{
      cin >> min;
   }while(min <= 0);

   do{
     cin >> max; 
   }while(max <= min);
   
   do{
      cin >> k;
   }while(k <= 0);
   
   // Cómputos y salida
   cout << "Numeros muy divisibles en el siguiente rango: [" << min << "," << max << "]:\n";
   
   for (int i=min ; i <= max ; i++){
      for (int j=2 ; j < i/2 ; j++){
         if(i % j == 0)
            num_divisores++;
      }
      
      if(num_divisores >= k)
         cout << i << " ";
      
      num_divisores = 0;
  }
   
}
