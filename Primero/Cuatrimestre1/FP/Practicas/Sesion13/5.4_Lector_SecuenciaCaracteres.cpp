// Diego Santiago Ortiz

#include <string>
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

// Secuencia de caracteres

// La clase SecuenciaCaracteres es "atípica" en el sentido de que es una clase
// con muchos métodos. El principio de responsabilidad única nos dice que
// las clases deben tener una única responsabilidad y, por tanto, no suelen tener
// un número elevado de métodos.
// Sin embargo, a veces nos encontramos con este tipo de clases "genéricas"
// En este caso, la responsabilidad es manejar una secuencia de caracteres 
// lo que conlleva la definición de numerosos métodos


class SecuenciaCaracteres{
private:
   static const int TAMANIO = 2e6;  // 2e6 es un real (dos millones) 
                                    // -> casting automático a int
                                    
                                    // Para poder dimensionar con un tamaño
                                    // tan grande, hay que cambiar unos parámetros
                                    // del compilador:
                                    // Herramientas -> Opciones del Compilador ->
                                    // Compilador -> Añadir las siguientes opciones
                                    // -Wl,--stack,26000000
   char v[TAMANIO];
   int utilizados;
   
   void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = v[pos_izda];
      v[pos_izda] = v[pos_dcha];
      v[pos_dcha] = intercambia;
   }
   
   bool EsCorrectaPos(int indice){
      return 0 <= indice && indice < utilizados;
   }
