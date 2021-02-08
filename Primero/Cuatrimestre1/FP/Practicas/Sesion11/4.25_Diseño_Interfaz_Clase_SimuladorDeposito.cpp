// Diego Santiago Ortiz

// Diseño SimuladorDeposito

using namespace std;

class SimuladorDeposito{
   private:
      double saldo;
      double interes;
   public:
      SimuladorDeposito();
      SimuladorDeposito(double sald, double inter);
      
      void SetSimulador(double sald, double inter);
      
      double InteresReinvertido(int plazo);
      
      int AniosHastaObjetivo(double capital_objetivo);
};

int main(){
   
   SimuladorDeposito simulacion;
   int plazo,
       anios_transcurridos;
   double capital_objetivo,
          capital_generado;
   
   anios_transcurridos = simulacion.AniosHastaObjetivo(capital_objetivo);
   
   capital_generado = simulacion.InteresReinvertido(plazo);
}


