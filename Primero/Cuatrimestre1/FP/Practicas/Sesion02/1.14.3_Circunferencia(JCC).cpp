//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
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
	
   const double PI = 6 * asin(0.5);    // Podemos usar una expresi�n en la definici�n de la cte. 
                                       // Mejor usar esta expresi�n que el literal 3.1415927
                                       // La expresi�n ser� m�s precisa y al tener menos d�gitos, 
                                       // menos propensa a errores de transcripci�n. 
                                       
   
   double radio;            // Dato de entrada
   double area, longitud;   // Datos de salida

   cout << "Longitud de circunferencia y �rea de c�rculo"
        << "\nIntroduzca el valor del radio: ";
   cin >> radio;

   area     = PI * radio * radio;      // :-)
   longitud = 2 * PI  * radio;         // :-)

   cout << "\n\nEl �rea del c�rculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
}
