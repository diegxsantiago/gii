//////////////////////////////////////////////////////////////////////////
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//////////////////////////////////////////////////////////////////////////

// Actualizaci�n salarial

#include <iostream>

using namespace std;

int main(){
   const int MIN_EXPER_ALTA   = 2,
             MIN_FAM_NUMEROSA = 2,
             MIN_EDAD_SENIOR  = 45;
   const double MAX_SAL_BAJO  = 1300;
   
   const double INDV_SENIOR_Y_SAL_BAJO    = 1.04,
                INDV_NO_SENIOR_Y_SAL_BAJO = 1.01,
                INDV_FAM_NUMEROSA         = 1.02,
                INDV_SIN_EXPERIENCIA      = 0.99;
   
   int    experiencia, edad, num_hijos;
   double salario_base, salario;
   double indv_salario;
   bool   es_experiencia_alta, es_familia_numerosa, es_edad_senior,
          es_salario_bajo;
        
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

   es_experiencia_alta = experiencia  > MIN_EXPER_ALTA;
   es_familia_numerosa = num_hijos > MIN_FAM_NUMEROSA;
   es_salario_bajo     = salario_base < MAX_SAL_BAJO;
   es_edad_senior      = edad >= MIN_EDAD_SENIOR;

   if (es_experiencia_alta){
      if (es_edad_senior && es_salario_bajo){
         indv_salario = INDV_SENIOR_Y_SAL_BAJO;

         if (es_familia_numerosa)
            indv_salario = indv_salario * INDV_FAM_NUMEROSA;
      }
      else
         indv_salario = INDV_NO_SENIOR_Y_SAL_BAJO;
   }
   else
      indv_salario = INDV_SIN_EXPERIENCIA;

   salario = salario * indv_salario;

   cout << "\n\n";
   cout << "\nSalario final: " << salario;
   
   // 4  1100  47   1   1144
   // 2  1100  47   1   1089
   // 4  1100  47   3   1166,8
}


/*
// En esta versi�n, s�lo se usan constantes para los l�mites:

int main(){
   const int MIN_EXPER_ALTA = 2,
             MIN_FAM_NUMEROSA = 2,
             MIN_EDAD_SENIOR      = 45,
   const double MAX_SAL_BAJO  = 1300;

   int    experiencia, edad, num_hijos;
   double salario_base, salario;
   double indv_salario;
   bool   es_experiencia_alta, es_familia_numerosa, es_edad_senior,
          es_salario_bajo, es_aplicable_subida;

   cout << "Subida salarial\n";
   cout << "\nIntroduzca los siguientes datos del trabajador:";
   cout << "\nSalario mensual base: ";
   cin  >> salario_base;
   cout << "\nN�mero de a�os de experiencia en la empresa: ";
   cin  >> experiencia;
   cout << "\nEdad: ";
   cin  >> edad;
   cout << "\nN�mero de hijos ";
   cin  >> num_hijos;

   salario = salario_base;

   es_experiencia_alta = experiencia  > MIN_EXPER_ALTA;
   es_familia_numerosa = num_hijos > MIN_FAM_NUMEROSA;
   es_salario_bajo     = salario_base < MAX_SAL_BAJO;
   es_edad_senior      = edad >= MIN_EDAD_SENIOR;
   es_aplicable_subida = es_experiencia_alta;

   if (es_aplicable_subida){
      if (es_edad_senior && es_salario_bajo){
         indv_salario = 1.04;

         if (es_familia_numerosa)
            indv_salario = indv_salario * 1.02;
      }
      else
         indv_salario = 1.01;
   }
   else
      indv_salario = 0.99;

   salario = salario * indv_salario;

   cout << "\n\n";

   if (es_aplicable_subida)
      cout << "Se aplic� al menos una subida.";
   else
      cout << "No se aplic� ninguna subida.";

   cout << "\nSalario final: " << salario;

   // 1100  4  47   1   1144
   // 1100  2  47   1   1089
   // 1100  4  47   3   1166,8
}
*/
