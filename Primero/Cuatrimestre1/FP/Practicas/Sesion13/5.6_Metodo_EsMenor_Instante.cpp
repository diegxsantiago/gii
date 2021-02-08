// Diego Santiago Ortiz

#include <cmath>
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Instante en un día -> hora, minuto, segundo (desde las 0h)

/*
class Instante
   Instante(int hora, int minuto, int segundo)
   Instante(int segundos_totales)
   Instante()
   int Hora()
   int Minuto()
   int Segundo(){
   void SetHoraMinutoSegundo(int hora, int minuto, int segundo)
   void SetSegundosTotales(int segundos_totales)
   void SumaleSegundos(int segundos_a_aniadir)
   void RestaleSegundos(int segundos_a_quitar)
   bool EsNulo()
   int SegundosTotales()   
   int MinutosTotales()
   double MinutosTotalesDecimal()
   double HorasTotalesDecimal()
   string ToString()
   
   // Métodos NUEVOS:
   
   void Sumale(Instante otro_instante)
   void Restale(Instante otro_instante)
   Instante Suma(Instante otro_instante)
   Instante DiferenciaCon(Instante otro_instante)
*/


class Instante{
private:    
   /*
   MUY IMPORTANTE:
      NO INCLUIMOS COMO DATO MIEMBRO NADA QUE SE PUEDA OBTENER A PARTIR
      DE LOS OTROS DATOS MIEMBRO,COMO POR EJEMPLO SEGUNDOS_TOTALES
      LO QUE HAREMOS SERÁ PROPORCIONAR UN MÉTODO QUE CALCULE SEGUNDOS_TOTALES
   */
   
   /*
   Sobre las ctes:
   
      Hemos decidido que las ctes SEG_1_MIN, MIN_1_HORA y HOR_1_DIA
      sean private ya que hemos supuesto que no se necesitan fuera de la clase.
      Pero podría darse el caso de que sí se necesitasen.
      Por ejemplo, si desde el main queremos hacer un filtro de entrada de datos para los
      minutos, por ejemplo, necesitaríamos saber el máximo (60)
      En este caso, podemos resolverlo de dos formas:
      
      a) Poner dichas ctes como ctes globales 
      
      b) Proporcionar métodos Get a la clase Instante 
         para que devuelva los valores de dichas ctes.
         El problema de esta opción es que no podríamos
         dimensionar un vector, por ejemplo, con estos valores
         ya que el valor devuelto por el método Get no sería un const.
         
      c) También se pueden poner las constantes SEG_1_MIN, MIN_1_HORA
         y HOR_1_DIA como datos miembros públicos: Sería la única excepción a la norma
         de usar siempre datos miembros privados.
         De esta forma, desde el main, si tenemos 
            Instante un_instante;
         podemos acceder a dichos datos miembros. 
         Se puede hacer de dos formas (pero siempre declarándolas como "static const"):
         
         i)  objeto.dato_miembro
            
             En nuestro ejemplo sería:
            
             instante.SEG_1_MIN
            
         ii) clase::dato_miembro
            
             En nuestro ejemplo sería:
   
             Instante::SEG_1_MIN
   */
         
   static const int  SEG_1_MIN = 60,
                     MIN_1_HORA = 60,
                     HOR_1_DIA = 24;  
   
   int hor = -1;
   int min = -1;
   int seg = -1;
   
   bool EsCorrectoSeg(int segundo){
      return 0 <= segundo && segundo < SEG_1_MIN;
   }
   bool EsCorrectoMin(int minuto){
      return 0 <= minuto && minuto < MIN_1_HORA;
   }
   bool EsCorrectoHor(int hora){
      return 0 <= hora  && hora < HOR_1_DIA;
   }
   bool EsCorrecto (int hora, int minuto, int segundo){
      return  EsCorrectoHor(hora) && 
              EsCorrectoMin(minuto) && 
              EsCorrectoSeg(segundo);
   }

public:
   // Incluimos un constructor sin parámetros para poder crear fácilmente vectores de objetos.
   // Al construir un objeto Instante llamando al constructor sin parámetros
   // éste se quedará como un "zombie". Lo identificaremos poniendo sus datos miembro
   // a -1 y proporcionando el método EsNulo()
   //    Instante un_instante;  <-  -1, -1, -1
   //    bool es_nulo = un_instante.EsNulo();   <- true
   Instante(){      
   }
   
