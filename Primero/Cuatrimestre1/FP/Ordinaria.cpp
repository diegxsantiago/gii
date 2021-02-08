Santiago Ortiz, Diego

using namespace std;    // Se va a utilizar namespace est�ndar

*******************************************************************************
EJERCICIO1

class SecuenciaCaracteres{
public:
   // Incluye desde pos_inicio incluida hasta pos_final sin incluir
   SecuenciaCaracteres Subsecuencia(int pos_inicio, int pos_final){
      SecuenciaCaracteres subsecuencia;
      
      if (pos_inicio >= 0 && pos_final <= Utilizados()){
         for (int i=pos_inicio ; i < pos_final ; i++)
            subsecuencia.Aniade(Elemento(i));   
      }
      
      return subsecuencia;
   }
   
   bool EsPalisimetrica(){
      bool palisimetrica = Utilizados() % 2 == 0;  // Condici�n necesaria
      SecuenciaCaracteres una_secuencia,
                          otra_secuencia;
      
      int mitad = Utilizados()/2;                  // Posici�n por la que
                                                   // dividiremos la secuencia
      
      una_secuencia = Subsecuencia(0,mitad);
      otra_secuencia = Subsecuencia(mitad,Utilizados());
      
      for (int i=0 ; i < una_secuencia.Utilizados() && palisimetrica; i++){
         palisimetrica = una_secuencia.Apariciones(Elemento(i))
                         == otra_secuencia.Apariciones(Elemento(i));
      }
         
      return palisimetrica;
      
   }
   
   //////////////////
   //M�todo adicional
   //////////////////
   
   int Apariciones(char a_buscar){
      int apariciones = 0;
      
      for (int i=0 ; i < Utilizados() ; i++){
         if (Elemento(i) == a_buscar)
            apariciones++;
      }
      
      return apariciones;
   }
   
};
   
   ////////////////////////////////////////////////////////
   //Explicaci�n por pasos del funcionamiento del algoritmo
   ////////////////////////////////////////////////////////
   
   A partir de mi nombre y mi primer apellido se obtiene la secuencia:
      
      diegosantiago
   
   Para el m�todo Subsecuencia se declara una SecuenciaCaracteres nueva
   y con el m�todo Aniade se van a�adiendo los caracteres de
   la secuencia original desde pos_inicio incluida hasta pos_final sin incluir.
   
   Para que una secuencia sea palisim�trica, en primer lugar debe tener un
   n�mero par de elementos, para que al dividirla por la mitad, ambas partes
   tengan el mismo n�mero de elementos. Esta condici�n no se da para nuestra
   secuencia (tiene 13 caracteres), por lo que ya no podr�a ser palisim�trica,
   no entrar�a en el bucle y la funci�n devolver�a FALSE.
   En cualquier caso, supongamos que mi apellido tiene una letra menos
   con el fin de clarificar el funcionamiento completo de mi algoritmo.
   As�, se tendr�a una nueva secuencia:
      
      diegosantiag
      
   Mediante el m�todo Subsecencia, se divide la secuencia en dos para obtener
   dos secuencias nuevas, una desde la posici�n 0
   hasta la mitad (= 12/2 = 6) - 1, y la segunda desde la mitad hasta el final.
   Se tendr�a pues:
      
      diegos
      antiag
      
   Ahora, se comprobar�a que el n�mero de apariciones de cada elemento de
   la primera mitad es igual al n�mero de apariciones de ese elemento
   en la segunda mitad. Podr�a hacerse a la inversa pero el resultado ser�a el
   mismo ya que �sta es una condici�n de reciprocidad.
   Para calcular el n�mero de apariciones se ha declarado e implementado
   el m�todo Apariciones.
   
   En este caso, se empezar�a comprobando que el car�cter 'd' de la primera 
   mitad, aparece 1 vez (apariciones de ese car�cter en la primera mitad),
   en la segunda mitad. Esta condici�n es falsa por lo que no ser�a necesario
   seguir comprobando el resto de caracteres y sus apariciones.
   El m�todo devolver�a FALSE y se concluir�a que la secuencia:
      
      diegosantiag
      
   NO es PALISIM�TRICA.
   

*******************************************************************************
EJERCICIO2

