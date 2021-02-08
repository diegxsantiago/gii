//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pal�ndromo e Invierte

/*
Tenga en cuenta la observaci�n al inicio de esta relaci�n
de problemas sobre la lectura de los caracteres. Para poder leer caracteres, inclu-
yendo los espacios en blanco, hay que usar caracter = cin.get() , en vez de
cin >> caracter .
Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un pal�ndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} ser�a
un pal�ndromo, pero {'a','c','b','a'} no lo ser�a. Si la secuencia tiene un
n�mero impar de componentes, la que ocupa la posici�n central es descartada,
por lo que {'a','b','j','b','a'} ser�a un pal�ndromo.

b) Invertir el vector. Si �ste conten�a, por ejemplo, los caracteres
{'m','u','n','d','o'} , despu�s de llamar al m�todo se quedar� con
{'o','d','n','u','m'} .

Construya un programa principal y declare un vector de caracteres de tama�o 100. Lea
las componentes considerando como terminador el car�cter # (�ste no forma parte
de la secuencia) y que no se introduzcan m�s de 100 caracteres. A continuaci�n, el
programa debe determinar si la secuencia es un pal�ndromo. En caso negativo, debe
invertirla y mostrar el resultado en pantalla.

Ejemplo de entrada: a# -- Salida correcta: Es un pal�ndromo
Ejemplo de entrada: abcba# -- Salida correcta: Es un pal�ndromo
Ejemplo de entrada: abccba# -- Salida correcta: Es un pal�ndromo
Ejemplo de entrada: abcdba#
-- Salida correcta: No es un pal�ndromo. Secuencia invertida: abdcba
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
   // Presentaci�n y lectura de los datos:

   cout << "Pal�ndromo e Invierte\n\n."
        << "Introduzca un m�ximo de " << TAMANIO << " caracteres, "
        << "con terminador " << TERMINADOR << "\n";
        
   total_utilizados = 0;
   caracter = cin.get();
   
   while (caracter != TERMINADOR && total_utilizados < TAMANIO){
      vector[total_utilizados] = caracter;
      total_utilizados++;
      caracter = cin.get();
   }

   
   //////////////////////////////////////////////////////////////////
   // Pal�ndromo:

   /*
   Primera versi�n.
   El sim�trico de la componente i es la componente 
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
   Segunda versi�n:
   M�s f�cil, si usamos dos apuntadores izda y dcha al inicio y al final del vector
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
      cout << "Es pal�ndromo";
   else{
      cout << "No Es pal�ndromo";
      cout << "\nComponentes del vector despu�s de invertirlo: <";
   
      for (int i = 0; i < total_utilizados; i++)
         cout  << vector[i];
         
      cout << ">";
   }
   
   cout << "\n\n";
}
