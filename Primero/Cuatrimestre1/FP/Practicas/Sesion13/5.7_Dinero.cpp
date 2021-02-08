// Diego Santiago Ortiz

//////////////////////////////////////////////////////////////////////////
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//////////////////////////////////////////////////////////////////////////

// Clase Dinero

#include <iostream>
using namespace std;

class Dinero{
private:
   long long eur_enteros    = 0;  // Tiene sentido un valor por defecto. 0 es una cantidad real
   long long cent_enteros = 0;

   bool EsCorrecta(int cantidad){
      return cantidad > 0;
   }
public:      
   long long Euros(){
      return eur_enteros;      
   }
   
   long long Centimos(){
      return cent_enteros;      
   }
   
   void SetEurCent(long long euros, long long centimos){
      if (EsCorrecta(euros) && EsCorrecta(centimos)){
         cent_enteros = centimos % 100;
         eur_enteros    = euros + centimos / 100;
      }
   }
   
   ///////////////////////////////////////////////////////////////////////
   // Métodos Diego Santiago Ortiz
   ///////////////////////////////////////////////////////////////////////
   
   void Sumale(Dinero otro_dinero){
      SetEurCent(Euros() + otro_dinero.Euros() , Centimos() + otro_dinero.Centimos());  
   }
   
   Dinero Suma(Dinero otro_dinero){
      Dinero suma;
      suma.SetEurCent(Euros(),Centimos());
      suma.Sumale(otro_dinero);
      
      return suma;
   }
};

int main(){
   long long  euros, centimos;
   Dinero dinero1, dinero2;
   Dinero dinero_suma;
   
   cin >> euros >> centimos;
   dinero1.SetEurCent(euros, centimos);

   cin >> euros >> centimos;
   dinero2.SetEurCent(euros, centimos);
   
   dinero1.Sumale(dinero2);
   dinero_suma = dinero1.Suma(dinero2);
   
   cout << dinero1.Euros() << " " << dinero1.Centimos() << " "
        << dinero_suma.Euros() << " " << dinero_suma.Centimos();
}
