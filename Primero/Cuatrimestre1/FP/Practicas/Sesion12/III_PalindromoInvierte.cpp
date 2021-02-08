//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Palíndromo e Invierte

/*
Tenga en cuenta la observación al inicio de esta relación
de problemas sobre la lectura de los caracteres. Para poder leer caracteres, inclu-
yendo los espacios en blanco, hay que usar caracter = cin.get() , en vez de
cin >> caracter .
Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un palíndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} sería
un palíndromo, pero {'a','c','b','a'} no lo sería. Si la secuencia tiene un
número impar de componentes, la que ocupa la posición central es descartada,
por lo que {'a','b','j','b','a'} sería un palíndromo.

b) Invertir el vector. Si éste contenía, por ejemplo, los caracteres
{'m','u','n','d','o'} , después de llamar al método se quedará con
{'o','d','n','u','m'} .

Construya un programa principal y declare un vector de caracteres de tamaño 100. Lea
las componentes considerando como terminador el carácter # (éste no forma parte
de la secuencia) y que no se introduzcan más de 100 caracteres. A continuación, el
programa debe determinar si la secuencia es un palíndromo. En caso negativo, debe
invertirla y mostrar el resultado en pantalla.

Ejemplo de entrada: a# -- Salida correcta: Es un palíndromo
Ejemplo de entrada: abcba# -- Salida correcta: Es un palíndromo
Ejemplo de entrada: abccba# -- Salida correcta: Es un palíndromo
Ejemplo de entrada: abcdba#
-- Salida correcta: No es un palíndromo. Secuencia invertida: abdcba
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main(){
   const char TERMINADOR = '#';    
   const int TAMANIO = 100;
   char vector[TAMANIO];
   int total_utilizados;
   char caracter;   
   bool es_palindromo;
   int  izda, dcha;
   char intercambia;

   //////////////////////////////////////////////////////////////////
   // Presentación y lectura de los datos:

   cout << "Palíndromo e Invierte\n\n."
        << "Introduzca un máximo de " << TAMANIO << " caracteres, "
        << "con terminador " << TERMINADOR << "\n";
        
   total_utilizados = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_utilizados < TAMANIO){
      vector[total_utilizados] = caracter;
      total_utilizados++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // Palíndromo:

   /*
   Primera versión.
   El simétrico de la componente i es la componente 
   total_utilizados - i - 1
   Recorremos con i desde 0 hasta la mitad del vector.      
   */
   
   es_palindromo = true;
   int ultimo = total_utilizados / 2; // incluso (total_utilizados - 1) / 2

   for (int i = 0; i <= ultimo && es_palindromo; i++){
      if (vector[i] != vector[total_utilizados - i - 1])
         es_palindromo = false;
         
      // o directamente:
      // es_palindromo = vector[i] != vector[total_utilizados - i + 1];
   }
   
   /*
   Segunda versión:
   Más fácil, si usamos dos apuntadores izda y dcha al inicio y al final del vector
   y los vamos avanzando / retrocediendo
   */
   
   es_palindromo = true;
   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha && es_palindromo){
      if (vector[izda] != vector[dcha])
         es_palindromo = false;
      else{
         izda++;
         dcha--;
      }
   }
   
   
   
   //////////////////////////////////////////////////////////////////
   // Invierte:   

   izda = 0;
   dcha = total_utilizados - 1;

   while (izda < dcha){
      intercambia = vector[izda];
      vector[izda] = vector[dcha];
      vector[dcha] = intercambia;
      izda++;
      dcha--;
   }
   
   //////////////////////////////////////////////////////////////////
   // Salida de resultados:
   cout << "\n";
   
   if (es_palindromo)
      cout << "Es palíndromo";
   else{
      cout << "No Es palíndromo";
      cout << "\nComponentes del vector después de invertirlo: <";
   
      for (int i = 0; i < total_utilizados; i++)
         cout  << vector[i];
         
      cout << ">";
   }
   
   cout << "\n\n";
}
