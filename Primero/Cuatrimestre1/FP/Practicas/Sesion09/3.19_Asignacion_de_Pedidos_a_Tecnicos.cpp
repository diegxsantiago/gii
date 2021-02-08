// Diego Santiago Ortiz

// Asignación de pedidos a técnicos

#include <iostream>
using namespace std;

int main(){
	
	const int MAX = 1000;
	int T[MAX][MAX];
	bool A[MAX][MAX],
	     pedido_disponible[MAX];
	int pos_minimo,
       coste_final = 0,
       util,
       min = MAX;
   bool salida = false;
	
	cin >> util;
	
	// Inicialización de T
	for (int i=0 ; i < util ; i++){
	   for (int j=0 ; j < util ; j++)
	     cin >> T[i][j];
   }
   
   for (int i=0 ; i < util ; i++)
      pedido_disponible[i] = true;

   // Inicialización de A
   for (int i=0 ; i < util ; i++){
	   for (int j=0 ; j < util ; j++)
	     A[i][j] = false;
   }
   
   // Cómputos
   for (int i=0 ; i < util ; i++){
	   for (int j=0 ; j < util ; j++){
	     if (T[i][j] < min && pedido_disponible[j]){
	        min = T[i][j];
           pos_minimo = j;
        }     
      }
      
      A[i][pos_minimo] = true;
      pedido_disponible[pos_minimo] = false;
      coste_final += T[i][pos_minimo];
      min = MAX;
   }
   
   // Salida
   for (int i=0 ; i < util ; i++){
      cout << "\nTecnico " << i << " -> Pedido ";
      for (int j=0 ; j < util && !salida ; j++){
         if(A[i][j]){
            cout << j;
            salida = true;
         }
      }
      salida = false;
   }
   cout << "\nCoste total: " << coste_final;
}
