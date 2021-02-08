// Diego Santiago Ortiz

// Tabla rectangular de enteros (sin implementaci�n)

#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Secuencia de enteros

class SecuenciaEnteros{
private:
   static const int TAMANIO = 2e6; // 2e6 es un real (dos millones) -> casting autom�tico;
                                   // Herramientas -> Opciones del Compilador ->
                                   // Compilador -> A�adir las siguientes opciones
                                   // -Wl,--stack,26000000
   long v[TAMANIO];
   int utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      long intercambia;

      intercambia = v[pos_izda];
      v[pos_izda] = v[pos_dcha];
      v[pos_dcha] = intercambia;
   }
public:
   SecuenciaEnteros()
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
   
   void Aniade(long nuevo){
      if (utilizados < TAMANIO){
         v[utilizados] = nuevo;
         utilizados++;
      }
   }
   
   void Modifica(int posicion, long nuevo){
      if (posicion >= 0 && posicion < utilizados)
         v[posicion] = nuevo;
   }

   long Elemento(int indice){
      return v[indice];
   }
   
   string ToString(){
      // Si el n�mero de caracteres en memoria es muy grande,
      // es mucho m�s eficiente reservar memoria previamente
      // y usar push_back

      string cadena;

      cadena.reserve(utilizados);

      for (int i=0; i < utilizados; i++){
         cadena.append(to_string(v[i]));
         cadena.append(" ");
         //cadena = cadena + to_string(v[i])  <- Evitarlo. Muy ineficiente para tama�os grandes;
      }
      
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, long buscado){
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
   
   int PrimeraOcurrencia (long buscado){
      return PrimeraOcurrenciaEntre (0, utilizados - 1, buscado);
   }
   

   /////////////////////////////////////////////////////////////
   // B�squedas
   
   // Precond: 0 <= izda <= dcha < utilizados
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      long minimo;

      minimo = v[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (v[i] < minimo){
            minimo = v[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, utilizados - 1);
   }
   
   int BusquedaBinaria (long buscado){
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
   
   // Inserta un valor en la posici�n especificada
   void Inserta(int pos_insercion, long valor_nuevo){
      if (utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= utilizados){

         for (int i = utilizados ; i > pos_insercion ; i--)
            v[i] = v[i-1];

         v[pos_insercion] = valor_nuevo;
         utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posici�n
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < utilizados){
         int tope = utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            v[i] = v[i+1];

         utilizados--;
      }
   }
   
   
   /////////////////////////////////////////////////////////////
   // Algoritmos de ordenaci�n
   
   void Ordena_por_Seleccion(){
      int pos_min;

      for (int izda = 0 ; izda < utilizados ; izda++){
         pos_min = PosicionMinimoEntre(izda, utilizados - 1);
         IntercambiaComponentes_en_Posiciones(izda, pos_min);
      }
   }
   
   void Ordena_por_Insercion(){
      int izda, i;
      long a_desplazar;

      for (izda=1; izda < utilizados; izda++){
         a_desplazar = v[izda];

         for (i=izda; i > 0 && a_desplazar < v[i-1]; i--)
            v[i] = v[i-1];

         v[i] = a_desplazar;
      }
   }
   
   void Ordena_por_Burbuja(){
      int izda, i;

      for (izda = 0; izda < utilizados; izda++)
        for (i = utilizados-1 ; i > izda ; i--)
          if (v[i] < v[i-1])
             IntercambiaComponentes_en_Posiciones(i, i-1);
   }
   
   void Ordena_por_BurbujaMejorado(){
      int izda, i;
      bool cambio;

      cambio= true;

      for (izda=0; izda < utilizados && cambio; izda++){
        cambio=false;

        for (i=utilizados-1 ; i>izda ; i--)
          if (v[i] < v[i-1]){
             IntercambiaComponentes_en_Posiciones(i, i-1);
             cambio=true;
          }
      }
   }
   
   void AniadeVarios(SecuenciaEnteros nuevos){
      int totales_a_aniadir = nuevos.Utilizados();
      
      for (int i = 0; i < totales_a_aniadir; i++)
         Aniade(nuevos.Elemento(i)); // Es importante entender
   }


   // Busca una sub-secuencia
   // Las posiciones deben estar en orden y consecutivas
   int PosicionContiene (SecuenciaEnteros a_buscar){
      int  inicio;
      int  ultima_componente;
      bool encontrado;
      int  posicion_contiene;
      bool va_coincidiendo;
      int  utilizados_a_buscar;

      /*
      Tenemos una secuencia "grande" de tama�o G y otra peque�a de tama�o P

      Recorrer la secuencia "grande" fijando una posici�n inicial inicio
      La �ltima posici�n inicial a probar ser� G-P
         A partir de inicio recorrer en paralelo las
         dos secuencias "grande" y "peque�a"
         Si no coinciden todas las componentes, hay que
         empezar de nuevo a partir de inicio + 1.
      */

      utilizados_a_buscar = a_buscar.Utilizados();

      if (utilizados_a_buscar > 0){
         ultima_componente = utilizados - utilizados_a_buscar;
         encontrado = false;

         for (inicio = 0; inicio <= ultima_componente && !encontrado; inicio++){
            va_coincidiendo = true;

            for (int i = 0; i < utilizados_a_buscar && va_coincidiendo; i++)
               va_coincidiendo = v[inicio + i] == a_buscar.Elemento(i);

            if (va_coincidiendo){
               posicion_contiene = inicio;
               encontrado = true;
            }
         }
      }
      else
         encontrado = false;

      if (encontrado)
         return posicion_contiene;
      else
         return -1;
   /*
   Bater�a de pruebas:
      Los dos vectores vac�os.
      Alguno de ellos vac�o.
      Los dos vectores iguales.  atti / atti
      Que no se encuentre.   atti / tj
      Que se encuentre al principio.  atti / at
      Que se encuentre justo al final. atti / ti
      Que haya un emparejamiento parcial pero no total,
      aunque luego s� se encuentre.  atttij / ti
   */
   }
};

///////////////////////////////////////////////////////////////////////
// Clases y Structs Diego Santiago Ortiz
///////////////////////////////////////////////////////////////////////

struct Posicion{
   int fila = -1;
   int columna = -1;
};

class TablaRectangularEnteros{
private:
   static const int TAMANIO = 1000;
   int tabla[TAMANIO][TAMANIO];
   int filas;
   int columnas;
public:
   TablaRectangularEnteros(int num_filas, int num_columnas){
      filas = num_filas;
      columnas = num_columnas;
   }
   void AniadeFila(SecuenciaEnteros nueva_fila){
      if (Columnas() == nueva_fila.Utilizados()){
         for (int i=0 ; i < Columnas() ; i++ )
            tabla[Filas()][i] = nueva_fila.Elemento(i);     
           
         filas++;    
      }   
   }
   
   int Filas(){
      return filas;    
   }

   int Columnas(){
      return columnas;
   }
   
   int Elemento(int fila, int columna){
      return tabla[fila][columna];
   }
   
   void Modifica(int fila, int columna, int sustituto){
      tabla[fila][columna] = sustituto;
   }
   
   Posicion PosEntero(int entero_a_buscar){
      bool encontrado = false;
      Posicion posicion;
      
      for (int i=0 ; i < Filas() && !encontrado ; i++){
         for (int j=0 ; j < Columnas() && !encontrado ; j++){
            if (entero_a_buscar == Elemento(i,j)){
               encontrado = true;
               posicion.fila = i;
               posicion.columna = j;  
            }
         }  
      }
      
      return posicion;
   }
   
   SecuenciaEnteros GetFila(int num_fila){
      SecuenciaEnteros fila;
      for (int i=0 ; i < Columnas() ; i++)
         fila.Aniade(tabla[num_fila][i]);
         
      return fila;
   }
   
   bool EsIgual(TablaRectangularEnteros otra_tabla){
      bool es_igual = (Filas() == otra_tabla.Filas()) && (Columnas() == otra_tabla.Columnas());

      for (int i=0 ; i < Filas() && es_igual ; i++){
         cout << "Entraaaaaaaaaaaa";
         for (int j=0 ; j < Columnas() && es_igual ; j++)
            if (Elemento(i,j) != otra_tabla.Elemento(i,j))
               es_igual = false;  
      }
      
      return es_igual;
   }
   
   TablaRectangularEnteros Traspuesta(){
      TablaRectangularEnteros traspuesta(Columnas(),Filas());
      
      for (int i=0 ; i < traspuesta.Filas() ; i++){
         for (int j=0 ; j < traspuesta.Columnas() ; j++)
            traspuesta.Modifica(i,j,Elemento(j,i));
      }
      
      return traspuesta;
   }
   
   bool EsSimetrica(){
      return EsIgual(Traspuesta());
   }
   
   TablaRectangularEnteros Multiplica(TablaRectangularEnteros otra_tabla){
      TablaRectangularEnteros multiplicada(Filas(),otra_tabla.Columnas());
      int elemento;
      
      if (Columnas() == otra_tabla.Filas()){
         for (int i=0 ; i < multiplicada.Filas() ; i++){
            for (int j=0 ; j < multiplicada.Columnas() ; j++){
               elemento = 0;
               for (int k=0 ; k < Columnas() ; k++)
                  elemento += (Elemento(i,k) * otra_tabla.Elemento(k,j));
               
               multiplicada.Modifica(i,j,elemento);
            }     
         }
      }
      
      return multiplicada;
   }
   
   void Imprime(){
      for (int i=0 ; i < Filas() ; i++){
         cout << "\n";
         for (int j=0 ; j < Columnas() ; j++){
            cout << Elemento(i,j) << " ";
         }
      }
      
   }
   
};

int main(){
   int filas,
       columnas,
       num;
   Posicion posicion;
   
   cin >> filas >> columnas;
   
   TablaRectangularEnteros tabla(filas,columnas);

   for (int i=0 ; i < tabla.Filas() ; i++){
      for (int j=0 ; j < tabla.Columnas() ; j++){
         cin >> num;
         tabla.Modifica(i,j,num);
      }
   }
   
   cin >> num;
   posicion = tabla.PosEntero(num);
   
   cout << "\nEl " << num << " se encuentra en la fila " << posicion.fila << " y en la columna " << posicion.columna;
   
   TablaRectangularEnteros traspuesta = tabla.Traspuesta();
   
   cout << "\n\nTabla traspuesta: ";
   traspuesta.Imprime();
   
   TablaRectangularEnteros multiplicacion = tabla.Multiplica(traspuesta);
   
   cout << "\n\nTabla original * traspuesta: ";
   multiplicacion.Imprime();
   
   cout << "\n\nEsta tabla ";
   if (! tabla.EsSimetrica())
      cout << "no ";
   cout << "es sim�trica";
         
}
