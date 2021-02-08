// Diego Santiago Ortiz

// Decimal redondeado

#include <iostream>  
#include <cmath> 
using namespace std;

double Potencia(double la_base, int el_exponente){
   
   double potencia;
   int exponente_positivo;

   exponente_positivo = abs(el_exponente);
   potencia = 1;

   for (int i = 1; i <= exponente_positivo; i++)
      potencia = potencia * la_base;

   if (el_exponente < 0)
      potencia = 1/potencia;

   return potencia;
}

double Redondea(double real, int num_decim){
   
   double desplazamiento; 
   
   desplazamiento = Potencia(10, num_decim);
   real = round(real * desplazamiento);  
   real = real / desplazamiento;

   return real;
}

int main(){
   
   double real,
          num_decim;
   
   cin >> real >> num_decim;
   
   real = Redondea(real,num_decim);
   
   cout << "Número redondeado: " << real;
}