class Tablero{
public:
   SecuenciaEnterosLong DiagonalInversa(){
      SecuenciaEnterosLong diagonal_inversa;
      
      for (int i=0, j=Dimension() - 1 ; i < Dimension() ; i++, j--)
         diagonal_inversa.Aniade(Elemento(i,j));
         
      return diagonal_inversa;
   }
   
   bool Heterogeneo(){
      bool heterogeneo = true;
      SecuenciaEnterosLong suma_columnas;
      suma_columnas = SumaColumnas();
      
      for (int i=0 ; i < suma_columnas.Utilizados() && heterogeneo ; i++){
         for (int j=i+1 ; j < suma_columnas.Utilizados() && heterogeneo ; j++){
            heterogeneo = suma_columnas.Elemento(i)
                          != suma_columnas.Elemento(j);
         }
      }
      
      return heterogeneo;
   }
   
   bool HeterogeneoCompleto(){
      bool heterogeneo_completo = Heterogeneo();
      SecuenciaEnterosLong suma_columnas;
      
      suma_columnas = SumaColumnas();
      
      for (int i=0 ; i < (suma_columnas.Utilizados() - 1)
                     && heterogeneo_completo ; i++){                     
         heterogeneo_completo = (suma_columnas.Elemento(i) + 1)
                                == suma_columnas.Elemento(i+1);
      }
         
      return heterogeneo_completo;
   }
   
   SecuenciaEnterosLong SumaColumnas(){
      SecuenciaEnterosLong suma_columnas;
      long suma_acumulada = 0;
      
      for (int i=0 ; i < Dimension() ; i++){
         
         for (int j=0 ; j < Dimension() ; j++)
            suma_acumulada += Elemento(i,j);
            
         suma_columnas.Aniade(suma_acumulada);
         suma_acumulada = 0;
      }
      
      return suma_columnas;
   }
   
};

   ////////////////////////////////////////////////////////
   //Explicaci�n por pasos del funcionamiento del algoritmo
   ////////////////////////////////////////////////////////
   
   Dado nuestro tablero:
   
   2 0 8
   8 9 4
   4 4 3
   
   En primer lugar, se obtiene la diagonal inversa.
   Para ello, se inicializan unos �ndices de posici�n a la posici�n del primer
   elemento de la diagonal, es decir, el de la esquina superior derecha (8).
   Para obtener el siguiente elemento se aumenta y decrementa el valor de
   los indices de las filas y las columnas, respectivamente (9), de manera que
   nos estaremos moviendo de forma diagonal. Y as� sucesivamente (4) hasta que,
   o bien se lleuge a la �ltima fila o a la primera columna.
   En este caso se ha optado por que la condici�n de salida sea llegar
   a la �ltima fila.
   Tenemos as�, la diagonal inversa en forma de SecuenciaEnterosLong:(9 8 4).
   
   En segundo lugar, se comprueba si es HETEROG�NEO y HETEROG�NEO completo.
   Para ello, se ha declarado e implementado un m�todo que te devuelve la suma
   de cada una de las columnas en forma de SecuenciaEnterosLong. Esto se hace
   recorriendo los valores de cada columna con un bucle y acumul�ndolos en una
   variable que, una vez recorrida toda la columna se asignar� a la secuencia
   y volver� a ser inicializada a 0.
   As�, recorremos y sumamos la primera columna (14), la segunda (13) y
   la tercera (15), y obtenemos la secuencia 'suma de columnas':(14 13 15).
   
   Para saber si es HETEROG�NEO, se comprueba para cada suma si existe
   otra suma en una posici�n m�s adelante en la secuencia con el mismo valor.
   As�, se comprueba si 14 es distinto de 13 o de 15, y posteriormente,
   si 13 es distinto a 15. En este caso son todos distintos por lo que se
   cumple la condici�n de HETEROG�NEO y devolvemos TRUE.
   
   Por otro lado, para saber si es HETEROG�NEO COMPLETO, se necesita saber,
   en primer lugar, si es HETEROG�NEO por lo que inicializamos el booleano
   que devolveremos despu�s con el m�todo anterior.
   Si es HETEROG�NEO (as� es en este caso), se entra en el bucle y
   se comprueba que se cumple la condici�n de HETEROG�NEO COMPLETO.
   En nuestro caso particular, se comprueba si 13 es justamente 14 + 1,
   lo cual es totalmente falso, por lo que se finaliza el bucle
   y devolvemos el valor FALSE.
   
   Nuestro tablero es HETEROG�NEO pero no HETEROG�NEO COMPLETO.
