// Diego Santiago Ortiz

// Sumatoria

#include <iostream>
using namespace std;

int main(){
   
   const int TAM_MAX = 1000;
   
   int n,
       T,
       suma = 0,
       pos_inicio = -1;
   int v[TAM_MAX];
   bool encontrado = false;
   
   // Entrada
   cin >> n;
   for (int i=0 ; i < n ; i++)
      cin >> v[i];
   cin >> T;
   
   // Cómputos
   for (int i=0 ; i < n && !encontrado; i++){
      for (int j=i ; j < n && !encontrado ; j++){
         suma += v[j];
         encontrado = suma == T;
      }
      pos_inicio = i;
      suma = 0;
   }
   
   // Salida
   if (encontrado)
      cout << "Secuencia encontrada a partir de la posicion " << pos_inicio << ".";
   else
      cout << "No hay ninguna secuencia.";
   
}
