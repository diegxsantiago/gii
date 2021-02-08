#include <iostream>
#include <cmath>
using namespace std;

int main(){
   double a, b, c;         // Par�metros de la ecuaci�n
   double raiz1, raiz2;    // Ra�ces obtenidas
   double radical, denominador;
   
   cout << "\nIntroduce coeficiente de 2� grado: ";
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
      cout << "\nLas ra�ces son" << raiz1 << " y " << raiz2;
   }
   else{
      raiz1 = -c/b;
      cout << "\nLa �nica ra�z es " << raiz1;
   }
}
