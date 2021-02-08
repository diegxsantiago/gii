// Diego Santiago Ortiz

// Errores en funciones void

#include <iostream>
#include <string>
using namespace std;

// Ejemplo 1
void EliminaUltimo(string cadena){
   cadena.pop_back();
}

/*
No tendría ningún error de compilación.
En cambio, la variable cadena, al ser pasado POR VALOR, no cambiaría su valor más allá de la función.
Por tanto, la función carece de propósito o sentido.
*/

// Ejemplo 2
void Imprime(double valor){
   double valor;
   cout << valor;
}

/*
Al declarar una variable con el mismo nombre que la variable pasada a la función como parámetro,
ocurriría un error de compilación.
En realidad no sería necesario declarar esa variable.
*/

// Ejemplo 3
void Cuadrado(int entero){
   return entero*entero;
}


/*
Un void no tiene return.
Quizá, la solución pasaría por hacer un cout de entero*entero para mostrar por pantalla ese resultado,
a pesar de que no se almacenase en ninguna variable.
*/

