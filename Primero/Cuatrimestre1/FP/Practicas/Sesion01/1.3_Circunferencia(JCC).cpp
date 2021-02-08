//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Circunferencia

/*
Cree un programa que nos pida la longitud del radio y calcule el área
del círculo y la longitud de la circunferencia correspondientes. Finalmente, el programa
mostrará en pantalla los resultados. Recuerde que:
área circulo = pi * r * r
longitud circunferencia = 2 * pi * r
Se proponen las siguientes alternativas.
a) Pedir al usuario que introduzca el valor de pi
b) Usar el literal 3.1416 donde sea necesario.
c) Usar un dato llamado pi, asignarle el literal 3.1416 y usarlo donde sea necesario.
¿Cuál elegiría y por qué?
*/


#include <iostream>
#include <cmath>

using namespace std;

int main(){
   /*
   ¿Le pedimos al usuario que introduzca el valor de pi?
   La respuesta es que no.
   
   Un principio básico en programación:
      No se le pedirá al usuario que introduzca cualquier dato
      que pueda calcularse dentro del programa.
   
   Este mismo principio lo extenderemos cuando veamos las funciones 
   y las clases.
   */
   
   /*   
   Si no le pedimos al usuario que introduzca el valor de pi,
   ¿usamos entonces el literal 3.1416 donde sea necesario?
   
   double radio;            // Dato de entrada
   double area, longitud;   // Datos de salida

   cout << "Introduzca el valor del radio: ";
   cin >> radio;

   area     = 3.1416 * radio * radio;   // :-(
   longitud = 2 * 3.1416  * radio;      // :-(

   cout << "\n\nEl área del círculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
   cout << "\n\n";
   */

   /*
   Esta solución no es aceptable ya que si, por ejemplo, queremos darle
   mayor precisión a Pi y utilizar el valor 3.1415927
   tenemos que hacer un cambio del valor tantas veces como aparezca,
   lo cual es muy propenso a errores.

   Un principio básico en programación:
     No debemos repetir código

   A lo largo del curso detallaremos lo que pretendemos decir con esta frase.
   Por ahora, no debemos repetir la aparición del literal 3.1416

   Solución:
      Usamos un dato, le asignamos un valor y usamos dicho dato
      en expresiones posteriores.
   */

   double PI = 6 * asin(0.5);
   
   double radio;            // Dato de entrada
   double area, longitud;   // Datos de salida

   cout << "Longitud de circunferencia y área de círculo"
        << "\nIntroduzca el valor del radio: ";
   cin >> radio;

   area     = PI * radio * radio;      // :-)
   longitud = 2 * PI  * radio;         // :-)

   cout << "\n\nEl área del círculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
}
