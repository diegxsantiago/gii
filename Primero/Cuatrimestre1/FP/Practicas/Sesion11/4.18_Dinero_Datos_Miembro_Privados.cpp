// Diego Santiago Ortiz

// Dinero con datos miembro privados

#include <iostream>
using namespace std;

class Dinero{
   private:
      int euros,
          centimos;
          
   public:      
      void SetEurosCentimos(int eur, int cent){
         while(cent > 100){
            cent -= 100;
            eur++;
         }
         
         euros = eur;
         centimos = cent;
      }
      
      int GetEuros(){
         return euros;
      }
      
      int GetCentimos(){
         return centimos;
      }
};

int main(){
   
   Dinero un_producto,
          otro_producto,
          producto_final;
   int euros, centimos;
   
   // Lectura de datos
   cout << "Introduzca los euros y céntimos del primer producto y los euros y céntimos del segundo producto: \n";
   cin >> euros >> centimos;
   un_producto.SetEurosCentimos(euros,centimos);  
   cin >> euros >> centimos;
   otro_producto.SetEurosCentimos(euros,centimos);
   
   // Cómputos
   producto_final.SetEurosCentimos(un_producto.GetEuros() + otro_producto.GetEuros(), un_producto.GetCentimos() + otro_producto.GetCentimos());
          
   // Salida
   cout << "La suma es " << producto_final.GetEuros() << " euros y " << producto_final.GetCentimos() << " céntimos";
   
}
