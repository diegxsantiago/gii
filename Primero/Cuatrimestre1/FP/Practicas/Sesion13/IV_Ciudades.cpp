//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Mapa de distancias entre ciudades

#include <iostream>
#include <cmath>
using namespace std;


// -----------------------------------------------------------------------
class MapaDistancias{
private:
    static const int NUM_MAX_CIUDADES = 50;
    static const int DISTANCIA_NULA = 0;
    double mat_dist[NUM_MAX_CIUDADES][NUM_MAX_CIUDADES];
    int  num_ciudades;

    bool EsCorrectaDistancia(double distancia){
       return distancia > DISTANCIA_NULA;
    }
    
    bool EsCorrectoIndice(int indice){
      return 0 <= indice && indice < num_ciudades;   
    }
    
    bool EsCorrectaPosicion(int origen, int destino){
       return  EsCorrectoIndice(origen) && EsCorrectoIndice(destino);
    }
    
public:
   MapaDistancias (int numero_ciudades)
      : num_ciudades(numero_ciudades)
   {
      for (int i = 0; i < num_ciudades; i++)
         for (int j = 0; j < num_ciudades; j++)
            mat_dist[i][j] = DISTANCIA_NULA;
   }

   int Capacidad(){
      return NUM_MAX_CIUDADES;
   }

   int NumCiudades(){
      return num_ciudades;
   }

   void ModificaDistancia(int una, int otra, double distancia){
      if (EsCorrectaDistancia(distancia) && EsCorrectaPosicion(una, otra)){
         mat_dist[una][otra] = mat_dist[otra][una] = distancia;
      }
   }

   bool EstanConectadas(int una, int otra){
      return mat_dist[una][otra] != DISTANCIA_NULA;
   }

   int NumeroConexionesDirectas(int origen){
      int numero_conexiones = 0;
      
      for (int destino = 0; destino < num_ciudades; destino++)
         if (EstanConectadas(origen, destino))
            numero_conexiones++;

      return numero_conexiones;
   }
   
   int CiudadMejorConectada(){
      int indice_mas_conectada = -1; // Por si no hubiese ninguna conexión
      int max_conexiones = -1;
      int num_conexiones_actual;

      for (int origen = 0; origen < num_ciudades; origen++){
         num_conexiones_actual = NumeroConexionesDirectas(origen);

         if (num_conexiones_actual > max_conexiones)   {
            max_conexiones = num_conexiones_actual;
            indice_mas_conectada = origen;
         }
      }

      return indice_mas_conectada;
   }
   
   /*
   Ampliación:
   
      Desde el main, tengo que saber que -1 es el valor que indica que no existe ninguna ciudad.
      Para que la clase ofrezca dicha información, lo normal es declarar lo siguiente:
      
      static const int CIUDAD_NO_EXISTE = -1;
      
      De forma que en el main, la llamada sería del tipo:
      
      if (mapa.CiudadConMasConexionesDirectas() == mapa.CIUDAD_NO_EXISTE)
         ......
   */

   int MejorEscalaEntre (int origen, int destino){
      double min_distancia;
      int  escala_de_min_distancia;
      long distancia_con_escala;

      escala_de_min_distancia = -1;   // o a CIUDAD_NO_EXISTE = -1  - Ver Ampliación más arriba -
      min_distancia = INFINITY ;
      
      for (int escala = 0; escala < num_ciudades; escala++){
         distancia_con_escala = DistanciaConEscala(origen, escala, destino);
         
         if (distancia_con_escala != DISTANCIA_NULA){               
            if (distancia_con_escala < min_distancia){
               escala_de_min_distancia = escala;
               min_distancia = distancia_con_escala;
            }
         }
      }      
      
      return escala_de_min_distancia;
   }

   double DistanciaConEscala(int origen, int escala, int destino){
      double distancia;

      if (EstanConectadas(origen, escala)
          &&
          EstanConectadas(escala, destino)){

         distancia = mat_dist[origen][escala]
                     +
                     mat_dist[escala][destino];

      }
      else
         distancia = DISTANCIA_NULA;

      return distancia;
   }


   string ToString() {
      string cadena;
      
      for (int i = 0; i < num_ciudades; i++){
         for (int j = 0; j < num_ciudades; j++){
            cadena.append(to_string(mat_dist[i][j]));
            cadena.append("\t");
         }
         cadena.append("\n");
      }
      return cadena;
   }
};


// -----------------------------------------------------------------------
int main (){
   int ciudad_mas_conectada;
   int origen, destino, escala;
   int num_ciudades;
   const int TERMINADOR_CIUDADES = -1;

   cout << "Mapa de distancias"
        << "\n\nIntroduzca los datos en el siguiente orden:"
        << "\na) Número de ciudades"
        << "\nb) Distancias entre ellas en forma de matriz diagonal superior"
        << "\n   Lista de índices de ciudades para las que se quiere ver "
        << "\n   si están todas conectadas entre sí. Terminador: " 
        << TERMINADOR_CIUDADES
        << "\n"
        << "\n   Ciudad de origen y ciudad de destino."
        << "\n\n";

   cin >> num_ciudades;
   
   MapaDistancias mapa(num_ciudades);

   for (int i = 0; i < num_ciudades - 1; i++){         
      for (int j = i+1; j < num_ciudades; j++){
         double distancia;
         
         cin >> distancia;
         mapa.ModificaDistancia(i, j, distancia); 
      }
   }
   
   cin >> origen >> destino;
         
   cout << "\n" << mapa.ToString() << "\n";
   
   ///////////////////////////////////////////////////////////////////////
   // Ciudad con más conexiones directas
   
   ciudad_mas_conectada = mapa.CiudadMejorConectada();
   
   cout << "La ciudad con más conexiones directas es la ciudad: " 
        << ciudad_mas_conectada;
   
   escala = mapa.MejorEscalaEntre(origen, destino);
   
   if (escala == -1)
      cout << "No existe escala";
   else
      cout << "\nLa mejor escala entre " << origen << " y "
           << destino << " es " << escala;                    
}
/*
Entrada:

   5    
   50  100   0    150     
       70    0    0      
             60   80      
                  90
   0 4

Salida:

   La ciudad con más conexiones directas es la ciudad: 2
   La mejor escala entre 0 y 4 es 2
*/
