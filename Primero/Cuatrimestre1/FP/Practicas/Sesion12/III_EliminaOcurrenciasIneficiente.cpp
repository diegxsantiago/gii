//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Elimina ocurrencias de una componente en un vector -versión ineficiente-

/*
Se desea eliminar todas las apariciones de un determinado carácter a_borrar , dentro de un 
vector de caracteres. Por ejemplo, después de eliminar el carácter 'o' del vector
{'S','o','Y',' ','y','o'} , éste debe quedarse con {'S','Y',' ','y'} .
Un primer algoritmo para resolver este problema sería el siguiente (en ejercicios pos-
teriores se verán métodos más eficientes):

   Recorrer todas las componentes del vector
      Si la componente es igual al carácter a_borrar, eliminarla
      (desplazando hacia la izda las componentes que hay a su dcha)

A la hora de implementar el anterior código, debe prestar especial atención cuando
hay dos caracteres a borrar consecutivos.
Construya un programa que lea caracteres hasta que se introduzca # lo que formará
el vector. A continuación lea el carácter a eliminar. El programa imprimirá el vector
resultante después de eliminar todas las apariciones de dicho carácter.

Ejemplo de entrada: maaaovaiala#a
-- Salida correcta: movil
Ejemplo de entrada: aaaaa#a
-- Salida correcta: vector vacío
*/


#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR = '#';
   const int MAX_NUM_CARACTERES = 100;
   char v[MAX_NUM_CARACTERES];
   char a_borrar;
   char caracter;
   int i, utilizados;
 
   // Lectura
   
   caracter = cin.get();
   i = 0;
   
   while (caracter != TERMINADOR){
      v[i] = caracter;
      caracter = cin.get();
      i++;
   }
   
   utilizados = i;
   
   a_borrar = cin.get();

   /*
   Algoritmo:
      Recorrer todas las componentes que hay en el vector
         Si la componente actual es igual a a_borrar
            Elimirla 
         en otro caso
            Pasar a la siguiente componente
   */
   /*
      Para eliminar una componente hay que trasladar
      a la izquierda todas las componentes que hay a su derecha
      (ver los apuntes de la asignatura)
   */
   
   /*
      La siguiente implementación de este algoritmo es incorrecta porque
      cuando ha borrado una ocurrencia, no debe avanzar i.
      Al estar dentro de un for, siempre se ejecuta i++,
      por lo que si hay dos caracteres a_borrar contiguos,
      no borra el segundo.

         for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] == a_borrar)
               Elimina la posición i 
               (desplazando a la izda las componentes que están a su dcha)
         }
   */
   
   /*
   Solución: ¿Decrementamos i dentro del bucle?

         for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] == a_borrar)
               Elimina la posición i;
            i--;              :-(
         }

   NO!! Jamás modificaremos la variable contadora de un for dentro del bucle.
   Usamos un bucle while, incrementado i dentro de un else:
   */
   
   /*
   i = 0;

   while (i < utilizados){                            // utilizados va cambiando
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La última asignación  ultimo <- ? no es necesaria
            v[j] = v[j+1];

         utilizados --;
      }
      else
         i++;
   }
   */
   
   /*
   Observe la forma de trabajar del algoritmo:
   Si el valor de i pasa la condición del while,
   tenemos la garantía de que está en el rango correcto.
   Por lo tanto podemos proceder a trabajar con dicha componente
   y vuelve a subir para comprobar si el nuevo valor de i 
   está en el rango correcto.
   
   Podríamos haber optado por otro planteamiento:
      
      Mientras i sea correcto
         Mientras v[i] sea igual a a_borrar
            Elimina la posición i
   
   El algoritmo sería:
   
      while (i < utilizados){
         while (v[i] == a_borrar)
            Elimina la posición i
         
         i++;
      }
   
   Pero se presenta un problema.
   En el segundo while no controlamos que el índice i sea correcto.
   Por tanto, si los últimos caracteres del vector son
   iguales a a_borrar, entrará en un bucle sin fin.
   Para que funcionase correctamente tendríamos que haber puesto lo siguiente:
      
      while (i < utilizados){
         while (i < utilizados && v[i] == a_borrar)
            Elimina la posición i
         
         i++;
      }
      
   
   En definitiva:
   
   
      ==================================================================
      Mucho cuidado cuando tengamos bucles anidados que involucren
      un mismo contador -i-      
      Habrá que comprobar en ambos bucles que esté en el rango correcto.
      ==================================================================



   En cualquier caso, la solución no queda ya tan elegante al repetir la
   expresión i < utilizados
   
   Consejo:
      Intentar fomentar bucles del tipo 
      
      while (condición sobre i)
         if (otra condición)
            procesar
         actualizar i

      en vez de:
      
      while (condición sobre i)
         while (otra condición sobre i)
            procesar
         actualizar i
   
   Observe que se indica "fomentar"
   En ningún caso se dice que todos los bucles tendrán que ser así.
   */
   
   /*
   Para finalizar, veamos otro recorrido para eliminar correctamente
   las ocurrencias de a_borrar y resolver el problema que se presentaba
   cuando había varias ocurrencias consecutivas.
   Podríamos haber realizado el bucle desde el final hasta el principio.
   Sigue siendo igual de ineficiente pero elimina correctamente los caracteres
   y no nos tenemos que preocupar de que se queden componentes "colgadas"
   sin eliminar.
   
      for (int i = utilizados - 1; i >= 0; i--){
         if (v[i] == a_borrar)
            Elimina la posición i
      }
   */

   /////////////////////////////////////////////////////////////////////

   // En definitiva, las dos soluciones aceptadas son:
   
   /*
   
   // Solución 1.
   
   i = 0;

   while (i < utilizados){                            // utilizados va cambiando
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La última asignación  ultimo <- ? no es necesaria
            v[j] = v[j+1];

         utilizados --;
      }
      else
         i++;
   }
   */
   
   /*
   // Solución 2
   
   for (int i = utilizados - 1; i >= 0; i--){
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La última asignación  ultimo <- ? no es necesaria
            v[j] = v[j+1];

         utilizados --;
      }
   }
   */    
      
   cout << "<";
   
   for (int i = 0; i < utilizados; i++)
      cout << v[i] ;
      
   cout << ">";
   
}
