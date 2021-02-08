// Diego Santiago Ortiz

// Generador aleatorio de números enteros

#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla
#include <iostream>
using namespace std;


class GeneradorAleatorioEnteros{
private:
   mt19937 generador_mersenne;   // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;

   long long Nanosec(){
      return chrono::high_resolution_clock::now().time_since_epoch().count();
   }
   
public:
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   
   GeneradorAleatorioEnteros(int min, int max){
      const int A_DESCARTAR = 70000; // Panneton et al. ACM TOMS Volume 32 Issue 1, March 2006
      auto semilla = Nanosec();
      
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }

   int Siguiente(){
      return distribucion_uniforme(generador_mersenne);
   }
};


int main(){  
   GeneradorAleatorioEnteros aleatorio1(1,5),
                             aleatorio2;
   int num_valores_a_generar; ;

   for (int i = 0; i < 4; i++){
      num_valores_a_generar = aleatorio1.Siguiente();
      cout << num_valores_a_generar << "  ";
      
      for (int j = 0; j < num_valores_a_generar; j++)
         cout << aleatorio2.Siguiente() << " ";
         
      cout << "\n";
   }

}
