Santiago Ortiz, Diego

using namespace std;    // Se va a utilizar namespace estándar

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
      bool palisimetrica = Utilizados() % 2 == 0;  // Condición necesaria
      SecuenciaCaracteres una_secuencia,
                          otra_secuencia;
      
      int mitad = Utilizados()/2;                  // Posición por la que
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
   //Método adicional
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
   //Explicación por pasos del funcionamiento del algoritmo
   ////////////////////////////////////////////////////////
   
   A partir de mi nombre y mi primer apellido se obtiene la secuencia:
      
      diegosantiago
   
   Para el método Subsecuencia se declara una SecuenciaCaracteres nueva
   y con el método Aniade se van añadiendo los caracteres de
   la secuencia original desde pos_inicio incluida hasta pos_final sin incluir.
   
   Para que una secuencia sea palisimétrica, en primer lugar debe tener un
   número par de elementos, para que al dividirla por la mitad, ambas partes
   tengan el mismo número de elementos. Esta condición no se da para nuestra
   secuencia (tiene 13 caracteres), por lo que ya no podría ser palisimétrica,
   no entraría en el bucle y la función devolvería FALSE.
   En cualquier caso, supongamos que mi apellido tiene una letra menos
   con el fin de clarificar el funcionamiento completo de mi algoritmo.
   Así, se tendría una nueva secuencia:
      
      diegosantiag
      
   Mediante el método Subsecencia, se divide la secuencia en dos para obtener
   dos secuencias nuevas, una desde la posición 0
   hasta la mitad (= 12/2 = 6) - 1, y la segunda desde la mitad hasta el final.
   Se tendría pues:
      
      diegos
      antiag
      
   Ahora, se comprobaría que el número de apariciones de cada elemento de
   la primera mitad es igual al número de apariciones de ese elemento
   en la segunda mitad. Podría hacerse a la inversa pero el resultado sería el
   mismo ya que ésta es una condición de reciprocidad.
   Para calcular el número de apariciones se ha declarado e implementado
   el método Apariciones.
   
   En este caso, se empezaría comprobando que el carácter 'd' de la primera 
   mitad, aparece 1 vez (apariciones de ese carácter en la primera mitad),
   en la segunda mitad. Esta condición es falsa por lo que no sería necesario
   seguir comprobando el resto de caracteres y sus apariciones.
   El método devolvería FALSE y se concluiría que la secuencia:
      
      diegosantiag
      
   NO es PALISIMÉTRICA.
   

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
   //Explicación por pasos del funcionamiento del algoritmo
   ////////////////////////////////////////////////////////
   
   Dado nuestro tablero:
   
   2 0 8
   8 9 4
   4 4 3
   
   En primer lugar, se obtiene la diagonal inversa.
   Para ello, se inicializan unos índices de posición a la posición del primer
   elemento de la diagonal, es decir, el de la esquina superior derecha (8).
   Para obtener el siguiente elemento se aumenta y decrementa el valor de
   los indices de las filas y las columnas, respectivamente (9), de manera que
   nos estaremos moviendo de forma diagonal. Y así sucesivamente (4) hasta que,
   o bien se lleuge a la última fila o a la primera columna.
   En este caso se ha optado por que la condición de salida sea llegar
   a la última fila.
   Tenemos así, la diagonal inversa en forma de SecuenciaEnterosLong:(9 8 4).
   
   En segundo lugar, se comprueba si es HETEROGÉNEO y HETEROGÉNEO completo.
   Para ello, se ha declarado e implementado un método que te devuelve la suma
   de cada una de las columnas en forma de SecuenciaEnterosLong. Esto se hace
   recorriendo los valores de cada columna con un bucle y acumulándolos en una
   variable que, una vez recorrida toda la columna se asignará a la secuencia
   y volverá a ser inicializada a 0.
   Así, recorremos y sumamos la primera columna (14), la segunda (13) y
   la tercera (15), y obtenemos la secuencia 'suma de columnas':(14 13 15).
   
   Para saber si es HETEROGÉNEO, se comprueba para cada suma si existe
   otra suma en una posición más adelante en la secuencia con el mismo valor.
   Así, se comprueba si 14 es distinto de 13 o de 15, y posteriormente,
   si 13 es distinto a 15. En este caso son todos distintos por lo que se
   cumple la condición de HETEROGÉNEO y devolvemos TRUE.
   
   Por otro lado, para saber si es HETEROGÉNEO COMPLETO, se necesita saber,
   en primer lugar, si es HETEROGÉNEO por lo que inicializamos el booleano
   que devolveremos después con el método anterior.
   Si es HETEROGÉNEO (así es en este caso), se entra en el bucle y
   se comprueba que se cumple la condición de HETEROGÉNEO COMPLETO.
   En nuestro caso particular, se comprueba si 13 es justamente 14 + 1,
   lo cual es totalmente falso, por lo que se finaliza el bucle
   y devolvemos el valor FALSE.
   
   Nuestro tablero es HETEROGÉNEO pero no HETEROGÉNEO COMPLETO.
