// Comprobar si dos secuencias de caracteres riman de forma asonante y con grado k

#include <string>
#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 500;  
   char v[TAMANIO];
   int util;
   
   bool EsCorrectaPosicion(int indice){
      return 0 <= indice && indice < util;
   }
public:
   SecuenciaCaracteres()
      :util(0) {
   }
   
   int Utilizados(){
      return util;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      util = 0;
   }
   
   void Aniade(char nuevo){
      if (util < TAMANIO){
         v[util] = nuevo;
         util++;
      }
   }
   
   void Modifica(int posicion, char nuevo){
      if (EsCorrectaPosicion(posicion))      
         v[posicion] = nuevo;
   }

   char Elemento(int indice){
      return v[indice];
   }
   
   string ToString(){
      // Si el número de caracteres en memoria es muy grande,
      // es mucho más eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(util);

      for (int i=0; i < util; i++)
         cadena.push_back(v[i]);
         //cadena = cadena + v[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

      return cadena;
   }
   
   ////////////////////////////////////
   // MÉTODOS AUXILIARES PARA EL EXAMEN
   ////////////////////////////////////
   
   bool EsVocal(int pos){   
      return Elemento(pos) == 'a'
             || Elemento(pos) == 'e'
             || Elemento(pos) == 'i'
             || Elemento(pos) == 'o'
             || Elemento(pos) == 'u'
             || Elemento(pos) == 'A'
             || Elemento(pos) == 'E'
             || Elemento(pos) == 'I'
             || Elemento(pos) == 'O'
             || Elemento(pos) == 'U';
   }

   SecuenciaCaracteres Invierte(){
      SecuenciaCaracteres invertida;
      
      for (int i=Utilizados()-1 ; i >= 0 ; i--)
         invertida.Aniade(Elemento(i));
         
      return invertida;
   }

   SecuenciaCaracteres Trunca(int elementos){
      SecuenciaCaracteres truncada;
      
      for (int i=0 ; i < elementos ; i++)
         truncada.Aniade(Elemento(i));
         
      return truncada;
   }
   
   bool SonIguales(SecuenciaCaracteres a_comparar){
      bool iguales = Utilizados() == a_comparar.Utilizados();
      
      for (int i=0 ; i < Utilizados() && iguales ; i++)
         iguales = Elemento(i) == a_comparar.Elemento(i);
         
      return iguales;
   }
   
   SecuenciaCaracteres ExtraeVocales(){
      SecuenciaCaracteres vocales;
      
      for (int i=0 ; i < Utilizados() ; i++){
         if (EsVocal(i))
            vocales.Aniade(Elemento(i));  
      }
      
      return vocales;
   }
   
   //////////////////////////////////
   // MÉTODO RIMA ASONANTE DEL EXAMEN
   //////////////////////////////////
   
   bool RimaAsonante(SecuenciaCaracteres a_comprobar, int grado_k){
      return ExtraeVocales().Invierte().Trunca(grado_k).SonIguales(a_comprobar.ExtraeVocales().Invierte().Trunca(grado_k));
   }
};


/*
LectorSecuencias:
   Permite la lectura de objetos de la clase SecuenciaCaracteres.
   Condiciones de parada que se pueden establecer (conjuntamente):
      - Hasta llegar a un terminador
      - Hasta completar un número fijo de caracteres
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

int main(){
   SecuenciaCaracteres una_secuencia,
                       otra_secuencia;
   LectorSecuenciaCaracteres lector;
   int k;
   bool son_iguales;
   
   lector.SetTerminador('@');
   una_secuencia = lector.Lee();
   otra_secuencia = lector.Lee();
   
   cin >> k;
   
   son_iguales = una_secuencia.RimaAsonante(otra_secuencia,k);
   
   if (son_iguales)
      cout << "Riman";
   else
      cout << "No riman";
}

