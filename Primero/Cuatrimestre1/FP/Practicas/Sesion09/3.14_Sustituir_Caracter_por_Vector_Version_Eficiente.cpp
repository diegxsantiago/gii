// Diego Santiago Ortiz

// Sustituir carácter por vector (versión eficiente)

#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '#';
   const int MAX_NUM_CARACT = 3e6;
   char v[MAX_NUM_CARACT],
        nuevo[MAX_NUM_CARACT];
   char a_borrar;
   char car;
   int i,
       util_v,
       util_nuevo,
       apariciones_a_borrar = 0,
       pos_lec = 0,
       pos_esc = 0;

   // Lectura
   car = cin.get();
   i = 0;
   
   while (car != TERMINADOR){
      v[i] = car;
      car = cin.get();
      i++;
   }
   
   util_v = i;
   
   car = cin.get();
   i = 0;
   
   while (car != TERMINADOR){
      nuevo[i] = car;
      car = cin.get();
      i++;
   }
   
   util_nuevo = i;
   i=0;
   
   a_borrar = cin.get();

   // Cómputos
   
   for (int j=0 ; j < util_v ; j++){
      if (v[j] == a_borrar)
         apariciones_a_borrar++;
   }
   
   pos_lec = util_v - 1;
   util_v += (apariciones_a_borrar * (util_nuevo - 1));
   pos_esc = util_v - 1;
   
   while(apariciones_a_borrar > 0){
      if (v[pos_lec] == a_borrar){
         
         for (int k=util_nuevo - 1 ; k >= 0 ; k--){
            v[pos_esc] = nuevo[k];
            pos_esc--;
         }
         apariciones_a_borrar--;
      }
      else{
         v[pos_esc] = v[pos_lec];
         pos_esc--;
      }
      
      pos_lec--;     
   }
   
   // Salida
   
   for (int i = 0; i < util_v; i++)
      cout << v[i];
}
