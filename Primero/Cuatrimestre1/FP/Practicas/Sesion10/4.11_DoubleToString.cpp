// Diego Santiago Ortiz

// DoubleToString

#include <iostream>  
#include <cmath>
#include <string> 
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

string LeeString(char terminador){
   string cadena;
   char caracter;
   
   caracter = cin.get();
   
   while (caracter != terminador){
      cadena.push_back(caracter);
      caracter = cin.get();
   }
   
   return cadena;
}

string EliminaUltimos(string original, char a_borrar){
   
   string eliminados = original;
   
   while(!eliminados.empty() && (eliminados.back() == a_borrar || eliminados.back() == '.'))
      eliminados.erase(eliminados.size() - 1);
   
   return eliminados;
}

string DoubleToString(double num, int cifras){
   
   string convertido;
   
   if (cifras > 6)
      cifras = 6;
   
   num = Redondea(num,cifras);
   
   convertido = to_string(num);
   
   convertido = EliminaUltimos(convertido,'0');
   
   return convertido;
}

int main(){
   
   double real,
          num_decim;
   string num;
   
   cin >> real >> num_decim;
   
   num = DoubleToString(real,num_decim);
   
   cout << num;

}
