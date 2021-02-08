// Diego Santiago Ortiz

// Circunferencia con constantes

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
   const double PI = 6 * asin(0.5);   
   double radio;            
   double area, longitud;   

	cout << "Longitud de circunferencia y área de círculo"
        << "\nIntroduzca el valor del radio: ";
   cin >> radio;

   area     = PI * radio * radio;
   longitud = 2 * PI  * radio;

   cout << "\n\nEl área del círculo vale " << area;
   cout << "\n\nLa longitud de la circunferencia vale " << longitud;
}