public:
   SecuenciaCaracteres()
      :utilizados(0) {
   }
   
   int Utilizados(){
      return utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      utilizados = 0;
   }
   
   void Aniade(char nuevo){
      if (utilizados < TAMANIO){
         v[utilizados] = nuevo;
         utilizados++;
      }
   }
   
   void Modifica(int posicion, char nuevo){
      if (EsCorrectaPos(posicion))      
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

      cadena.reserve(utilizados);

      for (int i=0; i < utilizados; i++)
         cadena.push_back(v[i]);
         //cadena = cadena + v[i]  <- Evitarlo. Muy ineficiente para tamaños grandes;

      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (v[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre (0, utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   // Precond: 0 <= izda <= dcha < utilizados
   int PosMinimoEntre(int izda, int dcha){
      int pos_minimo = -1;
      char minimo;

      minimo = v[izda];
      pos_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (v[i] < minimo){
            minimo = v[i];
            pos_minimo = i;
         }

      return pos_minimo;
   }
   
   int PosMinimo(){
      return PosMinimoEntre(0, utilizados - 1);
   }
   
   int BusquedaBinaria (char buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (v[centro] == buscado)
            encontrado = true;
         else if (buscado < v[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, char valor_nuevo){
      if (utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= utilizados){

         for (int i = utilizados ; i > pos_insercion ; i--)
            v[i] = v[i-1];

         v[pos_insercion] = valor_nuevo;
         utilizados++;
      }
   }

	/*
   Tipos de borrados:
      - Lógico
         Usar un valor de componente especial y marcar la componente con dicho valor
         Un vector de edades -> valor -1
         Un vector de caracteres alfabéticos -> '@'
         Ventajas: Muy rápido

         Inconvenientes: Cualquier procesado posterior del vector
         debe tratar las componentes marcadas de una forma especial

      - Físico
         Implica desplazar 1 posición a la izquierda, todas las componentes que hay a la derecha de
			la que queremos borrar.

         Tiene justo las ventajas e incovenientes contrarias que el método anterior.

       En esta versión, implementamos el borrado físico.
	*/

   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      /*
      Algoritmo:

		   Recorremos de izquierda a derecha toda las componentes
		   que hay a la derecha de la posición a eliminar
			   Le asignamos a cada componente la que hay a su derecha
      */
      if (posicion >= 0 && posicion < utilizados){
         int tope = utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            v[i] = v[i+1];

         utilizados--;
      }

      // Nota:

      // En vez de usar la asignación
      //    v[i] = v[i+1];
      // también podríamos haber puesto lo siguiente:
      //    Modifica(i, Elemento(i+1));
      // Hemos preferido acceder directamente a las componentes con la notación en corchete
      // para aumentar la eficiencia del método Elimina, ya que si el vector es muy grande
      // tendrá que realizar muchos desplazamientos y, por tanto, muchos accesos al método
      // Elemento. En general, desde dentro de la clase, los métodos de la clase Secuencia
      // accederán directamente a las componentes con la notación corchete

      // Además, cuando entramos en la función Elimina, comprobamos con el condicional
      // que los accesos a los índices son correctos.
      // Si usamos el método Modifica, volveríamos a comprobar lo mismo.

      // Nota:

      // ¿Y si en vez de asignar v[i] = v[i+1];
      // llamamos a IntercambiaComponentesDirectamente(i, i+1) ?
      // La componente se eliminaría pero realizando el doble de asignaciones
      // Obviamente, no es necesario intercambiar las componentes.
      // Únicamente debemos ir asignando v[i] = v[i+1] de izquierda a derecha.
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenación
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < utilizados ; izda++){
         pos_min = PosMinimoEntre(izda, utilizados - 1);
         IntercambiaComponentesDirectamente(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      char a_desplazar;

      for (izda=1; izda < utilizados; izda++){
         a_desplazar = v[izda];

         for (i=izda; i > 0 && a_desplazar < v[i-1]; i--)
            v[i] = v[i-1];

         v[i] = a_desplazar;
      }
   }
   
   void InsertaOrdenadamente(char valor_nuevo){
        int i;

        if (utilizados > TAMANIO){
           for (i=utilizados; i>0 && valor_nuevo < v[i-1]; i--)
                v[i] = v[i-1];

           v[i] = valor_nuevo;
           utilizados++;
        }
   }
   
   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < utilizados; izda++)
        for (i = utilizados-1 ; i > izda ; i--)
          if (v[i] < v[i-1])
             IntercambiaComponentesDirectamente(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < utilizados && cambio; izda++){
        cambio=false;

        for (i=utilizados-1 ; i>izda ; i--)
          if (v[i] < v[i-1]){
             IntercambiaComponentesDirectamente(i, i-1);
             cambio=true;
          }
      }
   }
   
   
   
   
   //////////////////////////////////////////////////////
   // Tema V
   // Métodos que reciben como parámetro o devuelven objetos
   // de la propia clase SecuenciaCaracteres:
   
   
   
   
   void AniadeVarios(SecuenciaCaracteres nuevos){
      int totales_a_aniadir = nuevos.Utilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); 
   }


   SecuenciaCaracteres ToUpper(){
      SecuenciaCaracteres en_mayuscula;
      
      for(int i = 0; i < utilizados; i++)
         en_mayuscula.Aniade(toupper(v[i]));

      return en_mayuscula;
   }

   
   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosContiene ( int izda, int dcha, SecuenciaCaracteres a_buscar) {
      int  inicio;
      int  ultimo;
      bool encontrado;
      int  pos_contiene;
      bool va_coincidiendo;
      int  util_a_buscar;

      /*
      Tenemos una secuencia "grande" de tamaño G y otra pequeña de tamaño P

      Recorrer la secuencia "grande" fijando una posición inicial inicio
      La última posición inicial a probar será G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "pequeña"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      util_a_buscar = a_buscar.Utilizados();

      if (util_a_buscar > 0){
         ultimo = dcha + 1 - util_a_buscar;
         encontrado = false;

         for (inicio = izda; inicio <= ultimo && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < util_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = v[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               pos_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return pos_contiene;
      else
         return -1;
   /*
   Batería de pruebas:
      Los dos vectores vacíos.
      Alguno de ellos vacío.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego sí se encuentre.  atttij / ti
   */
   }
   
   
   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosContiene (SecuenciaCaracteres a_buscar){
      return PosContiene(0, utilizados - 1, a_buscar);
   }
   
   // Esta versión de InsertaSecuencia es ineficiente ya que inserta 
   // los caracteres uno a uno, realizando múltiples desplazamientos.
   // Se incluye como ejemplo de un método que llama a otro.
   void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar){
      int longitud_a_insertar = a_insertar.Utilizados();

      if (longitud_a_insertar + utilizados < TAMANIO){
         for (int i = 0; i < longitud_a_insertar; i++){
            Inserta(pos_insercion, a_insertar.Elemento(i));    // Inserta aumenta automáticamente utilizados
            pos_insercion++;
         }
      }
   }   
};

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

int main(){
   const char TERMINADOR = '#';
   LectorSecuenciaCaracteres lector; 
   SecuenciaCaracteres una_secuencia,
                       otra_secuencia;
   int pos_insertar;
   
   lector.SetTerminador(TERMINADOR);           
   una_secuencia = lector.Lee();
   otra_secuencia = lector.Lee();
   cin >> pos_insertar;
      
   una_secuencia.InsertaSecuencia(pos_insertar,otra_secuencia);

   cout << una_secuencia.ToString();

}
