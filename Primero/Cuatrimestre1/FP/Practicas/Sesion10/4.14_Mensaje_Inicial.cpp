// Diego Santiago Ortiz

// Mensaje inicial

#include <iostream>
#include <string>
using namespace std;

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

void ImprimeDelimitador(char patron, int n){
   
   cout << "\n";
   for (int i=0 ; i < n ; i++)
      cout << patron;
   cout << "\n";
}

void MensajeInicial(char patron, string cadena){
   
   ImprimeDelimitador(patron,cadena.size());
   cout << cadena;
   ImprimeDelimitador(patron,cadena.size());
}



int main(){
   const char TERMINADOR = '@';
   string cadena;
   char patron,
        terminador;
   
   patron = cin.get();
   
   cadena = LeeString(TERMINADOR);
   
   MensajeInicial(patron,cadena);

}
