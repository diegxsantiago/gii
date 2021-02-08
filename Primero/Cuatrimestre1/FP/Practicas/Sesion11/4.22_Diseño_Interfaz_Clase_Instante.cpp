// Diego Santiago Ortiz

// Diseño Instante

using namespace std;

class Instante{
   private:
      int horas,
          minutos,
          segundos;
   public:
      void SetInstante(int seg);
      
      int GetTotalSegundos();
      
      int GetTotalMinutos();
      
      int GetSegundosRestantes();
};

int main(){
   
   Instante instante;
   int seg,
       seg_transcurridos,
       min_transcurridos,
       seg_restantes;
   
   instante.SetInstante(seg);
   
   seg_transcurridos = instante.GetTotalSegundos();
   
   min_transcurridos = instante.GetTotalMinutos();
   
   seg_restantes = instante.GetSegundosRestantes();
    
}
