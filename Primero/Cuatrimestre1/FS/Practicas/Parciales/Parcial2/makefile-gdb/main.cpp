#include <stdio.h>
#include "funciones.h"

/* programa que genera una secuencia de numeros que es, para cada uno de los 
numeros comprendidos entre los dos dados por teclado, ambos incluidos, la mitad de cada uno.
 Si num1=2 y num2=8,  genera 1,1,2,2,3,3,4 */

int main ()
{
 int serie;
 int num1;
 int num2;
 printf("Primer elemento: ");
 scanf("%d",&num1);  /* leo el primer numero desde el terminal*/
 serie = num1;
 printf("Ultimo elemento: "); /* leo el segundo numero desde el terminal*/
 scanf("%d",&num2); 
 while(num1<num2)
 {
  serie=division(num1,2);
  printf("%d,",serie);
  num1=suma(num1,1);
 }
printf("\nFin de la serie\n");
}