   // Prec: las horas, minutos y segundos son correctos
   Instante(int hora, int minuto, int segundo){
      SetHoraMinutoSegundo(hora,  minuto,  segundo);
   }
   
   // Prec: los segundos son correctos
   Instante(int segundos_totales){
      SetSegundosTotales(segundos_totales);
   }

   int Hora(){
      return hor;
   }

   int Minuto(){
      return min;
   }

   int Segundo(){
      return seg;
   }

   void SetHoraMinutoSegundo(int hora, int minuto, int segundo){
      if (EsCorrecto(hora, minuto, segundo)){
         hor = hora;
         min = minuto;
         seg = segundo;
      }
   }

   void SetSegundosTotales(int segundos_totales){
      int minutos_enteros;
      const int SEG_1_DIA = SEG_1_MIN * MIN_1_HORA * HOR_1_DIA;
                                    
      if (segundos_totales < SEG_1_DIA){
         seg = segundos_totales % SEG_1_MIN;
         minutos_enteros  = segundos_totales / SEG_1_MIN;
         min  = minutos_enteros % MIN_1_HORA;
         hor  = minutos_enteros / MIN_1_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         SetSegundosTotales(
            SegundosTotales() 
            + 
            segundos_a_aniadir);       
   }
   
   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         SetSegundosTotales(
            SegundosTotales() 
            -
            segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hor, min, seg);  
   }

   int SegundosTotales(){
      return seg  +  SEG_1_MIN*(hor * MIN_1_HORA + min);
   }
   
   int MinutosTotales(){
      return trunc(MinutosTotalesDecimal());
   }

   double MinutosTotalesDecimal(){
      return 1.0 * SegundosTotales() / SEG_1_MIN;
   }

   double HorasTotalesDecimal(){
      return 1.0 * MinutosTotalesDecimal() / MIN_1_HORA;
   }

   string ToString(){
      return to_string(hor) + "h, " +
             to_string(min) + "\', " +
             to_string(seg) + "\'\'";
   }

   ///////////////////////////////////////////////////////////////////////
   // Métodos NUEVOS
   ///////////////////////////////////////////////////////////////////////


   void Sumale(Instante otro_instante){
      SumaleSegundos(otro_instante.SegundosTotales());
   }
   
   void Restale(Instante otro_instante){
      RestaleSegundos(otro_instante.SegundosTotales());
   }
   
   Instante Suma(Instante otro_instante){
      Instante suma;
      suma.SetSegundosTotales(SegundosTotales());
      suma.SumaleSegundos(otro_instante.SegundosTotales());
      
      return suma;
   }

   Instante DiferenciaCon(Instante otro_instante){
      int segundos_iniciales, segundos_finales, segundos_diferencia;

      segundos_iniciales = SegundosTotales();
      segundos_finales   = otro_instante.SegundosTotales();
      segundos_diferencia = abs(segundos_finales - segundos_iniciales);

      Instante diferencia_con;

      diferencia_con.SetSegundosTotales(segundos_diferencia);

      return diferencia_con;
   }
   
   ///////////////////////////////////////////////////////////////////////
   // Métodos Diego Santiago Ortiz
   ///////////////////////////////////////////////////////////////////////
   
   bool EsMenor(Instante instante_a_comparar){
      
      return Hora() < instante_a_comparar.Hora() 
             || ( Hora() == instante_a_comparar.Hora() && ( Minuto() < instante_a_comparar.Minuto() ) )
             || ( Minuto() == instante_a_comparar.Minuto() && (Segundo() < instante_a_comparar.Segundo()) );
   }
};

int main(){
   int horas,
       minutos,
       segundos;
       
   cin >> horas >> minutos >> segundos;
   
   Instante un_instante(horas,minutos,segundos);
   
   cin >> horas >> minutos >> segundos;
   
   Instante otro_instante(horas,minutos,segundos);
   
   cout << "El primero ";
   if(! un_instante.EsMenor(otro_instante))
      cout << "no ";
   cout << "es anterior";
   
}
