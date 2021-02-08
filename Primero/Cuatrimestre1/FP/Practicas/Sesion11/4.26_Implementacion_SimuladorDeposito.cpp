// Diego Santiago Ortiz

// Implementación SimuladorDeposito

using namespace std;
#include <iostream>

class SimuladorDeposito{
   private:
      double capital;
      double interes;
   public:
      SimuladorDeposito()
      :capital(0), interes(0){
      }
      
      SimuladorDeposito(double cap, double inter){
         capital = cap;
         interes = inter;
      }
      
      void SetSimulador(double cap, double inter){
         capital = cap;
         interes = inter;
      }
      
      double InteresReinvertido(int plazo){
         int anio = 0;
         double generado = capital;
         
         while(anio < plazo){
            generado += generado * (interes/100.0);
            anio++;
         };
         
         return generado;
      }
      
      int AniosHastaObjetivo(double capital_objetivo){
         int anios = 0;
         double generado;
         
         while(capital < capital_objetivo){
            capital += capital * (interes/100.0);
            anios++;
         };
         
         return anios;
      }
};

int main(){
   
   SimuladorDeposito simulacion;
   int plazo,
       anios_transcurridos;
   double saldo,
          interes,
          capital_objetivo,
          capital_generado;
   
   cin >> saldo >> interes >> plazo >> capital_objetivo;
   
   simulacion.SetSimulador(saldo,interes);
   
   anios_transcurridos = simulacion.AniosHastaObjetivo(capital_objetivo);
   capital_generado = simulacion.InteresReinvertido(plazo);
   
   cout << "\nHarían falta " << anios_transcurridos << " anios para llegar a " 
        << capital_objetivo << " euros con un interes del " << interes << " por ciento.";
        
   cout << "\nEn " << plazo << " anios se alcanzaría un capital de "
        << capital_generado << " euros con un interés del " << interes << " por ciento.";
   
}
