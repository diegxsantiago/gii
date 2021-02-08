//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Circunferencia con constantes

/*
Re-escriba el ejercicio de la Circunferencia usando constantes
*/


#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
   const double PI = 6 * asin(0.5);    // Podemos usar una expresión en la definición de la cte. 
                                       // Mejor usar esta expresión que el literal 3.1415927
                                       // La expresión será más precisa y al tener menos dígitos, 
                                       // menos propensa a errores de transcripción. 
                                       
   
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
