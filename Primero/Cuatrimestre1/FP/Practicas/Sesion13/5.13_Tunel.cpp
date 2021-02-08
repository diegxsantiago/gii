// Diego Santiago Ortiz

// Túnel con vector de objetos

#include <iostream>
#include <cmath>
#include <string>
#include "IV_FormateadorDoubles.cpp"
#include "V_Instante.cpp"
#include "V_VehiculoTunel.cpp"
using namespace std;

class Tunel{
private:
   double distancia_km;

   static const int MAX_NUM_VEHICULOS = 100;
   VehiculoTunel vehiculos[MAX_NUM_VEHICULOS];

   int total_entradas = 0;

   bool EsCorrectoIndice(int indice){
      return 0 <= indice && indice < total_entradas;
   }
public:
   Tunel(double distancia_km_tunel)
      :distancia_km(distancia_km_tunel)
   {
   }

   int TotalEntradas(){
      return total_entradas;
   }


   int Indice(string matricula){
      bool encontrada = false;
      int posicion = TotalEntradas();
      
      for (int i=0 ; i < TotalEntradas() && !encontrada ; i++){ 
         if (matricula == vehiculos[i].Matricula()){
            posicion = i;
            encontrada = true;
         }    
      }
      
      return posicion;
   }

   VehiculoTunel Vehiculo(int indice){
      VehiculoTunel vehiculo;
      
      if (EsCorrectoIndice(indice))
         vehiculo = vehiculos[indice];
      
      return vehiculos[indice];
   }

   void Entra(string matricula, Instante instante_entrada){
      vehiculos[TotalEntradas()].SetInstanteEntrada(instante_entrada);
      vehiculos[TotalEntradas()].SetMatricula(matricula);
      total_entradas++;
   }

   void Sale(string matricula, Instante instante_salida){
      vehiculos[Indice(matricula)].SetInstanteSalida(instante_salida);
   }

   bool HaSalido(int indice){
      return !vehiculos[indice].InstanteSalida().EsNulo();
   }
   
   double Velocidad(int indice){
      return distancia_km / vehiculos[indice].InstanteEntrada().DiferenciaCon(vehiculos[indice].InstanteSalida()).HorasTotalesDecimal();
   }
};

int main(){
   const char FIN_ENTRADA_FICHERO = '#';
   const char ENTRADA = 'E';
   const char SALIDA  = 'S';
   double long_tunel;
   char tipo_entrada_salida;

   string matricula;
   int hora, min, seg;
   
   FormateadorDoubles format_veloc("", " km/h");
   format_veloc.SetNumeroDecimales(1);

   cin >> long_tunel;

   Tunel tunel(long_tunel);

   cin >> tipo_entrada_salida;

   while (tipo_entrada_salida != FIN_ENTRADA_FICHERO){
      cin >> matricula;
      cin >> hora >> min >> seg;
      
      Instante instante(hora, min, seg);

      if (tipo_entrada_salida == ENTRADA)
         tunel.Entra(matricula, instante);
      else if (tipo_entrada_salida == SALIDA)   // Realmente no es necesario este if ya que sólo hay dos posibilidades
         tunel.Sale(matricula, instante);

      cin >> tipo_entrada_salida;
   }

   string cadena= "\n";
   for (int i = 0; i < tunel.TotalEntradas(); i++){

      cadena = cadena +
               "\n\nMatrícula:\t" + tunel.Vehiculo(i).Matricula() +
               "\nVelocidad:\t";

      string texto_salida;

      if (! tunel.HaSalido(i))
         texto_salida = "No ha salido";
      else
         texto_salida = format_veloc.GetCadena(tunel.Velocidad(i));

      cadena = cadena + texto_salida;
   }

   cout << cadena;
}

