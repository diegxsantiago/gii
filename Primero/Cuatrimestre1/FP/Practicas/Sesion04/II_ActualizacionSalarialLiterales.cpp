//////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//////////////////////////////////////////////////////////////////////////

// Actualización salarial
// Este ejercicio se mejorará usando constantes en vez de literales

#include <iostream>

using namespace std;

int main(){
   int    experiencia, edad, num_hijos;
   double salario_base, salario;
        
   cout << "Actualización salarial\n\n";
   cout << "Introduzca los siguientes datos del trabajador:\n";
   cout << "Número de años de experiencia en la empresa:\n";
   cin  >> experiencia;
   cout << "Salario mensual base:\n";
   cin  >> salario_base;
   cout << "Edad:\n";
   cin  >> edad;
   cout << "Número de hijos\n";
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

