// Diego Santiago Ortiz

// Diseño SecuenciaCaracteres

using namespace std;

class SecuenciaCaracteres{
   private:
      static const int TAM = 100;
      char caracteres[TAM];
      int utilizados;               /* Es mejor controlar el tamaño de SecuenciaCaracteres porque 
                                       este es un valor que nos puede servir en algún momento */
   public:
      void Aniade(char a);
      
      int Utilizados();
      
      void Invertir();
      
      int PrimeraOcurrencia(char a_buscar);
      
      void EliminaOcurrencias(char a_borrar);
};

int main(){
   
   SecuenciaCaracteres secuencia;
   char aux;
   int tamanio,
       i;
   
   secuencia.Aniade(aux);
   
   tamanio = secuencia.Utilizados();
   
   secuencia.Invertir();
   
   i = secuencia.PrimeraOcurrencia(aux);
   
   secuencia.EliminaOcurrencias(aux);
    
}
