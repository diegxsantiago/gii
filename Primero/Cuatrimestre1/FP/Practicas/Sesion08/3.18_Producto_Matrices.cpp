// Diego Santiago Ortiz

// Producto de matrices

#include <iostream>
using namespace std;

int main(){

   const int TAM_MAX = 100;
   int m1[TAM_MAX][TAM_MAX],
       m2[TAM_MAX][TAM_MAX],
       m_producto[TAM_MAX][TAM_MAX];
   int num,
       util_filas,
       util_filas1,
       util_filas2,
       util_columnas,
       util_columnas1,
       util_columnas2,
       producto = 0;
   
   // Lectura
   cin >> util_filas1 >> util_columnas1;
   
   for (int i=0 ; i < util_filas1 ; i++){
      for (int j=0 ; j < util_columnas1 ; j++){
         cin >> num;
         m1[i][j] = num;
      }
   }
   
   util_filas2 = util_columnas1;
   
   cin >> util_columnas2;
   
   for (int i=0 ; i < util_filas2 ; i++){
      for (int j=0 ; j < util_columnas2 ; j++){
         cin >> num;
         m2[i][j] = num;
      }
   }
   
   // Cómputos
   
   for (int i=0 ; i < util_filas2 ; i++){
      for (int j=0 ; j < util_columnas2 ; j++){
         for(int k=0 ; k < util_columnas1 ; k++){
            producto += m1[i][k] * m2[k][j];
         }
         
         m_producto[i][j] = producto;
         producto = 0;
      }
   }
   
   util_filas = util_filas1;
   util_columnas = util_columnas2;
   
   // Salida
   
   cout << "\nMatriz producto: \n";
   for (int i=0 ; i < util_filas ; i++){   
      for (int j=0 ; j < util_columnas ; j++)
         cout << m_producto[i][j] << " ";
         
      cout << "\n";
   }

}
