// Diego Santiago Ortiz

// Dinero con datos miembro p�blicos

#include <iostream>
using namespace std;

class Dinero{
   public:
      int euros,
          centimos;
         
      void SetEurosCentimos(int eur, int cent){
         while(cent > 100){
            cent -= 100;
            eur++;
         }
         
         euros = eur;
         centimos = cent;
      }
};

int main(){
   
   Dinero un_producto,
          otro_producto,
          producto_final;
   int euros, centimos;
   
   // Lectura de datos
   cout << "Introduzca los euros y c�ntimos del primer producto y los euros y c�ntimos del segundo producto: \n";
   cin >> euros >> centimos;
   un_producto.SetEurosCentimos(euros,centimos);  
   cin >> euros >> centimos;
   otro_producto.SetEurosCentimos(euros,centimos);
   
   // C�mputos
   producto_final.SetEurosCentimos(un_producto.euros + otro_producto.euros, un_producto.centimos + otro_producto.centimos);
          
   // Salida
   cout << "La suma es " << producto_final.euros << " euros y " << producto_final.centimos << " c�ntimos";
   
}
