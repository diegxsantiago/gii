// Diego Santiago Ortiz

// Lee entero mayor o igual que otro

#include <iostream>
#include <iostream>
using namespace std; 

int LeeIntMayorIgual(int min){
   
   int mayor_igual;
   
   do{
      cin >> mayor_igual;
   }while(mayor_igual < min);
   
   return mayor_igual;
}

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}

int main(){
   const int TOTAL_A_INTRODUCIR = 3;
   
   int min,
       max,
       n;
        
   cin >> min;

   max = LeeIntMayorIgual(min);
   
   n = LeeIntRango(min,max,"");

   cout << "\nValor final en rango: " << n;
}
