////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

// Lector de objetos de la clase SecuenciaCaracteres

#include <iostream>
#include <string>
using namespace std;

/*
LectorSecuencias:
   Permite la lectura de objetos de la clase SecuenciaCaracteres.
   Condiciones de parada que se pueden establecer (conjuntamente):
      - Hasta llegar a un terminador
      - Hasta completar un número fijo de caracteres
     
     
LectorSecuencias{
   void SetTerminador(char terminador_entrada)
   void SetTope(int num_valores_a_leer)
   void ResetRestricciones()
   SecuenciaCaracteres Lee()
}

Ejemplo de uso:
   SecuenciaCaracteres sec1, sec2;
   LectorSecuencias lector;
   
   lector.SetTerminador('#');
   lector.SetTope(5);

   sec1 = lector.Lee(); 
   sec2 = lector.Lee();
   
   lector.SetTope(1);
   ......
*/
class LectorSecuenciaCaracteres{
private:
   char terminador;
   int tope;
   int capacidad_maxima;

   bool FlujoAbierto(){
      return !cin.fail();
   }
   
public:
   LectorSecuenciaCaracteres(){
      ResetRestricciones();
   }
   
   void SetTerminador (char terminador_entrada){
      terminador = terminador_entrada;
   }
   
   void SetTope(int num_valores_a_leer){
      if (0 < num_valores_a_leer && num_valores_a_leer <= capacidad_maxima)
         tope = num_valores_a_leer;
   }
   
   void ResetRestricciones(){
      SecuenciaCaracteres cualquiera;
      
      capacidad_maxima = cualquiera.Capacidad();
      tope = capacidad_maxima;
      terminador = '\n';
   }
   
   SecuenciaCaracteres Lee(){   
      SecuenciaCaracteres a_leer;
      char caracter;      
      bool parar_lectura;
      bool es_terminador;
      int total_leidos = 0;
      
      do{            
         if (FlujoAbierto()){            
            caracter = cin.get();  
            total_leidos++;
            es_terminador = caracter == terminador;
                                  
            if (!es_terminador) 
               a_leer.Aniade(caracter); 
            
            parar_lectura = es_terminador || total_leidos == tope;                           
         }
      }while (!parar_lectura);
      
      return a_leer;
   }
};

