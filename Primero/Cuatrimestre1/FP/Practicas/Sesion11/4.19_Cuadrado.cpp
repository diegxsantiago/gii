// Diego Santiago Ortiz

// Cuadrado

#include <iostream>
#include <string>
using namespace std;

class Cuadrado{
   private:
      double x,
             y,
             lado;
   public:
      void SetCuadrado(double abcisas, double ordenadas, double lad){
         x = abcisas;
         y = ordenadas;
         lado = lad;
      }
      
      double GetAbcisaEsquina(){
         return x;
      }
      
      double GetOrdenadaEsquina(){
         return y;
      }
      
      double GetLado(){
         return lado;
      }
      
      double Area(){
         return lado*lado;
      }
      
      double Perimetro(){
         return 4*lado;
      }
      
      string ToString(){
         return to_string(x) + " , " + to_string(y);
      }
};


int main(){  
   const string MSJ_COORDENADAS = "\nCoordenadas: ";
   const string MSJ_LONGITUD = "\nLongitud: ";
   const string MSJ_AREA = "\nÁrea: ";
   const string MSJ_PERIMETRO = "\nPerímetro: ";
   double esquina_x, esquina_y, long_parcela;

   Cuadrado parcela,
            otra_parcela;

   cout << "Introduzca los datos de dos cuadrados:"
        << "\nEn primer lugar las dos coordenadas de la esquina inferior izquierda"
        << "\nA continuación la longitud de su lado\n";   
           
   cin >> esquina_x;   
   cin >> esquina_y;   
   cin >> long_parcela;

   parcela.SetCuadrado(esquina_x,esquina_y,long_parcela);
   
   cin >> esquina_x;   
   cin >> esquina_y;   
   cin >> long_parcela;

   otra_parcela.SetCuadrado(esquina_x,esquina_y,long_parcela);
   
   // Llame a los métodos correspondientes de parcela:
  
   cout << MSJ_COORDENADAS << parcela.ToString()
        << MSJ_LONGITUD    << parcela.GetLado() 
        << MSJ_AREA        << parcela.Area()
        << MSJ_PERIMETRO   << parcela.Perimetro();
   
   cout << "\n";
   
   // Llame a los métodos correspondientes de otra_parcela:

   cout << MSJ_COORDENADAS << otra_parcela.ToString()
        << MSJ_LONGITUD    << otra_parcela.GetLado() 
        << MSJ_AREA        << otra_parcela.Area()
        << MSJ_PERIMETRO   << otra_parcela.Perimetro();
}


