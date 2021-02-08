#include <iostream>
#include <cmath>
using namespace std;

int main(){
   double a, b, c;         // Parámetros de la ecuación
   double raiz1, raiz2;    // Raíces obtenidas
   double radical, denominador;
   
   cout << "\nIntroduce coeficiente de 2º grado: ";
   cin >> a;
   cout << "\nIntroduce coeficiente de 1er grado: ";
   cin >> b;
   cout << "\nIntroduce coeficiente independiente: ";
   cin >> c;
   
   if (a != 0) {
      denominador = 2*a;
      radical = sqrt(b*b - 4*a*c);
      raiz1 = (-b + radical) / denominador;
      raiz2 = (-b - radical) / denominador;
      cout << "\nLas raíces son" << raiz1 << " y " << raiz2;
   }
   else{
      raiz1 = -c/b;
      cout << "\nLa única raíz es " << raiz1;
   }
}
