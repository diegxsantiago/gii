// Diego Santiago Ortiz

// Contiene débil

#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '#';
   const int MAX_NUM_CARACT = 200;
   char grande[MAX_NUM_CARACT],
        peque[MAX_NUM_CARACT];
   char car;
   int util_grande,
       util_peque;
   int num_leidos,
       index_peque = 0;
   bool encontrado,
        seguir_buscando = true;
   
   
   cout << "Búsqueda -débil- de un vector de carteres dentro de otro\n"
        << "Introduzca los cartereses del vector grande, con terminador "
        << TERMINADOR << "\n"
        << "A continuación introduzca  los caracterees del vector pequeño,"
        << " usando el mismo terminador.\n\n";

   // Lectura

   car = cin.get();
   num_leidos = 0;

   while (car != TERMINADOR && num_leidos < MAX_NUM_CARACT){
      grande[num_leidos] = car;
      car = cin.get();
      num_leidos++;
   }

   util_grande = num_leidos;
   
   car = cin.get();
   num_leidos = 0;

   while (car != TERMINADOR && num_leidos < MAX_NUM_CARACT){
      peque[num_leidos] = car;
      car = cin.get();
      num_leidos++;
   }

   util_peque = num_leidos;

   // Cómputos
   
   for (int i=0 ; i < util_grande && index_peque < util_peque; i++){
      if (grande[i] == peque[index_peque])
         index_peque++;
   }
   
   encontrado = index_peque == util_peque;
   
   // Salida
   
   if (encontrado)
      cout << "\nEl vector pequenio esta dentro del grande";
   else
      cout << "\nEl vector pequenio NO esta dentro del grande";
   
}

