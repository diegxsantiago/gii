//////////////////////////////////////////////////////////////////////////
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//////////////////////////////////////////////////////////////////////////

// Actualizaci�n salarial
// Este ejercicio se mejorar� usando constantes en vez de literales

#include <iostream>

using namespace std;

int main(){
   int    experiencia, edad, num_hijos;
   double salario_base, salario;
        
   cout << "Actualizaci�n salarial\n\n";
   cout << "Introduzca los siguientes datos del trabajador:\n";
   cout << "N�mero de a�os de experiencia en la empresa:\n";
   cin  >> experiencia;
   cout << "Salario mensual base:\n";
   cin  >> salario_base;
   cout << "Edad:\n";
   cin  >> edad;
   cout << "N�mero de hijos\n";
   cin  >> num_hijos;

   salario = salario_base;

   if (experiencia > 2){
      if (edad >= 45 && salario_base < 1300){
         salario = salario * 1.04;

         if (num_hijos > 2)
            salario = salario * 1.02;
      }
      else
         salario = salario * 1.01;
   }
   else
      salario = salario * 0.99;

   cout << "\n\n";
   cout << "Salario final: " << salario << "\n";
   
   // 4  1100  47   1   1144
   // 2  1100  47   1   1089
   // 4  1100  47   3   1166,8
}

