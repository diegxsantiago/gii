//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Elimina ocurrencias de una componente en un vector -versi�n ineficiente-

/*
Se desea eliminar todas las apariciones de un determinado car�cter a_borrar , dentro de un 
vector de caracteres. Por ejemplo, despu�s de eliminar el car�cter 'o' del vector
{'S','o','Y',' ','y','o'} , �ste debe quedarse con {'S','Y',' ','y'} .
Un primer algoritmo para resolver este problema ser�a el siguiente (en ejercicios pos-
teriores se ver�n m�todos m�s eficientes):

   Recorrer todas las componentes del vector
      Si la componente es igual al car�cter a_borrar, eliminarla
      (desplazando hacia la izda las componentes que hay a su dcha)

A la hora de implementar el anterior c�digo, debe prestar especial atenci�n cuando
hay dos caracteres a borrar consecutivos.
Construya un programa que lea caracteres hasta que se introduzca # lo que formar�
el vector. A continuaci�n lea el car�cter a eliminar. El programa imprimir� el vector
resultante despu�s de eliminar todas las apariciones de dicho car�cter.

Ejemplo de entrada: maaaovaiala#a
-- Salida correcta: movil
Ejemplo de entrada: aaaaa#a
-- Salida correcta: vector vac�o
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
      La siguiente implementaci�n de este algoritmo es incorrecta porque
      cuando ha borrado una ocurrencia, no debe avanzar i.
      Al estar dentro de un for, siempre se ejecuta i++,
      por lo que si hay dos caracteres a_borrar contiguos,
      no borra el segundo.

         for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] == a_borrar)
               Elimina la posici�n i 
               (desplazando a la izda las componentes que est�n a su dcha)
         }
   */
   
   /*
   Soluci�n: �Decrementamos i dentro del bucle?

         for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] == a_borrar)
               Elimina la posici�n i;
            i--;              :-(
         }

   NO!! Jam�s modificaremos la variable contadora de un for dentro del bucle.
   Usamos un bucle while, incrementado i dentro de un else:
   */
   
   /*
   i = 0;

   while (i < utilizados){                            // utilizados va cambiando
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La �ltima asignaci�n  ultimo <- ? no es necesaria
            v[j] = v[j+1];

         utilizados --;
      }
      else
         i++;
   }
   */
   
   /*
   Observe la forma de trabajar del algoritmo:
   Si el valor de i pasa la condici�n del while,
   tenemos la garant�a de que est� en el rango correcto.
   Por lo tanto podemos proceder a trabajar con dicha componente
   y vuelve a subir para comprobar si el nuevo valor de i 
   est� en el rango correcto.
   
   Podr�amos haber optado por otro planteamiento:
      
      Mientras i sea correcto
         Mientras v[i] sea igual a a_borrar
            Elimina la posici�n i
   
   El algoritmo ser�a:
   
      while (i < utilizados){
         while (v[i] == a_borrar)
            Elimina la posici�n i
         
         i++;
      }
   
   Pero se presenta un problema.
   En el segundo while no controlamos que el �ndice i sea correcto.
   Por tanto, si los �ltimos caracteres del vector son
   iguales a a_borrar, entrar� en un bucle sin fin.
   Para que funcionase correctamente tendr�amos que haber puesto lo siguiente:
      
      while (i < utilizados){
         while (i < utilizados && v[i] == a_borrar)
            Elimina la posici�n i
         
         i++;
      }
      
   
   En definitiva:
   
   
      ==================================================================
      Mucho cuidado cuando tengamos bucles anidados que involucren
      un mismo contador -i-      
      Habr� que comprobar en ambos bucles que est� en el rango correcto.
      ==================================================================



   En cualquier caso, la soluci�n no queda ya tan elegante al repetir la
   expresi�n i < utilizados
   
   Consejo:
      Intentar fomentar bucles del tipo 
      
      while (condici�n sobre i)
         if (otra condici�n)
            procesar
         actualizar i

      en vez de:
      
      while (condici�n sobre i)
         while (otra condici�n sobre i)
            procesar
         actualizar i
   
   Observe que se indica "fomentar"
   En ning�n caso se dice que todos los bucles tendr�n que ser as�.
   */
   
   /*
   Para finalizar, veamos otro recorrido para eliminar correctamente
   las ocurrencias de a_borrar y resolver el problema que se presentaba
   cuando hab�a varias ocurrencias consecutivas.
   Podr�amos haber realizado el bucle desde el final hasta el principio.
   Sigue siendo igual de ineficiente pero elimina correctamente los caracteres
   y no nos tenemos que preocupar de que se queden componentes "colgadas"
   sin eliminar.
   
      for (int i = utilizados - 1; i >= 0; i--){
         if (v[i] == a_borrar)
            Elimina la posici�n i
      }
   */

   /////////////////////////////////////////////////////////////////////

   // En definitiva, las dos soluciones aceptadas son:
   
   /*
   
   // Soluci�n 1.
   
   i = 0;

   while (i < utilizados){                            // utilizados va cambiando
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La �ltima asignaci�n  ultimo <- ? no es necesaria
            v[j] = v[j+1];

         utilizados --;
      }
      else
         i++;
   }
   */
   
   /*
   // Soluci�n 2
   
   for (int i = utilizados - 1; i >= 0; i--){
      if (v[i] == a_borrar){
         for (int j = i ; j < utilizados - 1 ; j++)   // La �ltima asignaci�n  ultimo <- ? no es necesaria
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
