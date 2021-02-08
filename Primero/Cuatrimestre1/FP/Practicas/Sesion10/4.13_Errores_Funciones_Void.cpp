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
No tendr�a ning�n error de compilaci�n.
En cambio, la variable cadena, al ser pasado POR VALOR, no cambiar�a su valor m�s all� de la funci�n.
Por tanto, la funci�n carece de prop�sito o sentido.
*/

// Ejemplo 2
void Imprime(double valor){
   double valor;
   cout << valor;
}

/*
Al declarar una variable con el mismo nombre que la variable pasada a la funci�n como par�metro,
ocurrir�a un error de compilaci�n.
En realidad no ser�a necesario declarar esa variable.
*/

// Ejemplo 3
void Cuadrado(int entero){
   return entero*entero;
}


/*
Un void no tiene return.
Quiz�, la soluci�n pasar�a por hacer un cout de entero*entero para mostrar por pantalla ese resultado,
a pesar de que no se almacenase en ninguna variable.
*/

