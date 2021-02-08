// Diego Santiago Ortiz

// Elimina últimos

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

string EliminaUltimos(string original, char a_borrar){
   
   string eliminados = original;
   
   if (eliminados != ""){
      while (eliminados[eliminados.size() - 1] == a_borrar)
          eliminados.erase(eliminados.size() - 1);
   }
   
   return eliminados;
}

int main(){
   const char TERMINADOR = '#';
   char caracter, a_borrar;
   string cadena, eliminados;
 
   // Lectura
   
   cout << "Introduzca caracteres con terminador " << TERMINADOR << "\n";
        
   cadena = LeeString(TERMINADOR);
   
   a_borrar = cin.get();
   
   eliminados = EliminaUltimos(cadena, a_borrar);
   
   /* Para modificar la cadena original con el resultado de quitarle los últimos caracteres,
   llamaríamos a la función de la siguiente forma:
   
   cadena = EliminaUltimos(cadena, a_borrar);
   */
   
   cout << eliminados;
}
