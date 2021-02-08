////////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
////////////////////////////////////////////////////////////////////////////

// Ecuación de segundo grado

#include <iostream>
#include <cmath>
using namespace std;

enum class TipoEcuacion
   {una_raiz_doble, dos_raices_reales, ninguna_raiz_real, 
    recta_con_una_raiz, no_es_ecuacion};

int main(){
   int a, b, c;   // Nombres muy cortos, pero muy usados en la ecuación de segundo grado en los libros de Matemáticas
   int denominador;
   double radical, radicando, raiz1, raiz2;
   TipoEcuacion tipo_ecuacion;
   
   // Entrada de datos:
   
   cout << "\nIntroduce coeficiente de 2 o grado: ";
   cin >> a;
   cout << "\nIntroduce coeficiente de 1er grado: ";
   cin >> b;
   cout << "\nIntroduce coeficiente independiente: ";
   cin >> c;

   // Cómputos:
   
   if (a != 0) {
      denominador = 2*a;
      radicando = b*b - 4*a*c;      
      
      if (radicando == 0){
         raiz1 = -b / denominador;
         tipo_ecuacion = TipoEcuacion::una_raiz_doble;
      }
      else{
         if (radicando > 0){
            radical = sqrt(radicando);
            raiz1 = (-b + radical) / denominador;
            raiz2 = (-b - radical) / denominador;
            tipo_ecuacion = TipoEcuacion::dos_raices_reales;
         }
         else
            tipo_ecuacion = TipoEcuacion::ninguna_raiz_real;
      }
   }
   else{
      if (b != 0){
         raiz1 = -c / b;
         tipo_ecuacion = TipoEcuacion::recta_con_una_raiz;
      }
      else
         tipo_ecuacion = TipoEcuacion::no_es_ecuacion;
   }
   
   // Salida de Resultados:
   
   cout << "\n\n";
   
   if (tipo_ecuacion == TipoEcuacion::una_raiz_doble)
      cout << "Sólo hay una raíz doble: " << raiz1;
   else if (tipo_ecuacion == TipoEcuacion::dos_raices_reales)
      cout << "Las raíces son: " << raiz1 << " y " << raiz2;
   else if (tipo_ecuacion == TipoEcuacion::ninguna_raiz_real)
      cout << "No hay raíces reales.";
   else if (tipo_ecuacion == TipoEcuacion::recta_con_una_raiz)
      cout << "Es una recta. La única raíz es: " << raiz1;
   else if (tipo_ecuacion == TipoEcuacion::no_es_ecuacion)      // <- Realmente bastaría el else sin comprobar nada más
      cout << "No es una ecuación.";
      
      

   // Con un switch:
   /*
   switch (tipo_ecuacion){
      case TipoEcuacion::una_raiz_doble: 
         cout << "Sólo hay una raíz doble: " << raiz1;
         break;
      case TipoEcuacion::dos_raices_reales:
         cout << "Las raíces son: " << raiz1 << " y " << raiz2; 
         break;
      case TipoEcuacion::ninguna_raiz_real:
         cout << "No hay raíces reales.";
         break;
      case TipoEcuacion::recta_con_una_raiz:
         cout << "Es una recta. La única raíz es: " << raiz1;
         break;
      case TipoEcuacion::no_es_ecuacion:
         cout << "No es una ecuación.";
         break;
   }
   */
}

